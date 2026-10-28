import matplotlib.pyplot as plt

# Ваши данные
runs = [1, 2, 3]
times = [2e-07, 3e-07, 4e-07]

# Настройка полотна
plt.figure(figsize=(8, 5))

# Построение графика
plt.plot(runs, times, marker='o', linestyle='-', color='#0078D7', linewidth=2, markersize=8)

# Оформление (добавили N=2 в заголовок)
plt.title('Время выполнения \nРазмер матрицы: 2x2', fontsize=14, pad=15)
plt.xlabel('Номер запуска', fontsize=12)
plt.ylabel('Время (секунды)', fontsize=12)

# Настройка оси X, чтобы показывались только целые числа (1, 2, 3)
plt.xticks(runs)

# Включение сетки
plt.grid(True, linestyle='--', alpha=0.7)

# Вывод
plt.tight_layout()
plt.show()