# Лабораторная 2
# Кайдалова Александра, М8О-212Б-22, Вариант 10
## Тема: Классы
### Цель:
1. Закрепление навыков работы с классами;
2. Закрепление навыков работы с динамической памятью на «куче»;
3. Закрепление навыков работы с массивами.
#### Требования к программе:
Используя в качестве образца класс Array (см. ниже), реализовать динамические контейнеры с использова-
нием динамического массива.
• Каждый класс должен быть разделен на интерфейс и реализацию.
• Самостоятельно определить необходимые типы, поля и дополнительные методы.
• Реализовать генерацию исключений в конструкторах и методах при необходимости (использовать
стандартные исключения).
• Реализовать арифметические операции: сложение, вычитание, копирование
• Реализовать операции сравнения: (больше, меньше, равно).
• Арифметические операции с присваиванием должны быть реализованы как методы класса.

class Array
{
public:
Array();
Array(const size_t & n, unsigned char t = 0);
Array(const std::initializer_list< unsigned char> &t);
Array(const string &t);
Array(const Array& other);
Array(Array&& other) noexcept;
virtual ~Array() noexcept;
};
#### Вариант 10:
Создать класс Twelve для работы с беззнаковыми целыми двенадцатиричными числами, используя для пред-
ставления числа массив из элементов типа unsigned char, каждый из которых является двенадцатиричными
цифрой. Младшая цифра имеет меньший индекс (единицы – в нулевом элементе массива).

### Код программы:
''' main.cpp:
#include <iostream>
#include <string>
#include "twelve.h"

int main(){
    std::string s_a;
    std::cout << "Enter the first number: \n a = ";
    std::cin >> s_a;

    std::string s_b;
    std::cout << "Enter the second number: \n b = ";
    std::cin >> s_b;

    Twelve a(s_a);
    Twelve b(s_b);

    std::cout << '\n' << "Number of digits in a : " << a.GetSize() << '\n';
    std::cout << "Number of digits in b : " << b.GetSize() << '\n' << '\n';

    std::cout << "Number a in 10 system = " << a.translate_to_10() << '\n';
    std::cout << "Number b in 10 system = " << b.translate_to_10() << '\n' << '\n';

    std::cout << "a + b = " << a.plus(b) << '\n';
    std::cout << "a - b = " << a.minus(b) << '\n';
    std::cout << "b - a = " << b.minus(a) << '\n' << '\n';

    std::cout << "a > b : " << a.bigger(b) << '\n';
    std::cout << "a < b : " << a.smaller(b) << '\n';
    std::cout << "a = b : " << a.equally(b) << '\n' << '\n';

    Twelve c = a.copy();
    std::cout << "Copy of a: c = " << c.GetNums() << '\n';

    Twelve d = b.copy();
    std::cout << "Copy of b: d = " << d.GetNums() << '\n';

    return 0;
}'''

'''twelve.h:
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

}; '''

'''twelve.cpp:
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
} '''

