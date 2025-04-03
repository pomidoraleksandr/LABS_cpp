#include <iostream>
#include <chrono>
#include <fstream>

int *hundred_elements(const int element, int *arr, unsigned long long size){
    if (size == 1 or (size % 100 == 0)){
        int *new_arr = new int[size+100];
        for (unsigned long long i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        new_arr[i] = arr[i];
    }
    new_arr[size-1] = element;
    delete[] arr;
    return new_arr;
    };
    arr[size-1] = element;
    return arr;

};

int main()
{
    std::ofstream outFile("second.txt");
    int element = 1;
    int *array = new int[0];
    unsigned long long time = 0;
    array[0] = 0;
    for (unsigned long long size = 1; size != 100000; size++)
    {

        auto begin = std ::chrono ::steady_clock ::now();
        array = hundred_elements (element, array, size);
        auto end = std ::chrono ::steady_clock ::now();
        auto time_span = std ::chrono ::duration_cast<std::chrono ::nanoseconds>(end - begin);
        time = time + time_span.count();
        outFile << size << " " << time << std ::endl;
    }

    return 0;
}