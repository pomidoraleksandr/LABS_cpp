#include <iostream>
#include <chrono>
int l_search(int N, int key){
    int *numbers {new int[N]{0}};

    for (int k = 0; k < N; k++){
        if (numbers[k] == key){
            return k;
        }
    }

    return -1;
}


//void func(int a){
//    if (a > 0){
//        std::cout<<1<<'\r';
//    }
//    else std::cout<<0<<'\r';
//}

int main(){
    int N, key;
    std::cin>>N>> key;
    auto begin = std::chrono::steady_clock::now();
    for (unsigned cnt = 100000; cnt != 0; --cnt)
        l_search(N, key);
    auto end=std::chrono::steady_clock::now();
    auto time_span =std::chrono::duration_cast<std::chrono::milliseconds>(end-begin);

    std::cout<<"\n\n";
    std::cout<<time_span.count()<<std::endl;

    

    return 0;

}