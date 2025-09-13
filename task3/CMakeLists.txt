cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

project(task3   Project LANGUAGES CXX)

# Сообщение для логирования. Выведет путь к исходникам.
message(STATUS "Source dir: ${CMAKE_CURRENT_SOURCE_DIR}")

# Директория, куда будут сложены исполняемые файлы после сборки.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# Указываем, где искать заголовочные файлы для #include "..." и #include <...>
# ${CMAKE_CURRENT_SOURCE_DIR} - путь к директории, где находится текущий CMakeLists.txt
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Создаем исполняемый файл с именем "mymath" и перечисляем ВСЕ .cpp файлы, которые нужно скомпилировать и слинковать.
add_executable(mymath
    main.cpp
    src/ans_handler.cpp
    src/my_math.cpp
)