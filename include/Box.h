#pragma once
#include "Rectangle.h"


template <typename T>
class Box : public Rectangle<T> {

public:
    Box() = default;
    ~Box() = default;
    std::shared_ptr<Point<T>[]> getPoint() const final;
    Box(const Box & box);
    Box(const Point<T> & point1,
        const Point<T> & point2,
        const Point<T> & point3,
        const Point<T> & point4);
    Point<T> center() const final;
    double square() const final;
    std::ostream& print(std::ostream& out) const final;
    std::istream& scan(std::istream& in) final;
    bool equal(const Figure<T>& figure) const final;
    Box<T> & operator=(const Box<T> & box);
    Box<T> & operator=(Box<T> && box);
    std::string type() const override { return "Box"; };

};

#include "../src/Box.inl"