#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
int fsum(int arr[], int N, int num){
    int  k = 0, r = N-1;
    for(int i = 0; i<N; i++){
        if(arr[k]+arr[r]> num){
            r = r - 1;
        }
        if (arr[k]+arr[r] < num){
            k = k + 1;
        }
        if (arr[k]+arr[r] == num && (arr[k] != arr[r])){

            return arr[k], arr[r];
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
    unsigned seed = 1001;
    std::default_random_engine rng(seed);
    std :: ofstream outFile("fast_sum.txt");
    for ( unsigned cnt = 1; cnt != 1001 ;  ++cnt ){
        int* arr = create(cnt * 1000);
        auto begin = std :: chrono :: steady_clock :: now ( ) ;
        for (unsigned i = 1; i != 1000; ++i) {
            std::uniform_int_distribution<unsigned> distr(0, cnt*1000);
           fsum(arr, cnt * 1000, distr(rng));
         }
        auto end = std :: chrono :: steady_clock :: now ( ) ;
        auto time_span = std :: chrono :: duration_cast<std:: chrono :: microseconds >(end - begin ) ;
        outFile << cnt*1000 << " " <<  time_span . count ( ) << std :: endl ;
        delete [] arr;
    }
    outFile.close();
    return 0;
    }