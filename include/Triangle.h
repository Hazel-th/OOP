#pragma once
#include "Figure.h"
#include "Validator.h"

template <typename T>
class Triangle : public Figure<T> {

public:

    Triangle();

    ~Triangle() = default;

    std::shared_ptr<Point<T>[]> getPoint() const override;

    Triangle(const Point<T> &point1, const Point<T> &point2, const Point<T> &point3);

    Triangle(const Triangle & other);

    Point<T> center() const override;

    double square() const override;

    std::ostream& print(std::ostream& out) const override;

    std::istream& scan(std::istream& in) override;

    bool equal(const Figure<T>& figure) const override;

    Triangle& operator=(const Triangle& triangle);

    Triangle& operator=(const Triangle&& triangle) noexcept;

    std::string type() const override { return "Triangle"; };

};


#include "../src/Triangle.inl"