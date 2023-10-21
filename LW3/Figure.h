#pragma once
#include<iostream>

class Figure 
{

    friend std::istream& operator>>(std::istream& is, Figure& figure);
    friend std::ostream& operator<<(std::ostream& os, const Figure& figure);

public:

    Figure();
    Figure(double coord[8]);
    Figure(const Figure& other);
    Figure(Figure&& other);
    virtual ~Figure();

    virtual operator double() = 0; // возвращает площадь фигуры
    virtual double get_area() = 0;
    virtual double get_centre_x() = 0;
    virtual double get_centre_y() = 0;

protected:

    double coord[8];
    double area;
    double centre_x;
    double centre_y;

};

inline std::istream& operator>>(std::istream& is, Figure& figure){

    double coord[8];
    std::cout << "Введите координаты вершин фигуры в таком порядке через пробелы: A(x) A(y) B(x) B(y) C(x) C(y) D(x) D(y), где вершины A B C D идут по кругу: " << "\n";
    
    for (int q = 0; q < 8; q++){
        is >> coord[q];
        figure.coord[q] = coord[q];
    }
    std::cout << "Ввод закончен." << "\n";
    return is;
}

inline std::ostream& operator<<(std::ostream& os, const Figure& figure){

    os << "Координаты фигуры:" << "\n"; 
    os << "A: x = " << figure.coord[0] << "; y = " << figure.coord[1] << "\n";
    os << "B: x = " << figure.coord[2] << "; y = " << figure.coord[3] << "\n";
    os << "C: x = " << figure.coord[4] << "; y = " << figure.coord[5] << "\n";
    os << "D: x = " << figure.coord[6] << "; y = " << figure.coord[7] << "\n";

    return os;
}