#include "Hex.h"

Hex::Hex(int size) : Array(size) {}
Hex::Hex(int size, unsigned char initialValue) : Array(size, initialValue) {}

Hex Hex::operator+(const Hex& other) const {
    int newSize = std::min(size, other.size);
    Hex result(newSize);
    for (int i = 0; i < newSize; ++i) {
        result[i] = digits[i] + other.digits[i];
    }
    return result;
}