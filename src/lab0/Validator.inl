#pragma once


template <typename T>
void TriangleValidator<T>::validate(Figure<T> & figure) const {
    oneLine(figure.getPoint());
    equilateral(figure.getPoint());
}


template <typename T>
void TriangleValidator<T>::oneLine(std::shared_ptr<Point<T>[]> points) const {
    double len1 = len(points[0], points[1]);
    double len2 = len(points[1], points[2]);
    double len3 = len(points[0], points[2]);
    if (len3 == len2 + len1) {
        throw std::invalid_argument("Такого треугольника не существует");
    }
}


template <typename T>
void TriangleValidator<T>::equilateral(std::shared_ptr<Point<T>[]>  points) const {
    double a = len(points[0], points[1]);
    double b = len(points[1], points[2]);
    double c = len(points[0], points[2]);
    if (a != b && b != c && a != c) {
        std::cout << a << ' ' << b << ' ' << c << '\n';
        throw std::invalid_argument("Треугольник может быть только равностороннним");
    }
}


template <typename T>
bool TriangleValidator<T>::goodType(Figure<T> & figure) const {
    return figure.type() == "Triangle";
}


template <typename T>
void RectangleValidator<T>::validate(Figure<T> & figure) const {
    oneLine(figure.getPoint());
    equilateral(figure.getPoint());
    corectPoints(figure.getPoint());

    Point<T> point0 = figure.getPoint()[0];
    Point<T> point1 = figure.getPoint()[1];
    Point<T> point2 = figure.getPoint()[2];
    Point<T> point3 = figure.getPoint()[3];

    if ((!isParalel(point0 - point3, point2 - point1))
        && (!isParalel(point3 - point2, point1 - point0))){
        throw std::invalid_argument("Противоположные стороны не паралельны");
    }
}


template <typename T>
void RectangleValidator<T>::oneLine(std::shared_ptr<Point<T>[]> points) const {
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


template <typename T>
void RectangleValidator<T>::corectPoints(std::shared_ptr<Point<T>[]> points) const {
    double a = len(points[0], points[1]);
    double b = len(points[1], points[2]);
    double c = len(points[2], points[3]);
    double d = len(points[0], points[3]);
    if (sqrt(a * a + b * b) != len(points[0], points[2])
        || sqrt(c * c + d * d) != len(points[1], points[3])) {
        throw std::invalid_argument("Такого прямоугольника не существует");
    }
}


template <typename T>
void RectangleValidator<T>::equilateral(std::shared_ptr<Point<T>[]>  points) const {
    double a = len(points[0], points[1]);
    double b = len(points[1], points[2]);
    double c = len(points[2], points[3]);
    double d = len(points[0], points[3]);
    if (a != c || b != d) {
        throw std::invalid_argument("Такого проямоугольника не может быть");
    }
}


template <typename T>
bool RectangleValidator<T>::goodType(Figure<T> & figure) const {
    return figure.type() == "Rectangle";
}


template <typename T>
void BoxValidator<T>::validate(Figure<T> & figure) const {
    oneLine(figure.getPoint());
    equilateral(figure.getPoint());
    corectPoints(figure.getPoint());
}


template <typename T>
void BoxValidator<T>::oneLine(std::shared_ptr<Point<T>[]> points) const {
    double len1 = len(points[0], points[1]);
    double len2 = len(points[1], points[2]);
    double len3 = len(points[0], points[2]);
    if (len3 == len2 + len1) {
        throw std::invalid_argument("Все точки на одной линии");
    }
}


template <typename T>
void BoxValidator<T>::corectPoints(std::shared_ptr<Point<T>[]> points) const {

}


template <typename T>
void BoxValidator<T>::equilateral(std::shared_ptr<Point<T>[]> points) const {
    double a = len(points[0], points[1]);
    double b = len(points[1], points[2]);
    double c = len(points[2], points[3]);
    double d = len(points[0], points[3]);
    if (!(a == b && b == c && c == d)) {
        throw std::invalid_argument("Такого квадрата не может быть");
    }
}


template <typename T>
bool BoxValidator<T>::goodType(Figure<T> & figure) const {
    return figure.type() == "Box";
}


template <typename T>
Validator<T>::Validator() {
    validations.push_back(std::shared_ptr<IValidator<T>>(new TriangleValidator<T>()));
    validations.push_back(std::shared_ptr<IValidator<T>>(new RectangleValidator<T>()));
    validations.push_back(std::shared_ptr<IValidator<T>>(new BoxValidator<T>()));
}



template <typename T>
Validator<T>::~Validator() {}


template <typename T>
void Validator<T>::validate_figure(Figure<T> & figure) {
    for (int i = 0; i < validations.size(); ++i) {
        auto validation = validations[i];
        if (validation->goodType(figure)) {
            validation->validate(figure);
        }
    }
}