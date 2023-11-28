#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <locale>

int main() {
    const int M_PI = 3.14159265358979323846;
    setlocale(LC_ALL, "ru");

    auto start = std::chrono::high_resolution_clock::now();

    std::cout << std::setw(15) << "Угол (градусы)" << std::setw(15) << "Синус" << std::setw(15) << "Косинус" << std::setw(15) << "Тангенс\n";

    for (int i = 0; i <= 360; ++i) {
        // Вычисление угла в радианах
        double angle_rad = i * M_PI / 180.0;

        double sin_value = sin(angle_rad);
        double cos_value = cos(angle_rad);
        double tan_value = tan(angle_rad);

        // Вывод значений для каждого градуса в виде строки таблицы
        std::cout << std::setw(15) << i << std::setw(15) << sin_value << std::setw(15) << cos_value << std::setw(15) << tan_value << "\n";
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "\nВремя выполнения: " << duration.count() << " микросекунд" << std::endl;

    return 0;
}
