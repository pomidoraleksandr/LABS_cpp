#include <iostream>
#include <random>
#include <memory>

class Roll{
public:
    virtual unsigned roll() = 0;
    virtual ~Roll() = default;
};

class Dice : public Roll {
public:
    Dice(unsigned max, unsigned seed) : 
        max(max), dstr(1, max), reng(seed) { }

    unsigned roll() override {
        return dstr(reng);
    }

private:
    unsigned max;
    std::uniform_int_distribution<unsigned> dstr;
    std::default_random_engine reng;
};

class ThreeDicePool : public Roll {
public:
    ThreeDicePool(unsigned max,
                  unsigned seed_1, unsigned seed_2, unsigned seed_3) :
        dice1(std::make_unique<Dice>(max, seed_1)),
        dice2(std::make_unique<Dice>(max, seed_2)),
        dice3(std::make_unique<Dice>(max, seed_3)) { }

    unsigned roll() override {
        return dice1->roll() + dice2->roll() + dice3->roll();
    }

private:
    std::unique_ptr<Dice> dice1;
    std::unique_ptr<Dice> dice2;
    std::unique_ptr<Dice> dice3;
};

double expected_value(Roll &r, unsigned number_of_rolls = 1000) {
    auto accum = 0llu;
    for (unsigned cnt = 0; cnt != number_of_rolls; ++cnt) {
        accum += r.roll();
    }
    return static_cast<double>(accum) / static_cast<double>(number_of_rolls);
}

void calculate() {
    
    Dice singleDice(10, 42); 
    ThreeDicePool threeDice(10, 42, 43, 44); 
    
    unsigned num_rolls = 10000;
    
    double expected_single = expected_value(singleDice, num_rolls);
    double expected_three = expected_value(threeDice, num_rolls);
    
    std::cout << "Числ. мат. ожид. для 1 величины: " 
              << expected_single << std::endl;
    std::cout << "Числ. мат. ожид. для 3 величин: " 
              << expected_three << std::endl;
    
    std::cout << "\nТеор. значения:" << std::endl;
    double theoretical_single = (1.0 + 10.0) / 2.0;
    double theoretical_three = 3.0 * theoretical_single;
    std::cout << "Теор. мат. ожид. для 1 величины: " << theoretical_single << std::endl;
    std::cout << "Теор. мат. ожид. для 3 величин: " << theoretical_three << std::endl;
}

int main() {
    calculate();
    return 0;
}