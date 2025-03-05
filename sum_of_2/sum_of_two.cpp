#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
int lsum(int arr[], int N, int num){
    for (int i = 0; i < N; i++){
        for(int j = i + 1;j < N; j++){
            if (arr[i]+arr[j] == num && (arr[i] != arr[j])){
                return arr[i], arr[j];
            }
        }
    }   
    return -1;
}

int* create(int length) {
    int* a = new int[length];
    for (int i = 0; i < length; ++i) {
        a[i] = i; 
    }
    return a;
}


int main(){
    std :: ofstream outFile("long_sum.txt");
    for ( unsigned cnt = 1; cnt != 101 ;  ++cnt ){
        int* arr = create(cnt * 10);
        auto begin = std :: chrono :: steady_clock :: now ( ) ;
        for (unsigned i = 1; i != 1000; ++i) {
           lsum(arr, cnt * 10, -1);
         }
        auto end = std :: chrono :: steady_clock :: now ( ) ;
        auto time_span = std :: chrono :: duration_cast<std:: chrono :: microseconds >(end - begin ) ;
        outFile << cnt*10 << " " <<  time_span . count ( ) << std :: endl ;
        delete [] arr;
    }
    outFile.close();
    return 0;
    }