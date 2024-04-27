#include <iostream>
#include <cstring>

class String {
protected:
    //��������� �� Char
    char* str;
    //����� ������
    int length;

public:
    //����������� ��� ����������
    String() : str(nullptr), length(0) {}
    //����������� ����������� �-������
    String(const char* cstr) {
        length = strlen(cstr);
        str = new char[length + 1];
        strcpy(str, cstr);
    }

    //����������� ����������� ������
    String(char ch) {
        length = 1;
        str = new char[2];
        str[0] = ch;
        str[1] = '\0';
    }

    //����������� �����������
    String(const String& other) : length(other.length) {
        str = new char[length + 1];
        strcpy(str, other.str);
    }

    //����� ������
    int getLength() const {
        return length;
    }

    //������� ������
    void clear() {
        delete[] str;
        str = nullptr;
        length = 0;
    }

    //����������
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