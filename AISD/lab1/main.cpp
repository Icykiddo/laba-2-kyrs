#include <iostream>
#include <complex>
#include <stdexcept>
#include <cmath>
#include <random>

template <typename T>
struct Point
{
	T x;
	T y;
};
template <typename T>
class Broken
{
private:
	Point<T>* data;
	size_t size;
public:
	Broken(size_t count)
	{
		size = count;
		data = new Point<T>[size];
	}
	Broken(const Point<T>& point)
	{
		size = 1;
		data = new Point<T>[size];
		data[0] = point;
	}
	Broken(size_t count, T minVal, T maxVal)
	{
		size = count;
		data = new Point<T>[size];
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<T> dis(minVal, maxVal);
		for (size_t i = 0; i < size; i++)
		{
			data[i].x = dis(gen);
			data[i].y = dis(gen);
		}
	}
	Broken(const Broken<T>& other)
	{
		size = other.size;
		data = new Point<T>[size];
		for (size_t i = 0; i < size; i++)
		{
			data[i] = other.data[i];
		}
	}
	Point<T>& operator[] (size_t index)
	{
		if (index >= size)
		{
			throw std::out_of_range("Index out of range");
		}
		return data[index];
	}
	const Point<T>& operator[] (size_t index) const
	{
		if (index >= size)
		{
			throw std::out_of_range("Index out of range");
		}
		return data[index];
	}
	Broken<T> operator+ (const Broken<T>& coordinates) const
	{
		Broken<T> result(this->size + coordinates.size);
		for (size_t i = 0; i < this->size; i++)
		{
			result.data[i] = this->data[i];
		}
		for (size_t j = 0; j < coordinates.size; j++)
		{
			result.data[this->size + j] = coordinates.data[j];
		}
		return result;
	}
	Broken<T> operator+ (const Point<T>& vertex) const
	{
		Broken<T> result(this->size + 1);
		for (size_t i = 0; i < this->size; i++)
		{
			result.data[i] = this->data[i];
		}
		result.data[this->size] = vertex;
		return result;
 	}
	Broken<T>& operator= (const Broken<T>& old)
	{
		if (this == &old)
		{
			return *this;
		}
		delete[] data;
		size = old.size;
		data = new Point<T>[size];
		for (size_t i = 0; i < size; i++)
		{
			data[i] = old.data[i];
		}
		return *this;
 	}
	double getLength() const
	{
		double total = 0.0;
		for (size_t i = 0; i < size - 1; i++)
		{
			double dx = static_cast<double>(data[i + 1].x - data[i].x);
			double dy = static_cast<double>(data[i + 1].y - data[i].y);
			total += std::sqrt(dx * dx + dy * dy);
		}
		return total;
	}
	size_t getSize() const
	{
		return size;
	}
	~Broken()
	{
		delete[] data;
	}
 };
template <typename T>
Broken<T> operator+ (const Point<T>& top, const Broken<T>& broken)
{
	Broken<T> result(1 + broken.getSize());
	result[0] = top;
	for (size_t i = 0; i < broken.getSize(); i++)
	{
		result[i + 1] = broken[i];
	}
	return result;
}

int main()
{
	int N = 0;
	std::cout << "Enter the number of vertices N: " << std::endl;
	std::cin >> N;
	try
	{
		if (N <= 2)
		{
			throw std::invalid_argument("Error: the number of vertices (N) must be strictly greater than 2.");
		}
		Broken<double> Line(N);
		Point<double> Coor{ 0.0, 4.0 };
		Line[0] = Coor;
		const double PI = std::acos(-1.0);
		double AngleStep = 2.0 * PI / N;
		for (size_t i = 1; i < N; i++)
		{
			double CurrentAngle = AngleStep * i;
			Point<double> Newpoint;
			Newpoint.x = Coor.x * std::cos(CurrentAngle) - Coor.y * std::sin(CurrentAngle);
			Newpoint.y = Coor.x * std::sin(CurrentAngle) + Coor.y * std::cos(CurrentAngle);
			Line[i] = Newpoint;
		}
		std::cout << "Polygon generated successfully from " << Line.getSize() << " points." << std::endl;
		std::cout << "Coordinates of the vertices:" << std::endl;
		for (size_t i = 0; i < Line.getSize(); ++i) 
		{
			std::cout << "Vertex " << i + 1 << ": ("
				<< Line[i].x << ", " << Line[i].y << ")" << std::endl;
		}
		std::cout << "Length of the polygonal chain: " << Line.getLength() << std::endl;
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << "Invalid input: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
