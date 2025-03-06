#include <iostream>
#include <chrono>
#include <fstream>

int b_search(int arr[],int N, int key){

        int l_idx = 0, r_idx = N-1;
        while (l_idx<r_idx){
            int m_idx = l_idx + (r_idx-l_idx) / 2;
            if (key < arr[m_idx]){
                r_idx = m_idx;
            }
            else l_idx = m_idx + 1;
    
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

    std :: ofstream outFile("b_search_max.txt");
    for ( unsigned cnt = 1; cnt != 1001 ;  ++cnt ){
        int* arr = create(cnt * 10000);
        auto begin = std :: chrono :: steady_clock :: now ( ) ;
        for (unsigned i = 1; i != 10000; ++i) {
           b_search(arr, cnt * 10000, -1);
         }
        auto end = std :: chrono :: steady_clock :: now ( ) ;
        auto time_span = std :: chrono :: duration_cast<std:: chrono :: microseconds >(end - begin ) ;
        outFile << cnt*10000 << " " <<  time_span . count ( ) << std :: endl ;
        delete [] arr;
    }
    return 0;
    }