#include <iostream>
#include <string>
#include <cmath>
#include "twelve.h"

Twelve::Twelve()
{   
    size = 1; 
    nums = new unsigned char [1];
    nums[0] = '0';
}

Twelve::Twelve(const size_t & n)
{
    size = n;
    nums = new unsigned char [size];

    for (size_t q = 0; q < size ; q++){
        nums[q] = 0;
    }

}

Twelve::Twelve(const std::initializer_list<unsigned char> &t)
{
    size = t.size();
    nums = new unsigned char [size];
    size_t q = size - 1;

    for (unsigned char num: t){
        if (!((num >= 'A' && num <= 'B') || (num >= '0' && num <= '9')))
            throw std::invalid_argument("!!!!!!! input number does not satisfy the conditions !!!!!!!");
        nums[q--] = num;
    }
    

}

Twelve::Twelve(const std::string &t)
{
    size = t.size();
    nums = new unsigned char [size];
    int q = size - 1;

    for (size_t w = 0; w < size; w++){
         if (!((t[w] >= 'A' && t[w] <= 'B') || (t[w] >= '0' && t[w] <= '9')))
            throw std::invalid_argument("!!!!!!! input number does not satisfy the conditions !!!!!!!");
        nums[q] = t[w];
        q--;
    }

}

Twelve::Twelve(const Twelve& other)
{
    size = other.size;
    nums = new unsigned char [size];

    for (size_t q = 0; q < size; q++){
        nums[q] = other.nums[q];
    }

}

Twelve::Twelve(Twelve&& other) noexcept
{
    size = other.size;
    nums = other.nums;

}

Twelve::~Twelve() noexcept
{
    size = 0;
    delete[] nums;
    nums = nullptr;
}

///////////////////////// МЕТОДЫ ////////////////////////

// Получение размера
int Twelve::GetSize()
{
    return size;
}


// Получение указателя на массив nums
unsigned char* Twelve::GetNums()
{
    return nums;
}


// перевод из 12 в 10 с.с.
int Twelve::translate_to_10()
{   
    int dop = 0;
    to_10 = 0;
    for (int q = 0; q < size; q++){

        if (nums[q] == 'A'){
            dop = 10 * pow(12, q);
        }

        if (nums[q] == 'B'){
            dop = 11 * pow(12, q);
        }
        to_10 += dop;
        if (nums[q] != 'A' && nums[q] != 'B'){
            to_10 += (nums[q] - '0') * pow(12, q);
        }

        dop = 0;
    }
    return to_10;
}


// сложение 
std::string Twelve::plus(const Twelve& other)
{
    int res = this -> to_10 + other.to_10;
    std::string result;
    std::string rev_result;
    int w = res;
    char dop;

    while (w > 0){
        if (w % 12 == 10){
            result.append("A");
        }
        if (w % 12 == 11){
            result.append("B");
        }
        if ((w % 12 != 10) && (w % 12 != 11)){
            dop = w % 12;
            result.append(std::to_string(dop));
        }
        w /= 12;
    }

    for (int q = result.length() - 1; q >= 0; q--){
        rev_result += result[q];
    }

    return rev_result;
}

// вычитание
std::string Twelve::minus(const Twelve& other)
{
    std::string result;
    std::string rev_result;

    if (this -> to_10 < other.to_10){
        return "negative number";
    }

    if (this -> to_10 == other.to_10){
        return "0";
    }

    if (this -> to_10 > other.to_10){
        int res = this -> to_10 - other.to_10;
        int w = res;
        char dop;

        while (w > 0){
            if (w % 12 == 10){
                result.append("A");
            }
            if (w % 12 == 11){
                result.append("B");
            }
            if ((w % 12 != 10) && (w % 12 != 11)){
                dop = w % 12;
                result.append(std::to_string(dop));
            }
            w /= 12;
        }

        for (int q = result.length() - 1; q >= 0; q--){
            rev_result += result[q];
        }
    }
        return rev_result;
}

// копирование в новую переменную
Twelve Twelve::copy()
{
    Twelve result;
    size_t w = size - 1;
    for (size_t q = 0; q < size; q++) {
        result.nums[w] = nums[q];
        w--;
    }
    return result;
}

// сравнение >
std::string Twelve::bigger(const Twelve& other)
{
    if (this -> to_10 > other.to_10){
        return "true";
    }

    else{
        return "false";
    }
}

// сравнение <
std::string Twelve::smaller(const Twelve& other)
{
    if (this -> to_10 < other.to_10){
        return "true";
    }

    else{
        return "false";
    }
}

// сравнение =
std::string Twelve::equally(const Twelve& other)
{
    if (this -> to_10 == other.to_10){
        return "true";
    }

    else{
        return "false";
    }
}
