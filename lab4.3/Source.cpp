#include <iostream>
#include "Hex.h"
#include "Fraction.h"

std::istream& operator>>(std::istream& input, Array& arr) {
    for (int i = 0; i < arr.getSize(); ++i) {
        unsigned char value;
        input >> value;
        arr[i] = value;
    }
    return input;
}

int main() {
    int size;

    std::cout << "Enter size of arrays: ";
    std::cin >> size;

    Array* arrayPtr1 = new Hex(size);
    Array* arrayPtr2 = new Fraction(size);

    std::cout << "Enter elements for Hex array: ";
    std::cin >> *arrayPtr1;

    std::cout << "Enter elements for Fraction array: ";
    std::cin >> *arrayPtr2;

    std::cout << "Array 1 type: Hex" << std::endl;
    std::cout << "Array 2 type: Fraction" << std::endl;

    Array sum = *arrayPtr1 + *arrayPtr2;
    std::cout << "Sum of array 1 and array 2: ";
    for (int i = 0; i < sum.getSize(); ++i) {
        std::cout << static_cast<int>(sum[i]) << " ";
    }
    std::cout << std::endl;

    Array difference = *arrayPtr1 - *arrayPtr2;
    std::cout << "Difference of array 1 and array 2: ";
    for (int i = 0; i < difference.getSize(); ++i) {
        std::cout << static_cast<int>(difference[i]) << " ";
    }
    std::cout << std::endl;

    Array product = *arrayPtr1 * *arrayPtr2;
    std::cout << "Product of array 1 and array 2: ";
    for (int i = 0; i < product.getSize(); ++i) {
        std::cout << static_cast<int>(product[i]) << " ";
    }
    std::cout << std::endl;

    try {
        Array quotient = *arrayPtr1 / *arrayPtr2;
        std::cout << "Quotient of array 1 and array 2: ";
        for (int i = 0; i < quotient.getSize(); ++i) {
            std::cout << static_cast<int>(quotient[i]) << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Exception occurred: " << e.what() << std::endl;
    }

    std::cout << "Comparison result (array 1 == array 2): " << (*arrayPtr1 == *arrayPtr2) << std::endl;
    std::cout << "Comparison result (array 1 != array 2): " << (*arrayPtr1 != *arrayPtr2) << std::endl;
    std::cout << "Comparison result (array 1 < array 2): " << (*arrayPtr1 < *arrayPtr2) << std::endl;
    std::cout << "Comparison result (array 1 > array 2): " << (*arrayPtr1 > *arrayPtr2) << std::endl;
    std::cout << "Comparison result (array 1 <= array 2): " << (*arrayPtr1 <= *arrayPtr2) << std::endl;
    std::cout << "Comparison result (array 1 >= array 2): " << (*arrayPtr1 >= *arrayPtr2) << std::endl;

    delete arrayPtr1;
    delete arrayPtr2;

    return 0;
}
