#pragma once
#include <iostream>

class MyString{
private:
    char* str; //строка-член класса

public:
    // Конструктор по умолчанию
    MyString() : str(nullptr) {
        std::cout << "Default Constructor called" << std::endl;
    }

    // Конструктор с параметром (конструктор инициализации)
    MyString(const char* s) {
        if (s != nullptr) {
            str = new char[strlen(s) + 1];
            strcpy_s(str, strlen(s) + 1, s);
        } else {
            str = nullptr;
        }
     }

    // Конструктор копирования
    MyString(const MyString& other) {
        if (other.str != nullptr) {
            str = new char[strlen(other.str) + 1];
            strcpy_s(str, strlen(other.str) + 1, other.str);
        } else {
            str = nullptr;
        }
        std::cout << "Copy Constructor called" << std::endl;
    }

    // Деструктор
    ~MyString() {
        delete[] str;
    }

    const char* GetString() const {
        return str;
    }

    void SetNewString(const char* newStr) {
        if (str != nullptr) {
            delete[] str;
        }

        if (newStr != nullptr) {
            str = new char[strlen(newStr) + 1];
            strcpy_s(str, strlen(newStr) + 1, newStr);
        }
        else {
            str = nullptr;
        }
    }

};
