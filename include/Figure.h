#pragma once
#include "point.h"


class Figure {
protected:
    Point * point;

public:
    virtual Point * getPoint() const { return point; };

    Figure() = default;
    ~Figure();

    virtual Point center() const = 0;
    friend std::ostream& operator<< (std::ostream& out, const Figure& figure);
    friend std::istream& operator>> (std::istream& in, const Figure& figure);
    virtual double square() const = 0;
    virtual std::ostream& print(std::ostream& out) const = 0;
    virtual std::istream& scan(std::istream& in) = 0;
    virtual Figure& operator=(const Figure& figure) = 0;
    virtual Figure& operator=(const Figure&& figure) = 0;
    virtual bool equal(const Figure& figure) const = 0;
    virtual std::string type() const { return "Figure"; };


};


std::ostream& operator<< (std::ostream& out, const Figure& figure);
std::istream& operator>> (std::istream& in, Figure& figure);
bool operator==(const Figure& figure1, const Figure& figure2);