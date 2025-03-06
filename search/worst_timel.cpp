#include <iostream>
#include <chrono>
#include <fstream>
int l_search(int arr[], int N, int key){

    for (int k = 0; k < N; k++){
        if (arr[k] == key){
            return k;
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

    std :: ofstream outFile("l_search_max.txt");
    for ( unsigned cnt = 1; cnt != 1001 ;  ++cnt ){
        int* arr = create(cnt * 10000);
        auto begin = std :: chrono :: steady_clock :: now ( ) ;
        for (unsigned i = 1; i != 10000; ++i) {
           l_search(arr, cnt * 10000, -1);
         }
        auto end = std :: chrono :: steady_clock :: now ( ) ;
        auto time_span = std :: chrono :: duration_cast<std:: chrono :: microseconds >(end - begin ) ;
        outFile << cnt*10000 << " " <<  time_span . count ( ) << std :: endl ;
        delete [] arr;
    }
    return 0;
    }