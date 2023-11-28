// ��������� ������� ������ ����
#include <iostream>
#include <cmath>
#include <chrono> 

float f(float x, float y) {
    return y / x - log(x) / x; // ������ ����� ��
}

int main() {
    setlocale(LC_ALL, "Russian");

    float a, b, h, x, y;
    int n;

    std::cout << "������� ��������� �������� x (a): ";
    std::cin >> a;
    std::cout << "������� �������� �������� x (b): ";
    std::cin >> b;
    std::cout << "������� ���������� ����� (n): ";
    std::cin >> n;

    h = (b - a) / n;

    std::cout << "������� ��������� �������� y(a): ";
    std::cin >> y;

    auto start_time = std::chrono::high_resolution_clock::now();

    std::cout << "��������� �������:\n";
    for (int i = 0; i <= n; i++) {
        x = a + i * h;
        y = y + h * f(x, y);
        std::cout << "X = " << x << ", Y = " << y << "\n";
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    std::cout << "����� ����������: " << duration.count() << " �����������\n";

    return 0;
}
