#include "my_math.hpp"
#include <cmath> // Для std::fabs

// Вспомогательная функция для вычисления факториала.
// Используем long long чтобы избежать переполнения для бОльших значений n.
long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

AnswerHandler my_sin(double x) {
    double result = 0.0;
    double term;
    int n = 0; // Start at n=0 for the first term (x^(1)/1!)
    const double epsilon = 1e-10; // Точность

    do {
        // Вычисляем степень: 2n+1
        int exponent = 2 * n + 1;
        // Вычисляем член ряда: (-1)^n * x^(2n+1) / (2n+1)!
        term = (n % 2 == 0 ? 1 : -1) * std::pow(x, exponent) / factorial(exponent);
        result += term;
        n++;
    } while (std::fabs(term) >= epsilon); // Продолжаем, пока текущий член больше epsilon

    AnswerHandler ah;
    ah.x = x;
    ah.answer = result;
    return ah;
}