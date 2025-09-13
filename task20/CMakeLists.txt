cmake_minimum_required(VERSION 3.20)

# Создание проекта с указанием языка C
project(TetrisGame LANGUAGES C)

# Установка стандарта C11 (можно изменить на нужную версию)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Создание статической библиотеки из tetris.c и tetris.h
add_library(tetris_lib STATIC
    tetris.c
    tetris.h
)

# Создание исполняемого файла из main.c
add_executable(tetris_app main.c)

# Связывание библиотеки с исполняемым файлом
target_link_libraries(tetris_app PRIVATE tetris_lib)

# Добавление директории с заголовочными файлами для библиотеки
target_include_directories(tetris_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(tetris_app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
