import matplotlib.pyplot as plt
import re
from collections import defaultdict

# Ваши исходные данные
data_text = """
Test 1: Matrix 200x200, treads 1, Lead time 0.0155938seconds
Test 2: Matrix 400x400, treads 1, Lead time 0.128071seconds
Test 3: Matrix 800x800, treads 1, Lead time 0.981306seconds
Test 4: Matrix 1200x1200, treads 1, Lead time 3.35806seconds
Test 5: Matrix 1600x1600, treads 1, Lead time 8.02234seconds

Test 1: Matrix 200x200, treads 2, Lead time 0.0154602seconds
Test 2: Matrix 400x400, treads 2, Lead time 0.138539seconds
Test 3: Matrix 800x800, treads 2, Lead time 1.00898seconds
Test 4: Matrix 1200x1200, treads 2, Lead time 3.31967seconds
Test 5: Matrix 1600x1600, treads 2, Lead time 7.95575seconds

Test 1: Matrix 200x200, treads 4, Lead time 0.0156163seconds
Test 2: Matrix 400x400, treads 4, Lead time 0.148697seconds
Test 3: Matrix 800x800, treads 4, Lead time 0.998552seconds
Test 4: Matrix 1200x1200, treads 4, Lead time 3.39516seconds
Test 5: Matrix 1600x1600, treads 4, Lead time 7.96815seconds

Test 1: Matrix 200x200, treads 8, Lead time 0.0169954seconds
Test 2: Matrix 400x400, treads 8, Lead time 0.151706seconds
Test 3: Matrix 800x800, treads 8, Lead time 0.98992seconds
Test 4: Matrix 1200x1200, treads 8, Lead time 3.35763seconds
Test 5: Matrix 1600x1600, treads 8, Lead time 8.12524seconds
"""

# Словарь для группировки данных по количеству потоков
threads_data = defaultdict(lambda: {'sizes': [], 'times': []})

# Регулярное выражение для поиска чисел в строках
pattern = r"Matrix (\d+)x\d+,\s*treads (\d+),\s*Lead time ([0-9.]+)seconds"

# Парсим текст
for line in data_text.strip().split('\n'):
    if not line.strip():
        continue
    match = re.search(pattern, line)
    if match:
        n = int(match.group(1))
        threads = int(match.group(2))
        time = float(match.group(3))
        
        threads_data[threads]['sizes'].append(n)
        threads_data[threads]['times'].append(time)

# Настраиваем полотно графика
plt.figure(figsize=(10, 6))

# Цвета для разных потоков
colors = {1: '#1f77b4', 2: '#ff7f0e', 4: '#2ca02c', 8: '#d62728'}

# Рисуем линии для каждого потока
for threads in sorted(threads_data.keys()):
    sizes = threads_data[threads]['sizes']
    times = threads_data[threads]['times']
    
    plt.plot(sizes, times, marker='o', linewidth=2, 
             color=colors.get(threads, 'black'), 
             label=f'{threads} поток(ов)')

# Оформление графика
plt.title('Сравнение времени перемножения матриц от числа потоков', fontsize=14, pad=15)
plt.xlabel('Размер матрицы (N)', fontsize=12)
plt.ylabel('Время выполнения (секунды)', fontsize=12)
plt.grid(True, linestyle='--', alpha=0.7)
plt.legend(title="OpenMP Threads", fontsize=11, title_fontsize=12)

# Вывод
plt.tight_layout()
plt.show()