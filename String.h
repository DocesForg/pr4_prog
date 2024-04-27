#include <iostream>
#include <cstring>

class String {
protected:
    //Указатель на Char
    char* str;
    //Длина строки
    int length;

public:
    //Конструктор без параметров
    String() : str(nullptr), length(0) {}
    //Конструктор принимающий С-строку
    String(const char* cstr) {
        length = strlen(cstr);
        str = new char[length + 1];
        strcpy(str, cstr);
    }

    //Конструктор принимающий символ
    String(char ch) {
        length = 1;
        str = new char[2];
        str[0] = ch;
        str[1] = '\0';
    }

    //Конструктор копирования
    String(const String& other) : length(other.length) {
        str = new char[length + 1];
        strcpy(str, other.str);
    }

    //Длина строки
    int getLength() const {
        return length;
    }

    //Очистка строки
    void clear() {
        delete[] str;
        str = nullptr;
        length = 0;
    }

    //Деструктор
    virtual ~String() {
        delete[] str;
    }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    String operator-(const String& other) const {
        int newLength = length - other.length;
        char* newStr = new char[newLength + 1];
        strcpy(newStr, str);
        strcat(newStr, other.str);
        return String(newStr);
    }

    bool operator>(const String& other) const {
        return strcmp(str, other.str) > 0;
    }

    bool operator<(const String& other) const {
        return strcmp(str, other.str) < 0;
    }
};