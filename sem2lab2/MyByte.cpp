#include <iostream>
#include <string.h>
using namespace std;


class Bin {
public:
    unsigned char value : 8;

    void Show() {
        cout << "Двоичное: ";
        for (int i = 7; i >= 0; i--) {
            cout << ((value >> i) & 1);
        }
        cout << endl;
    }
};

class Hex {
public:
    unsigned char value : 8;

    void Show() {
        cout << "Шестнадцатеричное: ";
        cout << hex << (int)value << endl;
    }
};

class Oct {
public:
    unsigned char value : 8;

    void Show() {
        cout << "Восьмеричное: ";
        cout << oct << (int)value << endl;
    }
};

class Dec {
public:
    unsigned char value : 8;

    void Show() {
        cout << "Десятичная: ";
        cout << dec << (int)value << endl;
    }
};


union MyByte {
private:
    Bin bin;
    Hex hex;
    Oct oct;
    Dec dec;
    unsigned char value;
public:
    MyByte(unsigned char value) :value(value) {}


    void ShowAll() {
        dec.Show();
        bin.Show();
        hex.Show();
        oct.Show();

        if (value >= 32 && value <= 126) {
            cout << (char)value << endl;
        }
    }
    void ShowBin() {
        bin.Show();
    }
    void ShowHex() {
        hex.Show();
    }
    void ShowOct() {
        oct.Show();
    }
    void ShowDec() {
        cout << (int)value << endl;
    }
    void ShowSymbol() {
        if (value >= 32 && value <= 126) {
            cout << (char)value << endl;
        }
        else { cout << "----" << endl; }
    }



    void ShowDigit(int base, int index) {
        switch (base) {
        case 2:
            cout << ((bin.value >> (7 - index)) & 1);
            break;
        case 8:
            cout << ((oct.value >> (2 - index)) & 1);
            break;
        case 16:
            cout << ((hex.value >> (3 - index)) & 1);
            break;
        }
    }
    void SetDigit(int base, int index, int digit) {
        switch (base) {
        case 2:
            bin.value = (bin.value & ~(1 << (7 - index))) | (digit << (7 - index));
            break;
        case 8:
            oct.value = (oct.value & ~(1 << (2 - index))) | (digit << (2 - index));
            break;
        case 16:
            int shift = 4 * index;
            int mask = 15 << shift;
            hex.value = (hex.value & ~mask) | (digit << shift);
            break;
        }
        this->value = bin.value; 
    }
};