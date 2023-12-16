#include "../include/Box.h"


Box::Box() {
    this->point = new Point[4];
    if (this->point == nullptr)
        throw std::string("The point is not allocated!");
}


Box::Box(Point &point1, Point &point2, Point &point3, Point &point4) {
    this->point = new Point[4];
    if (this->point == nullptr)
        throw std::string("The point is not allocated!");
    point[0] = point1;
    point[1] = point2;
    point[2] = point3;
    point[3] = point4;
}


std::ostream& Box::print(std::ostream &out) const {
    for (int i = 0; i < 4; ++i) {
        out << point[i] << std::endl;
    }
    return out;
}


std::istream& Box::scan(std::istream &in) {
    int cnt = 1;
    for (int i = 0; i < 4; ++i) {
        std::cout << "Введите координаты точки " << cnt++ << ": ";
        in >> point[i];
    }
    return in;
}

Point Box::center() const {
    double x = point[0].x + point[1].x + point[2].x + point[3].x;
    double y = point[0].y + point[1].y + point[2].y + point[3].y;
    return Point(x / 4, y / 4);
}


double Box::square() const {
    double x = len(point[0], point[1]);
    return x * x;
}

Figure & Box::operator=(const Figure &figure) {
    this->point = figure.getPoint();
    return *this;
}


Figure & Box::operator=(const Figure && figure) {
    this->point = std::move(figure.getPoint());
    return *this;
}


bool Box::equal(const Figure &figure) const {
    for (int i = 0; i < 4; ++i) {
        if (point[i] != figure.getPoint()[i]) {
            return false;
        }
    }
    return true;
}



Point * Box::getPoint() const { return this->point; }