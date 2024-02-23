#pragma once
#include <iostream>

class Bochka {
private:
    double volume;
    double concentration; // концентрация спирта в процентах

public:
    Bochka(double vol, double conc) : volume(vol), concentration(conc) {}

    void Pereliv(Bochka& other) {
        double totalConc = volume * concentration + other.volume * other.concentration;
        double avgConc = totalConc / (volume + other.volume);

        concentration = avgConc;
        other.concentration = avgConc;

        std::cout << "Perelil. Concentration now: " << concentration << "%" << std::endl;
    }

    bool ConcentrationOver50() {
        return concentration > 50.0;
    }
};
