// Fraction.h
#pragma once
#include "Array.h"

class Fraction : public Array {
private:
    bool sign;
public:
    Fraction(int size, bool sign = false);
    Fraction(int size, unsigned char initialValue, bool sign = false);
    Fraction operator+(const Fraction& other) const;
};