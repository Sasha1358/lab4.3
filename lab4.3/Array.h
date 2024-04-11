// Array.h
#pragma once
#include <iostream>

class Array {
protected:
    static const int MAX_SIZE = 100;
    unsigned char digits[MAX_SIZE];
    int size;
    void rangeCheck(int index) const;
public:
    Array();
    Array(int size, unsigned char initialValue = 0);
    virtual ~Array();
    Array(const Array& other);
    Array& operator=(const Array& other);

    unsigned char& operator[](int index);
    const unsigned char& operator[](int index) const;

    virtual Array operator+(const Array& other) const;

    int getSize() const;
    void setSize(int newSize);

    Array operator-(const Array& other) const;
    Array operator*(const Array& other) const;
    Array operator/(const Array& other) const;
    bool operator==(const Array& other) const;
    bool operator!=(const Array& other) const;
    bool operator<(const Array& other) const;
    bool operator>(const Array& other) const;
    bool operator<=(const Array& other) const;
    bool operator>=(const Array& other) const;
};

