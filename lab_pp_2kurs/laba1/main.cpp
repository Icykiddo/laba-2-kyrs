#include <iostream>
#include <fstream>
#include <chrono>
#include <omp.h>
struct Matrix
{
	int N;
	double* data;
	Matrix()
	{
		N = 0;
		data = nullptr;
	}
	~Matrix()
	{
		delete[] data;
	}
};
int main()
{
	setlocale(LC_ALL, "RUS");
	Matrix A;
	Matrix B;
	std::ifstream InFile_1(L"C:\\Users\\Артём\\source\\repos\\lab_pp_2kurs\\laba1\\input1.txt");
	if (!InFile_1.is_open())
	{
		std::cerr << "Error: failed to open the first file!" << std::endl;
		return 1;
	}
	if (InFile_1.is_open())
	{
		A.N = 2;
		A.data = new double[A.N * A.N];

		for (int i = 0; i < A.N * A.N; i++)
		{
			InFile_1 >> A.data[i];
		}
		InFile_1.close();
	}
	std::ifstream InFile_2(L"C:\\Users\\Артём\\source\\repos\\lab_pp_2kurs\\laba1\\input2.txt");
	if (!InFile_2.is_open())
	{
		std::cerr << "Error: failed to open the second file!" << std::endl;
		return 1;
	}
	if (InFile_2.is_open())
	{
		B.N = 2;
		B.data = new double[B.N * B.N];

		for (int i = 0; i < B.N * B.N; i++)
		{
			InFile_2 >> B.data[i];
		}
		InFile_2.close();
	}

	Matrix C;
	C.N = 2;
	C.data = new double[C.N * C.N];
	for (int i = 0; i < C.N * C.N; i++)
	{
		C.data[i] = 0.0;
	}
	auto start_time = std::chrono::high_resolution_clock::now();
#pragma omp parallel for
	for (int i = 0; i < C.N; i++)
	{
		for (int j = 0; j < C.N; j++)
		{
			for (int k = 0; k < C.N; k++)
			{
				C.data[i * C.N + j] += A.data[i * A.N + k] * B.data[k * B.N + j];
			}
		}
	}
	auto end_time = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end_time - start_time;
	std::cout << "Lead time: " << duration.count() << "seconds" << std::endl;
	std::ofstream OutFile(L"C:\\Users\\Артём\\source\\repos\\lab_pp_2kurs\\laba1\\output.txt");
	if (OutFile.is_open())
	{
		OutFile << "Volume (N): " << C.N << "\n\n";
		for (int i = 0; i < C.N; i++)
		{
			for (int j = 0; j < C.N; j++)
			{
				OutFile << C.data[i * C.N + j] << "\t";
			}
			OutFile << "\n";
		}
		OutFile.close();
	}
	return 0;
}