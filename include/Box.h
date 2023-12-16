#pragma once
#include "Rectangle.h"

class Box : public Rectangle {

public:
    Box();
    ~Box() = default;
    Point * getPoint() const override final;
    Box(Point& point1, Point& point2, Point& point3, Point & point4);
    Point center() const override final;
    double square() const override final;
    std::ostream& print(std::ostream& out) const override final;
    std::istream& scan(std::istream& in) override final;
    bool equal(const Figure& figure) const override final;
    Figure& operator=(const Figure& figure) override final;
    Figure& operator=(const Figure&& figure) override final;
    std::string type() const override { return "Box"; };
    Rectangle &toRectangle();

};