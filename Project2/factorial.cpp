#include <iostream>
#include <chrono>

// ������� ��� ���������� ����������
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

    std::cout << "������� ����� ��� ���������� ����������: ";
    std::cin >> number;

    // �������� �� ������������� �����
    if (number < 0) {
        std::cout << "��������� �� ��������� ��� ������������� �����.\n";
    }
    else {
        // ��������� ������� ����������
        auto start = std::chrono::high_resolution_clock::now();

        // ����� ������� ��� ���������� ����������
        unsigned long long result = factorial(number);

        // ���������� ��������� ������� ����������
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

        std::cout << "��������� ����� " << number << " ����� " << result << std::endl;
        std::cout << "����� ����������: " << duration.count() << " �����������" << std::endl;
    }

    return 0;
}
