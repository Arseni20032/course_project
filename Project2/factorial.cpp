#include <iostream>
#include <chrono>

// Функция для вычисления факториала
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    int number;

    std::cout << "Введите число для вычисления факториала: ";
    std::cin >> number;

    // Проверка на отрицательные числа
    if (number < 0) {
        std::cout << "Факториал не определен для отрицательных чисел.\n";
    }
    else {
        // Измерение времени выполнения
        auto start = std::chrono::high_resolution_clock::now();

        // Вызов функции для вычисления факториала
        unsigned long long result = factorial(number);

        // Завершение измерения времени выполнения
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

        std::cout << "Факториал числа " << number << " равен " << result << std::endl;
        std::cout << "Время выполнения: " << duration.count() << " микросекунд" << std::endl;
    }

    return 0;
}
