#pragma once
#include<iostream>
#include"Figure.h"

class Square: public Figure 
{

    friend std::istream& operator>>(std::istream& is, Square& square);
    friend std::ostream& operator<<(std::ostream& os, const Square& square);

public:

    Square();
    Square(double coord[8], double& diag);
    Square(const Square& other);
    Square(Square&& other);
    ~Square();

    virtual operator double() override; 
    virtual double get_area() override;
    virtual double get_centre_x() override;
    virtual double get_centre_y() override;

    Square& operator=(const Square& other);
    Square& operator=(Square&& other);
    bool operator==(const Square& other) const;

protected:

    double a;

};

inline std::istream& operator>>(std::istream& is, Square& square){

    double coord[8];
    std::cout << "Введите координаты вершин квадрата в таком порядке через пробелы: A(x) A(y) B(x) B(y) C(x) C(y) D(x) D(y), где вершины A B C D идут по кругу: " << "\n";
    
    for (int q = 0; q < 8; q++){
        is >> coord[q];
        square.coord[q] = coord[q];
    }
    std::cout << "Введите длину стороны квадрата: " << "\n";
    is >> square.a;
    std::cout << "Ввод закончен." << "\n";

    return is;
}

inline std::ostream& operator<<(std::ostream& os, const Square& square){

    os << "Координаты квадрата:" << "\n"; 
    os << "A: x = " << square.coord[0] << "; y = " << square.coord[1] << "\n";
    os << "B: x = " << square.coord[2] << "; y = " << square.coord[3] << "\n";
    os << "C: x = " << square.coord[4] << "; y = " << square.coord[5] << "\n";
    os << "D: x = " << square.coord[6] << "; y = " << square.coord[7] << "\n";
    os << "Длина стороны квадрата квадрата: " << square.a << "\n";

    return os;
}