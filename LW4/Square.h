#pragma once
#include<iostream>
#include<cmath>
#include"Figure.h"

template <typename Sq>
class Square: public Figure<Sq>
{
    template <typename T>
    friend std::istream& operator>>(std::istream& is, Square<T>& square);
    template <typename T>
    friend std::ostream& operator<<(std::ostream& os, const Square<T>& square);

public:

    Square(): Figure<Sq>(){
        a = 0;
    }

    Square(std::pair<Sq, Sq> coord[4], Sq& a): Figure<Sq>(coord){
        this->a = a;
    }

    Square(const Square& other): Figure<Sq>(other){
        this->a = other.a;
    }

    Square(Square&& other): Figure<Sq>(std::move(other)){
        this->a = other.a;
        other.a = 0;
    }

    ~Square(){
        a = 0;
    }


    virtual Sq get_area() override{
        this->area = pow(a,2);
        return (this->area);
    }


    Square<Sq>& operator=(const Square<Sq>& other){
        if (this != &other){
            for (int q = 0; q < 4; q++){
                this->coord[q] = other.coord[q];
            }
            this->a = other.a;
        }
        return *this;
    }

    Square<Sq>& operator=(Square<Sq>&& other){
        if (this != &other){
            for (int q = 0; q < 4; q++){
                this->coord[q] = other.coord[q];
                other.coord[q] = {0, 0};
            }
            this->a = other.a;
            other.a = 0;
        }
        return *this;
    }

    bool operator==(const Square<Sq>& other) const{
        if (this->a != other.a){
            return false;
        }
        return true;
    }


    Sq a;

};

template <typename T>
inline std::istream& operator>>(std::istream& is, Square<T>& square){

    std::cout << "Введите координаты вершин квадрата в таком порядке через пробелы: A(x) A(y) B(x) B(y) C(x) C(y) D(x) D(y), где вершины A B C D идут по кругу: " << "\n";
    
    for (int q = 0; q < 4; q++){
        is >> square.coord[q].first >> square.coord[q].second;
    }
    std::cout << "Введите длину стороны квадрата: " << "\n";
    is >> square.a;
    std::cout << "Ввод закончен." << "\n";

    return is;
}

template <typename T>
inline std::ostream& operator<<(std::ostream& os, const Square<T>& square){

    os << "Координаты квадрата:" << "\n"; 
    os << "A: x = " << square.coord[0].first << "; y = " << square.coord[0].second << "\n";
    os << "B: x = " << square.coord[1].first << "; y = " << square.coord[1].second << "\n";
    os << "C: x = " << square.coord[2].first << "; y = " << square.coord[2].second << "\n";
    os << "D: x = " << square.coord[3].first << "; y = " << square.coord[3].second << "\n";
    os << "Длина стороны квадрата квадрата: " << square.a << "\n";

    return os;
}