#include <iostream>
#include "my_math.hpp"

int main() {
    double input_value;
    std::cout << "Enter a value to calculate sin(x): ";
    std::cin >> input_value;

    AnswerHandler result = my_sin(input_value);

    std::cout << "my_sin(" << result.x << ") = " << result.answer << std::endl;

    return 0;
}