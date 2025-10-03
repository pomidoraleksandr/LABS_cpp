#include <iostream>
#include <iomanip>
#include "Dice.h"
#include "ThreeDicePool.h"
#include "help.h"

void task1() {
    std::cout << "Рефакторинг" << std::endl;

    Dice d50(50, 42);
    ThreeDicePool threeD20(20, 42, 42, 42);

    std::cout << "Матожидание Dice: "
        << expected_value(d50, 10000) << std::endl;
    std::cout << "теор мат ожид: "  << std::endl;

    std::cout << "мат ожид ThreeDicePool: "
        << expected_value(threeD20, 10000) << std::endl;
    std::cout << "теор мат ожид: "  << std::endl;
    std::cout << std::endl;
}


int main() {

    task1();

    return 0;
}