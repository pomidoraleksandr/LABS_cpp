#include <iostream>
#include <chrono>
#include <fstream>

int *creating_symbol(const int element, int *arr, unsigned long long size)
{
    int *new_arr = new int[size];
    for (unsigned long long i = 0; i < size; i++)
    {
        new_arr[i] = arr[i];
    }
    new_arr[size - 1] = element;
    delete[] arr;
    return new_arr;
};

int main()
{
    std::ofstream outFile("first.txt");
    int element = 1;
    int *array = new int[0];
    unsigned long long time = 0;
    array[0] = 0;
    for (unsigned long long size = 1; size != 100000; size++)
    {

        auto begin = std ::chrono ::steady_clock ::now();
        array = creating_symbol (element, array, size);
        auto end = std ::chrono ::steady_clock ::now();
        auto time_span = std ::chrono ::duration_cast<std::chrono ::nanoseconds>(end - begin);
        time = time + time_span.count();
        outFile << size << " " << time << std ::endl;
    }

    return 0;
}