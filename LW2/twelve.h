#pragma once

#include <iostream>
#include <string>

class Twelve 
{

public:

    // конструкторы класса
    Twelve();
    Twelve(const size_t & n);
    Twelve(const std::initializer_list<unsigned char> &t);
    Twelve(const std::string &t);
    Twelve(const Twelve& other);
    Twelve(Twelve&& other) noexcept;

    // деконструктор класса
    virtual ~Twelve() noexcept;

    // методы класса
    int GetSize();
    unsigned char* GetNums();
    int translate_to_10();
    std::string plus(const Twelve& other);
    std::string minus(const Twelve& other);
    Twelve copy();
    std::string bigger(const Twelve& other);
    std::string smaller(const Twelve& other);
    std::string equally(const Twelve& other);

private:

    size_t size;
    unsigned char* nums;
    int to_10;

};