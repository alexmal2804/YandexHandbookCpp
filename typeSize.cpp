#include <iostream>
#include <limits>

int main()
{
    std::cout << "char minimum value: " << std::numeric_limits<char>::min() << "\n";
    std::cout << "char maximum value: " << std::numeric_limits<char>::max() << "\n";
    std::cout << "int minimum value: " << std::numeric_limits<int>::min() << "\n";
    std::cout << "int maximum value: " << std::numeric_limits<int>::max() << "\n";
    std::cout << "long minimum value: " << std::numeric_limits<long long>::min() << "\n";
    std::cout << "long maximum value: " << std::numeric_limits<long long>::max() << "\n";
    std::cout << "unsigned int minimum value: " << std::numeric_limits<unsigned int>::min() << "\n";
    std::cout << "unsigned int maximum value: " << std::numeric_limits<unsigned int>::max() << "\n";
    std::cout << "unsigned long long maximum value: " << std::numeric_limits<unsigned long long>::max() << "\n";
    std::cout << "float minimum value: " << std::numeric_limits<float>::min() << "\n";
    std::cout << "float maximum value: " << std::numeric_limits<float>::max() << "\n";
    std::cout << "double minimum value: " << std::numeric_limits<double>::min() << "\n";
    std::cout << "double maximum value: " << std::numeric_limits<double>::max() << "\n";
    std::cout << "\n";

    std::cout << "char: " << sizeof(char) << "\n";
    std::cout << "bool: " << sizeof(bool) << "\n";
    std::cout << "short int: " << sizeof(short int) << "\n";
    std::cout << "int: " << sizeof(int) << "\n";
    std::cout << "long int: " << sizeof(long int) << "\n";
    std::cout << "long long int: " << sizeof(long long) << "\n";
    std::cout << "double: " << sizeof(double) << "\n";
    std::cout << "float: " << sizeof(float) << "\n";
    std::cout << "long double: " << sizeof(long double) << "\n";
    std::cout << "\n";

    unsigned int a = 123456; // на 64-битной платформе sizeof(a) == 4
    // Произведение a * a не помещается в 4 байта, так как оно больше 2^32
    std::cout << a * a * a << "\n";
    std::cout << "\n";

    unsigned int x = 0;     // на 64-битной платформе sizeof(x) == 4
    unsigned int y = x - 1; // 4294967295, то есть 2**32 - 1
    unsigned int z = y + 1; // 0
    std::cout << x << " " << y << " " << z << "\n";
    std::cout << "\n";
}