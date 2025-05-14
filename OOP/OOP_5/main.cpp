#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include <algorithm>

using namespace std;

// Функция для проверки корректности двоичного числа
bool is_valid_binary(const string& binary) {
    return all_of(binary.begin(), binary.end(), [](char c) {
        return c == '0' || c == '1';
        });
}

// Функция перевода из двоичной в десятичную систему
double binary_to_decimal(const string& binary) {
    if (!is_valid_binary(binary)) {
        throw invalid_argument("Invalid binary number: " + binary);
    }

    double decimal = 0;
    size_t point_pos = binary.find('.');

    // Целая часть
    string int_part = (point_pos == string::npos) ? binary : binary.substr(0, point_pos);
    for (int i = 0; i < int_part.size(); ++i) {
        if (int_part[i] == '1') {
            decimal += pow(2, int_part.size() - 1 - i);
        }
    }

    // Дробная часть
    if (point_pos != string::npos) {
        string frac_part = binary.substr(point_pos + 1);
        for (int i = 0; i < frac_part.size(); ++i) {
            if (frac_part[i] == '1') {
                decimal += pow(2, -1 - i);
            }
        }
    }

    return decimal;
}

// Функция перевода из десятичной в семеричную систему
string decimal_to_septenary(double decimal) {
    if (decimal < 0) {
        throw invalid_argument("Negative numbers not supported");
    }

    // Обработка целой части
    int int_part = static_cast<int>(decimal);
    double fractional_part = decimal - int_part;

    string result;

    // Перевод целой части
    if (int_part == 0) {
        result = "0";
    }
    else {
        while (int_part > 0) {
            result = to_string(int_part % 7) + result;
            int_part /= 7;
        }
    }

    // Перевод дробной части (если есть)
    if (fractional_part > 0) {
        result += '.';
        const int max_precision = 10; // Максимальное количество знаков после запятой
        int precision = 0;

        while (fractional_part > 0 && precision < max_precision) {
            fractional_part *= 7;
            int digit = static_cast<int>(fractional_part);
            result += to_string(digit);
            fractional_part -= digit;
            precision++;
        }
    }

    return result;
}

// Основная функция перевода из двоичной в семеричную систему
string binary_to_septenary(const string& binary) {
    try {
        double decimal = binary_to_decimal(binary);
        return decimal_to_septenary(decimal);
    }
    catch (const invalid_argument& e) {
        throw; // Перебрасываем исключение дальше
    }
}

int main() {
    cout << "Binary to Septenary Converter" << endl;
    cout << "Enter a binary number (e.g., 1010.101): ";

    string binary;
    cin >> binary;

    try {
        string septenary = binary_to_septenary(binary);
        cout << "Binary: " << binary << " -> Septenary: " << septenary << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
    catch (...) {
        cout << "Unknown error occurred" << endl;
    }

    // Примеры работы
    cout << "\nExamples:" << endl;
    try {
        cout << "101 -> " << binary_to_septenary("101") << endl;       // 5 -> 5
        cout << "1010 -> " << binary_to_septenary("1010") << endl;    // 10 -> 13
        cout << "0.1 -> " << binary_to_septenary("0.1") << endl;      // 0.5 -> 0.333...
        cout << "101.01 -> " << binary_to_septenary("101.01") << endl; // 5.25 -> 5.161616...
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}