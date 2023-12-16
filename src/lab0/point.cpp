#include "../include/point.h"


Point::Point(const Point& point) : x(point.x), y(point.y) {}

Point::Point(double _x, double _y) : x(_x), y(_y) {}

Point Point::operator=(Point &point) {
    x = point.x;
    y = point.y;
    return *this;
}



void Point::setX(double x) { this->x = x; }

void Point::setY(double y) { this->y = y; }

double Point::getX() const { return x; }

double Point::getY() const { return y; }

std::ostream& operator<<(std::ostream& out, const Point& point) {
    out << "(" << point.x << ", " << point.y << ")";
    return out;
}

std::istream& operator>>(std::istream& in, Point& point) {
    in >> point.x >> point.y;
    return in;
}


bool operator==(const Point& point1, const Point & point2) { return point1.x == point2.x && point1.y == point2.y; }



Point::Point(const Point &&point) : x(point.x), y(point.y) {}

double len(Point &point1, Point &point2) {
    double _x = point1.x - point2.x;
    double _y = point1.y - point2.y;
    return std::sqrt(_x * _x + _y * _y);
}


bool isParalel(const Point& p1, const Point& p2){
    if (fabs(fabs(cos(p1, p2)) -1) <= EPS){
        return true;
    }
    return false;
}

double dot(const Point& p1, const Point& p2){
    return p1.getX() * p2.getX() + p1.getY() * p2.getY();
}
double abs(const Point& p1){
    return sqrt(p1.getX() * p1.getX() + p1.getY() * p1.getY())  ;
}
double cos(const Point& p1, const Point& p2){
    return dot(p1,p2) / (abs(p1) * abs(p2));
}

Point &operator-(Point & point1, Point & point2) {
    Point point(point1.x - point2.x, point1.y - point2.y);
    return point;
}


Point &operator+(Point & point1, Point & point2) {
    Point point(point1.x + point2.x, point1.y + point2.y);
    return point;
}