#pragma once


template <typename T>
Point<T>::Point(const Point<T> & point) : x(point.x), y(point.y) {}


template <typename T>
Point<T>::Point(T _x, T _y) : x(_x), y(_y) {}


template <typename T>
Point<T>& Point<T>::operator=(const Point<T> & point){
    x = point.x;
    y = point.y;
    return *this;
}


template <class T>
Point<T>& Point<T>::operator=(Point<T> &&point) {
    Point<T> temp(std::move(point));
    *this = temp;
    return *this;
}



template <typename T>
void Point<T>::setX(T x) { this->x = x; }


template <typename T>
void Point<T>::setY(T y) { this->y = y; }


template <typename T>
T Point<T>::getX() const { return x; }


template <typename T>
T Point<T>::getY() const { return y; }


template <typename T>
std::ostream& operator<<(std::ostream& out, const Point<T>& point) {
    out << "(" << point.x << ", " << point.y << ")";
    return out;
}


template <typename T>
std::istream& operator>>(std::istream& in, Point<T>& point) {
    in >> point.x >> point.y;
    return in;
}


template <typename T>
bool operator==(const Point<T>& point1, const Point<T> & point2) { return point1.x == point2.x && point1.y == point2.y; }



template <typename T>
Point<T>::Point(const Point<T> &&point) : x(point.x), y(point.y) {}


template <typename T>
double len(Point<T> &point1, Point<T> &point2) {
    double _x = point1.x - point2.x;
    double _y = point1.y - point2.y;
    return std::sqrt(_x * _x + _y * _y);
}


template <typename T>
bool isParalel(const Point<T> & p1, const Point<T> & p2){
    if (fabs(fabs(cos(p1, p2)) -1) <= EPS){
        return true;
    }
    return false;
}


template <typename T>
T dot(const Point<T>& p1, const Point<T>& p2){
    return p1.getX() * p2.getX() + p1.getY() * p2.getY();
}


template <typename T>
T abs(const Point<T>& p1){
    return sqrt(p1.getX() * p1.getX() + p1.getY() * p1.getY());
}


template <typename T>
T cos(const Point<T>& p1, const Point<T>& p2){
    return dot(p1,p2) / (abs(p1) * abs(p2));
}


template <typename T>
Point<T> operator-(Point<T> & point1, Point<T> & point2) {
    Point<T> point(point1.x - point2.x, point1.y - point2.y);
    return point;
}


template <typename T>
Point<T> operator+(Point<T> & point1, Point<T> & point2) {
    Point<T> point(point1.x + point2.x, point1.y + point2.y);
    return point;
}