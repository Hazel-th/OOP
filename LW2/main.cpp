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
}