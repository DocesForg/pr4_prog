#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
#include "DecimalString.h"

int main() {
    setlocale(LC_ALL, "Rus");
    int choice;
    std::cout << "Меню:" << std::endl;
    std::cout << "1) Проверить, можно ли представить строку как целое число" << std::endl;
    std::cout << "2) Получить длину строки" << std::endl;
    std::cout << "3) Сравнить два числа (больше/меньше)" << std::endl;
    std::cout << "4) Вычесть две строки (если можно преобразовать в int)" << std::endl;
    std::cout << "Введите ваш выбор: ";
    std::cin >> choice;

    switch (choice) {
    case 1: {
        char input[100];
        std::cout << "Введите строку: ";
        std::cin >> input;
        DecimalString decString(input);
        std::cout << "Можно представить как int: " << (decString.canConvertToInt() ? "true" : "false") << std::endl;
        break;
    }
    case 2: {
        char input[100];
        std::cout << "Введите строку: ";
        std::cin >> input;
        String lString(input);
        std::cout << "Длина строки: " << lString.getLength() << std::endl;
        break;
    }
    case 3: {
        char input1[100], input2[100];
        std::cout << "Введите первое число: ";
        std::cin >> input1;
        std::cout << "Введите второе число: ";
        std::cin >> input2;
        DecimalString decString1(input1);
        DecimalString decString2(input2);
        if (decString1 > decString2) {
            std::cout << "Первое число больше" << std::endl;
        }
        else if (decString1 < decString2) {
            std::cout << "Второе число больше" << std::endl;
        }
        else {
            std::cout << "Числа равны" << std::endl;
        }
        break;
    }
    case 4: {
        char input1[100], input2[100];
        std::cout << "Введите первое число: ";
        std::cin >> input1;
        std::cout << "Введите второе число: ";
        std::cin >> input2;
        DecimalString decString1(input1);
        DecimalString decString2(input2);
        if (decString1.canConvertToInt() && decString2.canConvertToInt()) {
            int num1 = atoi(input1);
            int num2 = atoi(input2);
            int result = num1 - num2;
            std::cout << "Результат вычитания: " << result << std::endl;
        }
        else {
            std::cout << "Строки нельзя преобразовать в целые числа" << std::endl;
        }
        break;
    }
    default:
        std::cout << "Неверный выбор" << std::endl;
    }

    return 0;
}
