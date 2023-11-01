#include<iostream>
#include<cmath>
#include"Square.h"

Square::Square(): Figure()
{
    a = 0;
}
    
Square::Square(double coord[8], double& a): Figure(coord)
{
    this->a = a;
}

Square::Square(const Square& other): Figure(other)
{
    this->a = other.a;
}

Square::Square(Square&& other): Figure(std::move(other))
{
    this->a = other.a;
    other.a = 0;
}

Square::~Square()
{
    a = 0;
}

///////////////////////////////////////////////////
Square::operator double()
{   
    area = pow(a,2);
    return area;
} 

double Square:: get_area()
{
    area = pow(a,2);
    return area;
}

double Square::get_centre_x()
{
    centre_x = (coord[0]+coord[2]+coord[4]+coord[6]) / 4;
    return centre_x;
}

double Square::get_centre_y()
{
    centre_y = (coord[1]+coord[3]+coord[5]+coord[7]) / 4;
    return centre_y;
}

Square& Square::operator=(const Square& other)
{
    if (this != &other){
        // delete[] coord (указатель на динамический массив с координатами)
        // this->size = other.size; (размер массива)
        // coord = new double[size];
        for (int q = 0; q < 8; q++){
            this->coord[q] = other.coord[q];
        }
        this->a = other.a;
    }
    return *this;
}

Square& Square::operator=(Square&& other)
{
    if (this != &other){
        // delete[] coord (указатель на динамический массив с координатами)
        // this->size = other.size; (размер массива)
        // coord = new double[size];
        for (int q = 0; q < 8; q++){
            this->coord[q] = other.coord[q];
            other.coord[q] = 0;
        }
        this->a = other.a;
        other.a = 0;
    }
    return *this;
}

bool Square::operator==(const Square& other) const
{
    if (this->a != other.a){
        return false;
    }
    return true;
}