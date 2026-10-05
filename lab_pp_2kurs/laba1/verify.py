import numpy as np
import sys
def verify():
    try:
        print("Чтение исходных файлов...")
        A = np.loadtxt("input1.txt")
        B = np.loadtxt("input2.txt")
        C_cpp = np.loadtxt("output.txt", skiprows=2)
        C_true = A @ B
        if np.allclose(C_true, C_cpp):
            print("\nУСПЕХ: Верификация пройдена!")
        else:
            print("\nОШИБКА: Результаты не совпадают.")
            print("Ожидалось:\n", C_true)
            print("Получено:\n", C_cpp)
    except FileNotFoundError as e:
            print(f"Ошибка: Не найден файл {e.filename}.")
    except Exception as e:
            print(f"Произошла ошибка при чтении: {e}")

if __name__ == "__main__":
    verify()