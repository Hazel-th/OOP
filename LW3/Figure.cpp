#include<iostream>
#include<cmath>
#include"Figure.h"

Figure::Figure()
{
    for (int q = 0; q < 8; q++){
        coord[q] = 0;
    }
}

Figure::Figure(double coord[8])
{
    for (int q = 0; q < 8; q++){
        this->coord[q] = coord[q];
    }
}

Figure::Figure(const Figure& other)
{
    for (int q = 0; q < 8; q++){
        this->coord[q] = other.coord[q];
    }
}

Figure::Figure(Figure&& other)
{
    for (int q = 0; q < 8; q++){
        this->coord[q] = other.coord[q];
        other.coord[q] = 0;
    }
}

Figure::~Figure()
{
    for (int q = 0; q < 8; q++){
        coord[q] = 0;
    }
}