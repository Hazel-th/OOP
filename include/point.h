#pragma once
#include <iostream>
#include <cmath>


const double EPS = 1e-6;


template <typename T = double>
class Point {
public:
    T x, y;

    ~Point() = default;

    Point(T _x = T(), T _y = T());

    Point(const Point& point);

    Point(const Point && point);

    Point& operator=(const Point & point);

    Point& operator=(Point &&point);

    void setX(T x);

    void setY(T y);

    T getX() const ;

    T getY() const ;

    template<class U>
    friend std::ostream& operator<<(std::ostream& out, const Point<U>& point);

    template<class U>
    friend std::istream& operator>>(std::istream& in, Point<U>& point);

    template <class U>
    friend bool operator==(const Point<U>& point1, const Point<U> & point2);

    template<class U>
    friend Point<U> operator-(Point<U> & point1, Point<U> & point2);

};


template <typename T>
bool isParalel(const Point<T>& p1, const Point<T>& p2);

template <typename T>
T dot(const Point<T>& p1, const Point<T>& p2);

template <typename T>
T abs(const Point<T>& p1);

template <typename T>
T cos(const Point<T>& p1, const Point<T>& p2);

template <typename T>
std::ostream& operator<<(std::ostream& out, const Point<T>& point);

template <typename T>
std::istream& operator>>(std::istream& in, Point<T>& point);

template <typename T>
bool operator==(const Point<T>& point1, const Point<T> & point2);

template <typename T>
double len(Point<T> & point1, Point<T> & point2);

template <typename T>
Point<T> operator-(Point<T> & point1, Point<T> & point2);


#include "../src/Point.inl"