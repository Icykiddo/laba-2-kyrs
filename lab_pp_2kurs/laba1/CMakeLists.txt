cmake_minimum_required(VERSION 4.1)

project("laba1" CXX)

# Создаем исполняемый файл сразу из main.cpp
add_executable("${PROJECT_NAME}" main.cpp)

# Оставляем поддержку стандарта C++23, если нужно
target_compile_features("${PROJECT_NAME}" PUBLIC cxx_std_23)