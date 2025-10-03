#ifndef HELP_H
#define HELP_H

#include <iostream>
#include <iomanip>
#include <map>
#include <string>

template<typename T>
double expected_value(T& dice, unsigned number_of_rolls = 1000) {
    auto accum = 0lu;
    for (unsigned cnt = 0; cnt != number_of_rolls; ++cnt)
        accum += dice.roll();
    return static_cast<double>(accum) / static_cast<double>(number_of_rolls);
}


#endif