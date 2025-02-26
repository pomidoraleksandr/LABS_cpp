#include <iostream>
#include <random>

int main(){
    int arr[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 11, 12, 10, 13, 14};

    unsigned seed = 1001;
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned> dstr(0,14);

    for (unsigned counter = 100; counter != 0; --counter)
        std::cout<<arr[dstr(rng)]<<'\n';
    std::cout<<std::endl;

    return 0;
}