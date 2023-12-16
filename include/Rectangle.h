#pragma once
#include "Figure.h"


class Rectangle : public Figure {

public:

    Rectangle();
    ~Rectangle() = default;
    virtual Point * getPoint() const override;
    Rectangle(Point& point1, Point& point2, Point& point3, Point & point4);
    virtual Point center() const override;
    virtual double square() const override;
    virtual std::ostream& print(std::ostream& out) const override;
    virtual std::istream& scan(std::istream& in) override;
    virtual bool equal(const Figure& figure) const override;
    virtual Figure& operator=(const Figure& figure) override;
    virtual Figure& operator=(const Figure&& figure) override;
    std::string type() const override { return "Rectangle"; };

};