#include "../include/Triangle.h"


Triangle::Triangle() {
    this->point = new Point[3];
    if (this->point == nullptr)
        throw std::string("The point is not allocated!");
}


Triangle::Triangle(Point &point1, Point &point2, Point &point3) {
    this->point = new Point[3];
    if (this->point == nullptr)
        throw std::string("The point is not allocated!");
    point[0] = point1;
    point[1] = point2;
    point[2] = point3;
}


std::ostream& Triangle::print(std::ostream &out) const {
    for (int i = 0; i < 3; ++i) {
        out << point[i] << std::endl;
    }
    return out;
}


std::istream& Triangle::scan(std::istream &in) {
    int cnt = 1;
    for (int i = 0; i < 3; ++i) {
        std::cout << "Введите координаты точки " << cnt++ << ": ";
        in >> point[i];
    }
    return in;
}

Point Triangle::center() const {
    double x = (point[0].x + point[1].x + point[2].x);
    double y = (point[0].y + point[1].y + point[2].y);
    return Point(x / 3, y / 3);
}


double Triangle::square() const {
    double side = len(this->getPoint()[0], this->getPoint()[1]);
    return side * side * sqrt(3) / 4;
}

Figure & Triangle::operator=(const Figure &figure) {
    this->point = figure.getPoint();
    return *this;
}


Figure & Triangle::operator=(const Figure && figure) {
    this->point = std::move(figure.getPoint());
    return *this;
}


bool Triangle::equal(const Figure &figure) const {
    for (int i = 0; i < 3; ++i) {
        if (point[i] != figure.getPoint()[i]) {
            return false;
        }
    }
    return true;
}



Point * Triangle::getPoint() const { return this->point; }