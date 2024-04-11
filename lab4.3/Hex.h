// Hex.h
#pragma once
#include "Array.h"

class Hex : public Array {
public:
    Hex(int size);
    Hex(int size, unsigned char initialValue);
    Hex operator+(const Hex& other) const;
};