'''tests.cpp:
#include <gtest/gtest.h>
#include "twelve.h"

TEST(test_1, AllMetods)
{
	Twelve a("123");
    Twelve b("2");

	size_t sizea = a.GetSize();
	size_t expectSizea = 3;
    size_t sizeb = b.GetSize();
	size_t expectSizeb = 1;

	unsigned char* numsa = a.GetNums();
	unsigned char expectNumsa[] = {'3', '2', '1'};
    unsigned char* numsb = b.GetNums();
	unsigned char expectNumsb[] = {'2'};

    int to_10a = a.translate_to_10();
    int expectto_10a = 171;
    int to_10b = b.translate_to_10();
    int expectto_10b = 2;
    
    std::string ab = a.plus(b);
    std::string expectab = ("125");
    std::string a_b = a.minus(b);
    std::string expecta_b = ("121");
    std::string b_a = b.minus(a);
    std::string expectb_a = ("negative number");

    std::string aab = a.bigger(b);
    std::string expectaab = ("true");
    std::string abb = a.smaller(b);
    std::string expectabb = ("false");
    std::string aabb = a.equally(b);
    std::string expectaabb = ("false");

// проверка
    ASSERT_EQ(sizea, expectSizea);
    ASSERT_EQ(sizeb, expectSizeb);

	for (size_t q = 0; q < sizea; q++) 
		ASSERT_EQ(numsa[q], expectNumsa[q]);
    for (size_t q = 0; q < sizeb; q++) 
		ASSERT_EQ(numsb[q], expectNumsb[q]);

    ASSERT_EQ(to_10a, expectto_10a);
    ASSERT_EQ(to_10b, expectto_10b);

    ASSERT_EQ(ab, expectab);
    ASSERT_EQ(a_b, expecta_b);
    ASSERT_EQ(b_a, expectb_a);

    ASSERT_EQ(aab, expectaab);
    ASSERT_EQ(abb, expectabb);
    ASSERT_EQ(aabb, expectaabb);

}

TEST(test_2, AllMetods)
{
	Twelve a({'B', 'A', '0'});
    Twelve b({'A', '9', 'B'});

	size_t sizea = a.GetSize();
	size_t expectSizea = 3;
    size_t sizeb = b.GetSize();
	size_t expectSizeb = 3;

	unsigned char* numsa = a.GetNums();
	unsigned char expectNumsa[] = {'0', 'A', 'B'};
    unsigned char* numsb = b.GetNums();
	unsigned char expectNumsb[] = {'B', '9', 'A'};

    int to_10a = a.translate_to_10();
    int expectto_10a = 1704;
    int to_10b = b.translate_to_10();
    int expectto_10b = 1559;
    
    std::string ab = a.plus(b);
    std::string expectab = ("1A7B");
    std::string a_b = a.minus(b);
    std::string expecta_b = ("101");
    std::string b_a = b.minus(a);
    std::string expectb_a = ("negative number");

    std::string aab = a.bigger(b);
    std::string expectaab = ("true");
    std::string abb = a.smaller(b);
    std::string expectabb = ("false");
    std::string aabb = a.equally(b);
    std::string expectaabb = ("false");

// проверка
    ASSERT_EQ(sizea, expectSizea);
    ASSERT_EQ(sizeb, expectSizeb);

	for (size_t q = 0; q < sizea; q++) 
		ASSERT_EQ(numsa[q], expectNumsa[q]);
    for (size_t q = 0; q < sizeb; q++) 
		ASSERT_EQ(numsb[q], expectNumsb[q]);

    ASSERT_EQ(to_10a, expectto_10a);
    ASSERT_EQ(to_10b, expectto_10b);

    ASSERT_EQ(ab, expectab);
    ASSERT_EQ(a_b, expecta_b);
    ASSERT_EQ(b_a, expectb_a);

    ASSERT_EQ(aab, expectaab);
    ASSERT_EQ(abb, expectabb);
    ASSERT_EQ(aabb, expectaabb);

}

TEST(test_3, AllMetods)
{
	Twelve a({'9', '8'});
    Twelve b("B450");

	size_t sizea = a.GetSize();
	size_t expectSizea = 2;
    size_t sizeb = b.GetSize();
	size_t expectSizeb = 4;

	unsigned char* numsa = a.GetNums();
	unsigned char expectNumsa[] = {'8', '9'};
    unsigned char* numsb = b.GetNums();
	unsigned char expectNumsb[] = {'0', '5', '4', 'B'};

    int to_10a = a.translate_to_10();
    int expectto_10a = 116;
    int to_10b = b.translate_to_10();
    int expectto_10b = 19644;
    
    std::string ab = a.plus(b);
    std::string expectab = ("B528");
    std::string a_b = a.minus(b);
    std::string expecta_b = ("negative number");
    std::string b_a = b.minus(a);
    std::string expectb_a = ("B374");

    std::string aab = a.bigger(b);
    std::string expectaab = ("false");
    std::string abb = a.smaller(b);
    std::string expectabb = ("true");
    std::string aabb = a.equally(b);
    std::string expectaabb = ("false");

// проверка
    ASSERT_EQ(sizea, expectSizea);
    ASSERT_EQ(sizeb, expectSizeb);

	for (size_t q = 0; q < sizea; q++) 
		ASSERT_EQ(numsa[q], expectNumsa[q]);
    for (size_t q = 0; q < sizeb; q++) 
		ASSERT_EQ(numsb[q], expectNumsb[q]);

    ASSERT_EQ(to_10a, expectto_10a);
    ASSERT_EQ(to_10b, expectto_10b);

    ASSERT_EQ(ab, expectab);
    ASSERT_EQ(a_b, expecta_b);
    ASSERT_EQ(b_a, expectb_a);

    ASSERT_EQ(aab, expectaab);
    ASSERT_EQ(abb, expectabb);
    ASSERT_EQ(aabb, expectaabb);

}

TEST(test_4, AllMetods)
{
	Twelve a("9");
    Twelve b("9");

	size_t sizea = a.GetSize();
	size_t expectSizea = 1;
    size_t sizeb = b.GetSize();
	size_t expectSizeb = 1;

	unsigned char* numsa = a.GetNums();
	unsigned char expectNumsa[] = {'9'};
    unsigned char* numsb = b.GetNums();
	unsigned char expectNumsb[] = {'9'};

    int to_10a = a.translate_to_10();
    int expectto_10a = 9;
    int to_10b = b.translate_to_10();
    int expectto_10b = 9;
    
    std::string ab = a.plus(b);
    std::string expectab = ("16");
    std::string a_b = a.minus(b);
    std::string expecta_b = ("0");
    std::string b_a = b.minus(a);
    std::string expectb_a = ("0");

    std::string aab = a.bigger(b);
    std::string expectaab = ("false");
    std::string abb = a.smaller(b);
    std::string expectabb = ("false");
    std::string aabb = a.equally(b);
    std::string expectaabb = ("true");

// проверка
    ASSERT_EQ(sizea, expectSizea);
    ASSERT_EQ(sizeb, expectSizeb);

	for (size_t q = 0; q < sizea; q++) 
		ASSERT_EQ(numsa[q], expectNumsa[q]);
    for (size_t q = 0; q < sizeb; q++) 
		ASSERT_EQ(numsb[q], expectNumsb[q]);

    ASSERT_EQ(to_10a, expectto_10a);
    ASSERT_EQ(to_10b, expectto_10b);

    ASSERT_EQ(ab, expectab);
    ASSERT_EQ(a_b, expecta_b);
    ASSERT_EQ(b_a, expectb_a);

    ASSERT_EQ(aab, expectaab);
    ASSERT_EQ(abb, expectabb);
    ASSERT_EQ(aabb, expectaabb);

}

TEST(test_5, InvalidArgument)
{

    ASSERT_THROW(Twelve("-1765"), std::invalid_argument);
}

TEST(test_6, InvalidArgument)
{

    ASSERT_THROW(Twelve("q0w"), std::invalid_argument);
}

TEST(test_7, InvalidArgument)
{

    ASSERT_THROW(Twelve("Пгш"), std::invalid_argument);
}

TEST(test_8, InvalidArgument)
{

    ASSERT_THROW(Twelve({'7', '8', 'R', 'Y'}), std::invalid_argument);
}

TEST(test_9, InvalidArgument)
{

    ASSERT_THROW(Twelve({'*', '7', '6', '5', '5'}), std::invalid_argument);
}

TEST(test_10, InvalidArgument)
{

    ASSERT_THROW(Twelve("76A-9"), std::invalid_argument);
} '''