Laba 1
Test 1. Lead time: 2e-07seconds
Test 2. Lead time: 3e-07seconds
Test 3. Lead time: 4e-07seconds
Matrix 1: 2 4
          5 8

Matrix 2: 6 9
          1 4

Matrix final: 16 34
              38 77
Matrix dimension(N): 2

C:\Users\Артём\source\repos\lab_pp_2kurs\laba1>py verify.py
Чтение исходных файлов...

УСПЕХ: Верификация пройдена!

Laba 2
Test 1: Matrix 200x200, treads 1, Lead time 0.0300486seconds
Test 2: Matrix 400x400, treads 1, Lead time 0.233533seconds
Test 3: Matrix 800x800, treads 1, Lead time 2.19245seconds
Test 4: Matrix 1200x1200, treads 1, Lead time 7.28294seconds
Test 5: Matrix 1600x1600, treads 1, Lead time 20.5669seconds

Test 1: Matrix 200x200, treads 2, Lead time 0.0306016seconds
Test 2: Matrix 400x400, treads 2, Lead time 0.268778seconds
Test 3: Matrix 800x800, treads 2, Lead time 2.30854seconds
Test 4: Matrix 1200x1200, treads 2, Lead time 7.40885seconds
Test 5: Matrix 1600x1600, treads 2, Lead time 20.4576seconds

Test 1: Matrix 200x200, treads 4, Lead time 0.0321542seconds
Test 2: Matrix 400x400, treads 4, Lead time 0.234482seconds
Test 3: Matrix 800x800, treads 4, Lead time 2.2561seconds
Test 4: Matrix 1200x1200, treads 4, Lead time 7.18047seconds
Test 5: Matrix 1600x1600, treads 4, Lead time 20.1779seconds

Test 1: Matrix 200x200, treads 8, Lead time 0.0322686seconds
Test 2: Matrix 400x400, treads 8, Lead time 0.243538seconds
Test 3: Matrix 800x800, treads 8, Lead time 2.28784seconds
Test 4: Matrix 1200x1200, treads 8, Lead time 7.11543seconds
Test 5: Matrix 1600x1600, treads 8, Lead time 20.2396seconds

2)             Модифицировать программу из л/р №1 для параллельной работы по технологии OpenMP.  Провести серию экспериментов с разным количеством потоков (1, 2, 4, 8 и т.д.), разными размерами матриц (примерно 200, 400, 800, 1200, 1600, 2000), с разным количеством вычислительных ядер при наличии технической возможности (1, 2, 4, 8 и т.д. ), иначе использовать фиксированное существующее количество вычислительных ядер, например 4.
