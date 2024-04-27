#include <iostream>
#include <cstring>
#include "String.h"
class DecimalString : public String {
public:
    //Конструктор без параметров
    DecimalString() : String() {}

    //Конструктор принимающий С-строку
    DecimalString(const char* cstr) {
        bool valid = true;
        for (int i = 0; cstr[i] != '\0'; ++i) {
            if (!(isdigit(cstr[i]) || cstr[i] == '+' || (cstr[i] == '-' && i == 0))) {
                valid = false;
                break;
            }
        }
        if (valid) {
            length = strlen(cstr);
            str = new char[length + 1];
            strcpy(str, cstr);
        }
        else {
            length = 0;
            str = new char[1];
            str[0] = '\0';
        }
    }

    //Конструктор копирования
    DecimalString(const DecimalString& other) : String(other) {}

    //Деструктор
    ~DecimalString() {}

    bool canConvertToInt() const {
        if (length == 0) return false;
        if (length == 1 && (str[0] == '+' || str[0] == '-')) return false;
        for (int i = (str[0] == '+' || str[0] == '-') ? 1 : 0; i < length; ++i) {
            if (!isdigit(str[i])) return false;
        }
        return true;
    }

    DecimalString& operator=(const DecimalString& other) {
        if (this != &other) {
            String::operator=(other);
        }
        return *this;
    }

    DecimalString operator-(const DecimalString& other) const {
        int newLength = length - other.length;
        char* newStr = new char[newLength + 1];
        strcpy(newStr, str);
        strcat(newStr, other.str);
        return DecimalString(newStr);
    }

    bool operator>(const DecimalString& other) const {
        return String::operator>(other);
    }

    bool operator<(const DecimalString& other) const {
        return String::operator<(other);
    }
};