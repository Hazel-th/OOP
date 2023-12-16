#pragma once
#include "Figure.h"

template <typename T>
class Rectangle : public Figure<T> {

public:

    Rectangle();
    ~Rectangle() = default;
    virtual std::shared_ptr<Point<T>[]> getPoint() const override;
    Rectangle(const Point<T> & point1,
              const Point<T> & point2,
              const Point<T> & point3,
              const Point<T> & point4);

    Rectangle(const Rectangle<T> & rectangle);
    virtual Point<T> center() const override;
    virtual double square() const override;
    virtual std::ostream& print(std::ostream& out) const override;
    virtual std::istream& scan(std::istream& in) override;
    virtual bool equal(const Figure<T>& figure) const override;
    Rectangle<T>& operator=(const Rectangle<T> & rectangle);
    Rectangle<T>& operator=(const Rectangle<T> && rectangle);
    std::string type() const override { return "Rectangle"; };

};




#include "../src/Rectangle.inl"