#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <locale>

int main() {
    const int M_PI = 3.14159265358979323846;
    setlocale(LC_ALL, "ru");

    auto start = std::chrono::high_resolution_clock::now();

    std::cout << std::setw(15) << "���� (�������)" << std::setw(15) << "�����" << std::setw(15) << "�������" << std::setw(15) << "�������\n";

    for (int i = 0; i <= 360; ++i) {
        // ���������� ���� � ��������
        double angle_rad = i * M_PI / 180.0;

        double sin_value = sin(angle_rad);
        double cos_value = cos(angle_rad);
        double tan_value = tan(angle_rad);

        // ����� �������� ��� ������� ������� � ���� ������ �������
        std::cout << std::setw(15) << i << std::setw(15) << sin_value << std::setw(15) << cos_value << std::setw(15) << tan_value << "\n";
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "\n����� ����������: " << duration.count() << " �����������" << std::endl;

    return 0;
}
