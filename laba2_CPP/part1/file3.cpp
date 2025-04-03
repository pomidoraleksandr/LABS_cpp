#include <iostream>
#include <chrono>
#include <fstream>

int* double_mem(const int element, int* arr, unsigned long long size, unsigned long long capacity) {
    if (size == capacity) {
        unsigned long long new_capacity =  capacity * 2;
        int* new_arr = new int[new_capacity];
        
        for (unsigned long long i = 0; i < size; i++) {
            new_arr[i] = arr[i];
        }
        
        new_arr[size] = element;
        
        capacity = new_capacity;
        delete[] arr;
        return new_arr;
    }
    
    arr[size] = element;
    return arr;
}

int main()
{
    std::ofstream outFile("third.txt");
    int element = 1;
    int *array = new int[1];
    unsigned long long time = 0;
    array[0] = 0;
    unsigned long long amount = 1;
    for (unsigned long long size = 2; size != 100000; size++)
    {
        auto begin = std ::chrono ::steady_clock ::now();
        array = double_mem (element, array, size, amount);
        auto end = std ::chrono ::steady_clock ::now();
        auto time_span = std ::chrono ::duration_cast<std::chrono ::nanoseconds>(end - begin);
        time = time + time_span.count();
        outFile << size << " " << time << std ::endl;
    }

    return 0;
}