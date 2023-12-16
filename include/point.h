#pragma once
#include <iostream>
#include <cmath>


const double EPS = 1e-6;

class Point {
public:
    ~Point() = default;
    Point(double x = 0, double y = 0);
    Point(const Point& point);
    Point(const Point && point);
    Point operator=(Point& point);
    void setX(double x);
    void setY(double y);
    double getX() const ;
    double getY() const ;
    friend std::ostream& operator<<(std::ostream& out, const Point& point);
    friend std::istream& operator>>(std::istream& in, Point& point);
    friend bool operator==(const Point& point1, const Point & point2);
    friend Point &operator-(Point & point1, Point & point2);

    double x, y;
};

bool isParalel(const Point& p1, const Point& p2);

double dot(const Point& p1, const Point& p2);
double abs(const Point& p1);
double cos(const Point& p1, const Point& p2);


std::ostream& operator<<(std::ostream& out, const Point& point);
std::istream& operator>>(std::istream& in, Point& point);
bool operator==(const Point& point1, const Point & point2);
double len(Point & point1, Point & point2);
Point &operator-(Point & point1, Point & point2);