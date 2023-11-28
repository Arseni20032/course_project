#include <iostream>
#include <cmath>
#include <chrono>

double intensive_computation(double x) {
    double result = 0.0;

    for (int i = 0; i < 1000000; ++i) {
        result += sin(x) * cos(x) + log(x + 1) / sqrt(x + 1);
    }

    return result;
}

int main() {
    setlocale(LC_ALL, "ru");

    const int iterations = 100; 

    auto start_time = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < iterations; ++i) {
        double result = intensive_computation(static_cast<double>(i));

        std::cout << "Итерация " << i << ", результат: " << result << std::endl;
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

    std::cout << "Время выполнения: " << elapsed_time << " микросекунд." << std::endl;

    return 0;
}
