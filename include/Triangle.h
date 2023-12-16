#pragma once
#include "Figure.h"


class Triangle : public Figure {

public:

    Triangle();
    ~Triangle() = default;
    Point * getPoint() const override final;
    Triangle(Point& point1, Point& point2, Point& point3);
    Point center() const final override;
    double square() const final override;
    std::ostream& print(std::ostream& out) const override;
    std::istream& scan(std::istream& in) override;
    bool equal(const Figure& figure) const override;
    Figure& operator=(const Figure& figure) override;
    Figure& operator=(const Figure&& figure) override;
    std::string type() const override { return "Triangle"; };

};
