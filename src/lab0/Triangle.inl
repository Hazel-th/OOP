#pragma once
#include "../lib/Validator.h"

const int Size = 4;

template <typename T>
Rectangle<T>::Rectangle() {
    this->point = std::shared_ptr<Point<T>[]>(::new Point<T>[4]);
    for (int i = 0; i < 4; ++i) {
        ::new (this->point.get() + i) Point<T>();
    }
}


template <typename T>
Rectangle<T>::Rectangle(const Point<T> & point1,
                        const Point<T> & point2,
                        const Point<T> & point3,
                        const Point<T> & point4)
{
    this->point = std::shared_ptr<Point<T>[]>(::new Point<T>[4]);
    this->point[0] = point1;
    this->point[1] = point2;
    this->point[2] = point3;
    this->point[3] = point4;
    Validator<T> validator;
    validator.validate_figure(*this);
}


template <typename T>
std::ostream& Rectangle<T>::print(std::ostream &out) const {
    for (int i = 0; i < 4; ++i) {
        out << this->point[i] << std::endl;
    }
    return out;
}


template <typename T>
std::istream& Rectangle<T>::scan(std::istream &in) {
    int cnt = 1;
    for (int i = 0; i < 4; ++i) {
        std::cout << "Введите координаты точки " << cnt++ << ": ";
        in >> this->point[i];
    }
    return in;
}


template <class T>
Rectangle<T>::Rectangle(const Rectangle<T> & rectangle) : Rectangle<T>() {
    for (int i = 0; i < Size; ++i) {
        ::new (this->point.get() + i) Point<T>(rectangle.point[i]);
    }

}


template <typename T>
Point<T> Rectangle<T>::center() const {
    double x = this->point[0].x + this->point[1].x + this->point[2].x + this->point[3].x;
    double y = this->point[0].y + this->point[1].y + this->point[2].y + this->point[3].y;
    return Point<T>(x / 4, y / 4);
}


template <typename T>
double Rectangle<T>::square() const {
    double x = len(this->point[0], this->point[1]);
    double y = len(this->point[1], this->point[2]);
    return x * y;
}


template <typename T>
Rectangle<T> & Rectangle<T>::operator=(const Rectangle<T> & rectangle) {
    for (int i = 0; i < 4; ++i) {
        ::new (this->point.get() + i) Point<T>(rectangle.point[i]);
    }
    return *this;
}


template <typename T>
Rectangle<T> & Rectangle<T>::operator=(const Rectangle<T> && rectangle) {
    if (this != &rectangle)
        this->point = std::move(rectangle.point);
    return *this;
}


template <typename T>
bool Rectangle<T>::equal(const Figure<T> &figure) const {
    for (int i = 0; i < 4; ++i) {
        if (this->point[i] != figure.getPoint()[i]) {
            return false;
        }
    }
    return true;
}


template <typename T>
std::shared_ptr<Point<T>[]> Rectangle<T>::getPoint() const { return this->point; }