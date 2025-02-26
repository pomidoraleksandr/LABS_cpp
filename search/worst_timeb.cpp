#include <iostream>
#include <chrono>

int b_search(int N, int key){
    int *numbers {new int[N]{0}};

        int l_idx = 0, r_idx = N-1;
        while (l_idx<r_idx){
            int m_idx = (l_idx + r_idx) / 2;
            if (key < numbers[m_idx]){
                r_idx = m_idx;
            }
            else if (numbers[m_idx]< key){
                l_idx = m_idx + 1;
            }
            else return m_idx;
    
        }
        return -1;
    }

int main(){
    int N, key;
    std::cin>>N >> key;
    auto begin = std::chrono::steady_clock::now();
    for (unsigned cnt = 1000; cnt != 0; --cnt)
        b_search(N, key);
    auto end=std::chrono::steady_clock::now();
    auto time_span =std::chrono::duration_cast<std::chrono::milliseconds>(end-begin);

    std::cout<<"\n\n";
    std::cout<<time_span.count()<<std::endl;

    

    return 0;

}