#include <iostream>
#include <chrono>
int lsum(int N, int num){
    int *numbers{new int[N]{0}};
    for (int i = 0; i < N; i++){
        for(int j = 0;j < N; j++){
            if (numbers[i]+numbers[j] == num && (numbers[i] != numbers[j])){
                return numbers[i], numbers[j];
            }
        }
    }   
    return -1;
}
int main(){
    int N, key;
    std::cin>>N >> key;
    auto begin = std::chrono::steady_clock::now();
    for (unsigned cnt = 100000; cnt != 0; --cnt)
        lsum(N, key);
    auto end=std::chrono::steady_clock::now();
    auto time_span =std::chrono::duration_cast<std::chrono::milliseconds>(end-begin);

    std::cout<<"\n\n";
    std::cout<<time_span.count()<<std::endl;

    

    return 0;

}