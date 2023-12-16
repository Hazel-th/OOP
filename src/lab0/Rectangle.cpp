#include "../include/Rectangle.h"


Rectangle::Rectangle() {
    this->point = new Point[4];
    if (point == nullptr)
        throw std::string("The point is not allocated");
}


Rectangle::Rectangle(Point &point1, Point &point2, Point &point3, Point &point4) {
    this->point = new Point[4];
    if (this->point == nullptr)
        throw std::string("The point is not allocated!");
    point[0] = point1;
    point[1] = point2;
    point[2] = point3;
    point[3] = point4;
}


std::ostream& Rectangle::print(std::ostream &out) const {
    for (int i = 0; i < 4; ++i) {
        out << point[i] << std::endl;
    }
    return out;
}


std::istream& Rectangle::scan(std::istream &in) {
    int cnt = 1;
    for (int i = 0; i < 4; ++i) {
        std::cout << "Введите координаты точки " << cnt++ << ": ";
        in >> point[i];
    }
    return in;
}

Point Rectangle::center() const {
    double x = point[0].x + point[1].x + point[2].x + point[3].x;
    double y = point[0].y + point[1].y + point[2].y + point[3].y;
    return Point(x / 4, y / 4);
}


double Rectangle::square() const {
    double x = len(point[0], point[1]);
    double y = len(point[1], point[2]);
    return x * y;
}


Figure & Rectangle::operator=(const Figure &figure) {
    this->point = figure.getPoint();
    return *this;
}


Figure & Rectangle::operator=(const Figure && figure) {
    this->point = std::move(figure.getPoint());
    return *this;
}


bool Rectangle::equal(const Figure &figure) const {
    for (int i = 0; i < 4; ++i) {
        if (point[i] != figure.getPoint()[i]) {
            return false;
        }
    }
    return true;
}


Point * Rectangle::getPoint() const { return this->point; }