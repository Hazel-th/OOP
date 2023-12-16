#include "../include/Validator.h"
#include "vector"

void TriangleValidator::validate(Figure & figure) const {
    oneLine(figure.getPoint());
    equilateral(figure.getPoint());
}

void TriangleValidator::oneLine(Point *points) const {
    double len1 = len(points[0], points[1]);
    double len2 = len(points[1], points[2]);
    double len3 = len(points[0], points[2]);
    if (len3 == len2 + len1) {
        throw std::invalid_argument("Такого треугольника не существует");
    }
}


void TriangleValidator::equilateral(Point * points) const {
    double a = len(points[0], points[1]);
    double b = len(points[1], points[2]);
    double c = len(points[0], points[2]);
    if (a != b && b != c && a != c) {
        std::cout << a << ' ' << b << ' ' << c << '\n';
        throw std::invalid_argument("Треугольник может быть только равностороннним");
    }
}


bool TriangleValidator::goodType(Figure & figure) const {
    return figure.type() == "Triangle";
}


void RectangleValidator::validate(Figure &figure) const {
    oneLine(figure.getPoint());
    equilateral(figure.getPoint());
    corectPoints(figure.getPoint());


    if ((!isParalel(figure.getPoint()[0] - figure.getPoint()[3], figure.getPoint()[2] - figure.getPoint()[1])) && (!isParalel(figure.getPoint()[3] - figure.getPoint()[2], figure.getPoint()[1] - figure.getPoint()[0])) ){
        throw std::invalid_argument("Противоположные стороны не паралельны");
    }
}


void RectangleValidator::oneLine(Point *points) const {
    double a = len(points[0], points[1]);
    double b = len(points[1], points[2]);
    double c = len(points[2], points[3]);
    double d = len(points[0], points[3]);
    double len1 = len(points[0], points[2]);
    double len2 = len(points[1], points[3]);
    if (len1 == a + b || len2 == c + d) {
        throw std::invalid_argument("Такого прямоугольника не существует!");
    }
}


void RectangleValidator::corectPoints(Point *points) const {
    double a = len(points[0], points[1]);
    double b = len(points[1], points[2]);
    double c = len(points[2], points[3]);
    double d = len(points[0], points[3]);
    if (sqrt(a * a + b * b) != len(points[0], points[2])
        || sqrt(c * c + d * d) != len(points[1], points[3])) {
            throw std::invalid_argument("Такого прямоугольника не существует");
    }
}


void RectangleValidator::equilateral(Point * points) const {
    double a = len(points[0], points[1]);
    double b = len(points[1], points[2]);
    double c = len(points[2], points[3]);
    double d = len(points[0], points[3]);
    if (a != c || b != d) {
        throw std::invalid_argument("Такого проямоугольника не может быть");
    }
}


bool RectangleValidator::goodType(Figure & figure) const {
    return figure.type() == "Rectangle";
}


void BoxValidator::validate(Figure &figure) const {
    oneLine(figure.getPoint());
    equilateral(figure.getPoint());
    corectPoints(figure.getPoint());
}


void BoxValidator::oneLine(Point *points) const {
    double len1 = len(points[0], points[1]);
    double len2 = len(points[1], points[2]);
    double len3 = len(points[0], points[2]);
    if (len3 == len2 + len1) {
        throw std::invalid_argument("Все точки на одной линии");
    }
}


void BoxValidator::corectPoints(Point *points) const {

}

void BoxValidator::equilateral(Point * points) const {
    double a = len(points[0], points[1]);
    double b = len(points[1], points[2]);
    double c = len(points[2], points[3]);
    double d = len(points[0], points[3]);
    if (!(a == b && b == c && c == d)) {
        throw std::invalid_argument("Такого квадрата не может быть");
    }
}


bool BoxValidator::goodType(Figure & figure) const {
    return figure.type() == "Box";
}


Validator::Validator() {
    validations.push_back(dynamic_cast<IValidator*>(new TriangleValidator()));
    validations.push_back(dynamic_cast<IValidator*>(new RectangleValidator()));
    validations.push_back(dynamic_cast<IValidator*>(new BoxValidator()));
}



Validator::~Validator() {}

void Validator::validate_figure(Figure &figure) {
    for (int i = 0; i < validations.size(); ++i) {
        auto validation = validations[i];
        if (validation->goodType(figure)) {
            validation->validate(figure);
            return;
        }
    }
}