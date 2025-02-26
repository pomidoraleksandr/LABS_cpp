#include <iostream>
#include <chrono>
int fsum(int N, int num){
    int *numbers{new int[N]{0}}, k = 0, r = N-1;
    for(int i = 0; i<N; i++){
        if(numbers[k]+numbers[r]> num){
            r = r - 1;
        }
        if (numbers[k]+numbers[r] < num){
            k = k + 1;
        }
        if (numbers[k]+numbers[r] == num && (numbers[k] != numbers[r])){

            return numbers[k], numbers[r];
        }
        


    }
    return -1;
}
int main(){
    int N, key;
    std::cin>>N >> key;
    auto begin = std::chrono::steady_clock::now();
    for (unsigned cnt = 100000; cnt != 0; --cnt)
        fsum(N, key);
    auto end=std::chrono::steady_clock::now();
    auto time_span =std::chrono::duration_cast<std::chrono::milliseconds>(end-begin);

    std::cout<<"\n\n";
    std::cout<<time_span.count()<<std::endl;

    

    return 0;

}