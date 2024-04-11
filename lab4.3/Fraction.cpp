#include "Fraction.h"

Fraction::Fraction(int size, bool sign) : Array(size), sign(sign) {}
Fraction::Fraction(int size, unsigned char initialValue, bool sign) : Array(size, initialValue), sign(sign) {}

Fraction Fraction::operator+(const Fraction& other) const {
    int newSize = std::min(size, other.size);
    Fraction result(newSize);
    for (int i = 0; i < newSize; ++i) {
        result[i] = digits[i] + other.digits[i];
    }
    return result;
}
