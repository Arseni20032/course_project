// численное решение задачи коши
#include <iostream>
#include <cmath>
#include <chrono> 

float f(float x, float y) {
    return y / x - log(x) / x; // правая часть ДУ
}

int main() {
    setlocale(LC_ALL, "Russian");

    float a, b, h, x, y;
    int n;

    std::cout << "Введите начальное значение x (a): ";
    std::cin >> a;
    std::cout << "Введите конечное значение x (b): ";
    std::cin >> b;
    std::cout << "Введите количество шагов (n): ";
    std::cin >> n;

    h = (b - a) / n;

    std::cout << "Введите начальное значение y(a): ";
    std::cin >> y;

    auto start_time = std::chrono::high_resolution_clock::now();

    std::cout << "Численное решение:\n";
    for (int i = 0; i <= n; i++) {
        x = a + i * h;
        y = y + h * f(x, y);
        std::cout << "X = " << x << ", Y = " << y << "\n";
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    std::cout << "Время выполнения: " << duration.count() << " микросекунд\n";

    return 0;
}
