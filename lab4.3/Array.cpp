#include "Array.h"
#include <stdexcept>

Array::Array() : size(0) {
    for (int i = 0; i < MAX_SIZE; ++i) {
        digits[i] = 0;
    }
}

Array::Array(int size, unsigned char initialValue) {
    if (size < 0 || size > MAX_SIZE) {
        throw std::invalid_argument("Invalid size. Size must be between 0 and MAX_SIZE.");
    }
    for (int i = 0; i < size; ++i) {
        digits[i] = initialValue;
    }
    this->size = size;
}

Array::~Array() {}

Array::Array(const Array& other) : size(other.size) {
    for (int i = 0; i < size; ++i) {
        digits[i] = other.digits[i];
    }
}

Array& Array::operator=(const Array& other) {
    if (this == &other) {
        return *this;
    }
    size = other.size;
    for (int i = 0; i < size; ++i) {
        digits[i] = other.digits[i];
    }
    return *this;
}

unsigned char& Array::operator[](int index) {
    rangeCheck(index);
    return digits[index];
}

const unsigned char& Array::operator[](int index) const {
    rangeCheck(index);
    return digits[index];
}

int Array::getSize() const {
    return size;
}

void Array::setSize(int newSize) {
    if (newSize < 0 || newSize > MAX_SIZE) {
        throw std::invalid_argument("Invalid size. Size must be between 0 and MAX_SIZE.");
    }
    size = newSize;
}

void Array::rangeCheck(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds.");
    }
}

Array Array::operator+(const Array& other) const {
    int newSize = std::min(size, other.size);
    Array result(newSize);
    for (int i = 0; i < newSize; ++i) {
        result[i] = digits[i] + other.digits[i];
    }
    return result;
}
Array Array::operator-(const Array& other) const {
    int newSize = std::min(size, other.size);
    Array result(newSize);
    for (int i = 0; i < newSize; ++i) {
        result[i] = digits[i] - other.digits[i];
    }
    return result;
}

Array Array::operator*(const Array& other) const {
    int newSize = std::min(size, other.size);
    Array result(newSize);
    for (int i = 0; i < newSize; ++i) {
        result[i] = digits[i] * other.digits[i];
    }
    return result;
}

Array Array::operator/(const Array& other) const {
    int newSize = std::min(size, other.size);
    Array result(newSize);
    for (int i = 0; i < newSize; ++i) {
        if (other.digits[i] != 0) {
            result[i] = digits[i] / other.digits[i];
        }
        else {
            throw std::runtime_error("Division by zero.");
        }
    }
    return result;
}

bool Array::operator==(const Array& other) const {
    if (size != other.size) {
        return false;
    }
    for (int i = 0; i < size; ++i) {
        if (digits[i] != other.digits[i]) {
            return false;
        }
    }
    return true;
}

bool Array::operator!=(const Array& other) const {
    return !(*this == other);
}

bool Array::operator<(const Array& other) const {
    int minSize = std::min(size, other.size);
    for (int i = 0; i < minSize; ++i) {
        if (digits[i] < other.digits[i]) {
            return true;
        }
        else if (digits[i] > other.digits[i]) {
            return false;
        }
    }
    return size < other.size;
}

bool Array::operator>(const Array& other) const {
    return other < *this;
}

bool Array::operator<=(const Array& other) const {
    return !(other < *this);
}

bool Array::operator>=(const Array& other) const {
    return !(*this < other);
}
