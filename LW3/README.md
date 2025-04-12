# Лабораторная 3
# Нечаев Виктор, М8О-201Б-22, Вариант 10
## Тема: Наследование, полиморфизм
### Цель: 
    1. Изучение механизмов работы с наследованием в С++;
    2. Изучение механизма перегрузки операций.
#### Требования к программе:
Разработать программу на языке C++ согласно 10 варианту задания. Программа на C++ должна собираться с помощью системы сборки CMake. Программа должна получать данные из стандартного ввода (std::cin) и выводить данные в стандартный вывод (std::cout).

Разработать классы согласно 10 варианту задания, классы должны наследоваться от базового класса Figure. Фигуры являются фигурами вращения. Все классы должны поддерживать набор общих методов:
    1. Вычисление геометрического центра фигуры вращения;
    2. Вывод в стандартный поток вывода std::cout координат вершин фигуры через перегрузку оператора << для std::ostream;
    3. Чтение из стандартного потока данных фигур через перегрузку оператора >> для std::istream;
    4. Вычисление площади фигуры через перегрузку оператора приведения к типу double.

Создать программу, которая позволяет:
    1.Вводить из стандартного ввода std::cin фигуры, согласно варианту задания;
    2.Сохранять созданные фигуры в динамический массив (по аналогии с предыдущей лабораторной работой Array) указатели на фигуру (Figure*);
    3.Фигуры должны иметь переопределенные операции копирования (=), перемещения (=) и сравнения (==);
    4.Вызывать для всего массива общие функции (1-3 см. выше).Т.е. распечатывать для каждой фигуры в массиве геометрический центр и площадь;
    5.Необходимо уметь вычислять общую площадь фигур в массиве;
    6.Удалять из массива фигуру по индексу.
#### Вариант 10: 
Фигура №1 - Квадрат;
Фигура №2 - Прямоугольник;
Фигура №3 - Трапеция.
### main.cpp
```cpp
#include<iostream>
#include"Figure.h"
#include"Square.h"
#include"Rectangle.h"
#include"Trapezoid.h"
#include"Array.h"

int main(){

    Array figures(3);

    double coord_sq[8] = {2.0, 4.0, 4.0, 4.0, 4.0, 2.0, 2.0, 2.0};
    double a_sq = 2.0;
    Square* sq = new Square(coord_sq, a_sq);
    Figure* _sq = sq;
    figures.add(_sq, 0);

    double coord_rec[8] = {1.0, 4.0, 3.0, 4.0, 3.0, 1.0, 1.0, 1.0};
    double a_rec = 2.0;
    double b_rec = 3.0;
    Rectangle* rec = new Rectangle(coord_rec, a_rec, b_rec);
    Figure* _rec = rec;
    figures.add(_rec, 1);

    double coord_trap[8] = {2.0, 3.0, 4.0, 3.0, 5.0, 1.0, 1.0, 1.0};;
    double h_trap = 2.0;
    double a_trap = 2.0;
    double b_trap = 4.0;
    Trapezoid* trap = new Trapezoid(coord_trap, h_trap, a_trap, b_trap);
    Figure* _trap = trap;
    figures.add(_trap, 2);

    figures.all();
    std::cout << "\n" << "Общая площадь фигур в массиве: " << figures.all_area() << "\n";

    std::cout << "Введите номер фигуры, которую вы хотите удалить: " << "\n";
    int a;
    std::cin >> a;
    figures.del(a);
    std::cout << "\n";
    
    // КВАДРАТ
    Square sq1;
    std::cin >> sq1;
    std::cout << sq1;
    double area1 = static_cast<double>(sq1);
    std::cout << "Площадь квадрата: " << area1 << "\n";
    std::cout << "Координаты геометрического центра квадрата: " << sq1.get_centre_x() << "; " << sq1.get_centre_y() << "\n";

    Square sq2;
    std::cin >> sq2;
    std::cout << sq2;
    double area2 = static_cast<double>(sq2);
    std::cout << "Площадь квадрата: " <<area2 << "\n";
    std::cout << "Координаты геометрического центра квадрата: " << sq2.get_centre_x() << "; " << sq2.get_centre_y() << "\n";

    if (sq1 == sq2){
        std::cout << "Квадраты равны." << "\n";
    } 
    else{
        std::cout << "Квадраты не равны." << "\n";
    }

    // ПРЯМОУГОЛЬНИК
    Rectangle rec1;
    std::cin >> rec1;
    std::cout << rec1;
    double area3 = static_cast<double>(rec1);
    std::cout << "Площадь прямоугольника: " << area3 << "\n";
    std::cout << "Координаты геометрического центра квадрата: " << rec1.get_centre_x() << "; " << rec1.get_centre_y() << "\n";


    Rectangle rec2;
    std::cin >> rec2;
    std::cout << rec2;
    double area4 = static_cast<double>(rec2);
    std::cout << "Площадь прямоугольника: " << area4 << "\n";
    std::cout << "Координаты геометрического центра квадрата: " << rec2.get_centre_x() << "; " << rec2.get_centre_y() << "\n";


    if (rec1 == rec2){
        std::cout << "Прямоугольники равны." << "\n";
    } 
    else{
        std::cout << "Прямоугольники не равны." << "\n";
    }
    
    // ТРАПЕЦИЯ
    Trapezoid trap1;
    std::cin >> trap1;
    std::cout << trap1;
    double area5 = static_cast<double>(trap1);
    std::cout << "Площадь трапеции: " << area5 << "\n";
    std::cout << "Координаты геометрического центра квадрата: " << trap1.get_centre_x() << "; " << trap1.get_centre_y() << "\n";


    Trapezoid trap2;
    std::cin >> trap2;
    std::cout << trap2;
    double area6 = static_cast<double>(trap2);
    std::cout << "Площадь трапеции: " << area6 << "\n";
    std::cout << "Координаты геометрического центра квадрата: " << trap2.get_centre_x() << "; " << sq1.get_centre_y() << "\n";


    if (trap1 == trap2){
        std::cout << "Трапеции равны." << "\n";
    } 
    else{
        std::cout << "Трапеции не равны." << "\n";
    }

    return 0;
}
```
### Figure.h
```cpp
#pragma once
#include<iostream>

class Figure 
{

    friend std::istream& operator>>(std::istream& is, Figure& figure);
    friend std::ostream& operator<<(std::ostream& os, const Figure& figure);

public:

    Figure();
    Figure(double coord[8]);
    Figure(const Figure& other);
    Figure(Figure&& other);
    virtual ~Figure();

    virtual operator double() = 0; // возвращает площадь фигуры
    virtual double get_area() = 0;
    virtual double get_centre_x() = 0;
    virtual double get_centre_y() = 0;

protected:

    double coord[8];
    double area;
    double centre_x;
    double centre_y;

};

inline std::istream& operator>>(std::istream& is, Figure& figure){

    double coord[8];
    std::cout << "Введите координаты вершин фигуры в таком порядке через пробелы: A(x) A(y) B(x) B(y) C(x) C(y) D(x) D(y), где вершины A B C D идут по кругу: " << "\n";
    
    for (int q = 0; q < 8; q++){
        is >> coord[q];
        figure.coord[q] = coord[q];
    }
    std::cout << "Ввод закончен." << "\n";
    return is;
}

inline std::ostream& operator<<(std::ostream& os, const Figure& figure){

    os << "Координаты фигуры:" << "\n"; 
    os << "A: x = " << figure.coord[0] << "; y = " << figure.coord[1] << "\n";
    os << "B: x = " << figure.coord[2] << "; y = " << figure.coord[3] << "\n";
    os << "C: x = " << figure.coord[4] << "; y = " << figure.coord[5] << "\n";
    os << "D: x = " << figure.coord[6] << "; y = " << figure.coord[7] << "\n";

    return os;
}
```
### Figure.cpp
```cpp
#include<iostream>
#include<cmath>
#include"Figure.h"

Figure::Figure()
{
    for (int q = 0; q < 8; q++){
        coord[q] = 0;
    }
}

Figure::Figure(double coord[8])
{
    for (int q = 0; q < 8; q++){
        this->coord[q] = coord[q];
    }
}

Figure::Figure(const Figure& other)
{
    for (int q = 0; q < 8; q++){
        this->coord[q] = other.coord[q];
    }
}

Figure::Figure(Figure&& other)
{
    for (int q = 0; q < 8; q++){
        this->coord[q] = other.coord[q];
        other.coord[q] = 0;
    }
}

Figure::~Figure()
{
    for (int q = 0; q < 8; q++){
        coord[q] = 0;
    }
}
```
### Array.h
```cpp
#pragma once
#include<iostream>
#include"Figure.h"

class Array {
    
private:
    Figure** fig;
    int size;
    int lot;

public:
    Array(int size);
    ~Array();

    void add(Figure* fig, int index);
    void del(int index);
    void all() const;
    double all_area() const;
};
```
### Array.cpp
```cpp
#include<iostream>
#include<cmath>
#include"Array.h"

Array::Array(int size)
{   
    lot = 0;
    this->size = size;
    fig = new Figure*[size];
    for (int q = 0; q < size; q++) {
        fig[q] = nullptr;
    }
}

Array::~Array() 
{
    for (int q = 0; q < size; ++q) {
            if (fig[q] != nullptr) {
                delete fig[q];
            }
        }
        delete[] fig;
}

void Array::add(Figure* figure, int index) 
{
    if (index >= 0 && index < size) {
        if (fig[index] == nullptr){
            ++lot;
            fig[index] = figure;
            std::cout << "Фигура с номером " << index  << " добавлена в массив." << "\n";
            std::cout << "Количество фигур в массиве: " << lot << "\n";
        }
        else{
            std::cout << "Фигура с таким номером уже существует." << "\n";
        }
    }
}

void Array::del(int index) 
{   
    if (index >= 0 && index < size && index < lot) {
        if (fig[index] != nullptr){
            --lot;
            delete fig[index];
            fig[index] = nullptr;
            std::cout << "Фигура с номером " << index << " удалена из массива." << "\n";
            std::cout << "Количество фигур в массиве: " << lot << "\n";
        }
    }
    else{
            std::cout << "Фигуры с таким номером не существует." << "\n";
    }
    
}

void Array::all() const 
{
    int all;
    for (int q = 0; q < size; ++q) {
        if (fig[q] != nullptr) {
            all += fig[q]->get_area();
            std::cout << "Фигура номер: " << q << "\n";
            std::cout << *fig[q];
            std::cout << "Площадь фигуры: " << fig[q]->get_area() << "\n";
            std::cout << "Координаты гометрического центра фигуры: " << fig[q]->get_centre_x() << "; " << fig[q]->get_centre_y() << "\n"; 
            std::cout << "\n";
        }
    }
    std::cout << "Количество фигур в массиве: " << lot << "\n";
}

double Array::all_area() const
{
        double areas = 0;
        for (int q = 0; q < size; q++) {
            areas += fig[q]->get_area();
        }
        return areas;
}
```
### Square.h
```cpp
#pragma once
#include<iostream>
#include"Figure.h"

class Square: public Figure 
{

    friend std::istream& operator>>(std::istream& is, Square& square);
    friend std::ostream& operator<<(std::ostream& os, const Square& square);

public:

    Square();
    Square(double coord[8], double& diag);
    Square(const Square& other);
    Square(Square&& other);
    ~Square();

    virtual operator double() override; 
    virtual double get_area() override;
    virtual double get_centre_x() override;
    virtual double get_centre_y() override;

    Square& operator=(const Square& other);
    Square& operator=(Square&& other);
    bool operator==(const Square& other) const;

protected:

    double a;

};

inline std::istream& operator>>(std::istream& is, Square& square){

    double coord[8];
    std::cout << "Введите координаты вершин квадрата в таком порядке через пробелы: A(x) A(y) B(x) B(y) C(x) C(y) D(x) D(y), где вершины A B C D идут по кругу: " << "\n";
    
    for (int q = 0; q < 8; q++){
        is >> coord[q];
        square.coord[q] = coord[q];
    }
    std::cout << "Введите длину стороны квадрата: " << "\n";
    is >> square.a;
    std::cout << "Ввод закончен." << "\n";

    return is;
}

inline std::ostream& operator<<(std::ostream& os, const Square& square){

    os << "Координаты квадрата:" << "\n"; 
    os << "A: x = " << square.coord[0] << "; y = " << square.coord[1] << "\n";
    os << "B: x = " << square.coord[2] << "; y = " << square.coord[3] << "\n";
    os << "C: x = " << square.coord[4] << "; y = " << square.coord[5] << "\n";
    os << "D: x = " << square.coord[6] << "; y = " << square.coord[7] << "\n";
    os << "Длина стороны квадрата квадрата: " << square.a << "\n";

    return os;
}
```
### Square.cpp
```cpp
#include<iostream>
#include<cmath>
#include"Square.h"

Square::Square(): Figure()
{
    a = 0;
}
    
Square::Square(double coord[8], double& a): Figure(coord)
{
    this->a = a;
}

Square::Square(const Square& other): Figure(coord)
{
    this->a = other.a;
}

Square::Square(Square&& other): Figure(coord)
{
    this->a = other.a;
    other.a = 0;
}

Square::~Square()
{
    a = 0;
}

///////////////////////////////////////////////////
Square::operator double()
{   
    area = pow(a,2);
    return area;
} 

double Square:: get_area()
{
    area = pow(a,2);
    return area;
}

double Square::get_centre_x()
{
    centre_x = (coord[0]+coord[2]+coord[4]+coord[6]) / 4;
    return centre_x;
}

double Square::get_centre_y()
{
    centre_y = (coord[1]+coord[3]+coord[5]+coord[7]) / 4;
    return centre_y;
}

Square& Square::operator=(const Square& other)
{
    if (this != &other){
    	// delete[] coord (указатель на динамический массив с координатами)
        // this->size = other.size; (размер массива)
        // coord = new double[size];
        for (int q = 0; q < 8; q++){
            this->coord[q] = other.coord[q];
        }
        this->a = other.a;
    }
    return *this;
}

Square& Square::operator=(Square&& other)
{
    if (this != &other){
    	// delete[] coord (указатель на динамический массив с координатами)
        // this->size = other.size; (размер массива)
        // coord = new double[size];
        for (int q = 0; q < 8; q++){
            this->coord[q] = other.coord[q];
            other.coord[q] = 0;
        }
        this->a = other.a;
        other.a = 0;
    }
    return *this;
}

bool Square::operator==(const Square& other) const
{
    if (this->a != other.a){
        return false;
    }
    return true;
}
```
### Rectangle.h
```cpp
#pragma once
#include<iostream>
#include"Figure.h"

class Rectangle: public Figure 
{

    friend std::istream& operator>>(std::istream& is, Rectangle& rect);
    friend std::ostream& operator<<(std::ostream& os, const Rectangle& rect);

public:

    Rectangle();
    Rectangle(double coord[8], double& a, double& b);
    Rectangle(const Rectangle& other);
    Rectangle(Rectangle&& other);
    ~Rectangle();

    virtual operator double() override;
    virtual double get_area() override;
    virtual double get_centre_x() override;
    virtual double get_centre_y() override;
    
    Rectangle& operator=(const Rectangle& other);
    Rectangle& operator=(Rectangle&& other);
    bool operator==(const Rectangle& other) const;

protected:

    double a;
    double b;

};

inline std::istream& operator>>(std::istream& is, Rectangle& rect){

    double coord[8];
    std::cout << "Введите координаты вершин прямоугольника в таком порядке через пробелы: A(x) A(y) B(x) B(y) C(x) C(y) D(x) D(y), где вершины A B C D идут по кругу: " << "\n";
    
    for (int q = 0; q < 8; q++){
        is >> coord[q];
        rect.coord[q] = coord[q];
    }
    std::cout << "Введите длины сторон через пробел, сначала меньшую, затем большую: " << "\n";
    is >> rect.a >> rect.b;
    std::cout << "Ввод закончен." << "\n";

    return is;
}

inline std::ostream& operator<<(std::ostream& os, const Rectangle& rect){

    os << "Координаты прямоугольника:" << "\n"; 
    os << "A: x = " << rect.coord[0] << "; y = " << rect.coord[1] << "\n";
    os << "B: x = " << rect.coord[2] << "; y = " << rect.coord[3] << "\n";
    os << "C: x = " << rect.coord[4] << "; y = " << rect.coord[5] << "\n";
    os << "D: x = " << rect.coord[6] << "; y = " << rect.coord[7] << "\n";
    os << "Длины сторон прямоугольника: " << rect.a << "; " << rect.b << "\n";

    return os;
}
```
### Rectangle.cpp
```cpp
#include<iostream>
#include<cmath>
#include"Rectangle.h"

Rectangle::Rectangle(): Figure()
{
    a = 0;
    b = 0;
}

Rectangle::Rectangle(double coord[8], double& a, double& b): Figure(coord)
{
    this->a = a;
    this->b = b;
}

Rectangle::Rectangle(const Rectangle& other): Figure(coord)
{
    this->a = other.a;
    this->b = other.b;
}

Rectangle::Rectangle(Rectangle&& other): Figure(coord)
{
    this->a = other.a;
    other.a = 0;
    this->b = other.b;
    other.b = 0;
}

Rectangle::~Rectangle()
{
    a = 0;
    b = 0;
}

///////////////////////////////////////////////////
Rectangle::operator double()
{   
    area = a * b;
    return area;
} 

double Rectangle:: get_area()
{
    area = a * b;
    return area;
}

double Rectangle::get_centre_x()
{
    centre_x = (coord[0]+coord[2]+coord[4]+coord[6]) / 4;
    return centre_x;
}

double Rectangle::get_centre_y()
{
    centre_y = (coord[1]+coord[3]+coord[5]+coord[7]) / 4;
    return centre_y;
}

Rectangle& Rectangle::operator=(const Rectangle& other)
{
    if (this != &other){
    	// delete[] coord (указатель на динамический массив с координатами)
        // this->size = other.size; (размер массива)
        // coord = new double[size];
        for (int q = 0; q < 8; q++){
            this->coord[q] = other.coord[q];
        }
        this->a = other.a;
        this->b = other.b;
    }
    return *this;
}

Rectangle& Rectangle::operator=(Rectangle&& other)
{
    if (this != &other){
    	// delete[] coord (указатель на динамический массив с координатами)
        // this->size = other.size; (размер массива)
        // coord = new double[size];
        for (int q = 0; q < 8; q++){
            this->coord[q] = other.coord[q];
            other.coord[q] = 0;
        }
        this->a = other.a;
         other.a = 0;
        this->b = other.b;
        other.b = 0;
    }
    return *this;
}

bool Rectangle::operator==(const Rectangle& other) const
{
    if (this->a != other.a || this->b != other.b){
        return false;
    }
    return true;
}
```
### Trapezoid.h
```cpp
#pragma once
#include<iostream>
#include"Figure.h"

class Trapezoid: public Figure 
{

    friend std::istream& operator>>(std::istream& is, Trapezoid& trap);
    friend std::ostream& operator<<(std::ostream& os, const Trapezoid& trap);

public:

    Trapezoid();
    Trapezoid(double coord[8],double& high, double& AB, double& CD);
    Trapezoid(const Trapezoid& other);
    Trapezoid(Trapezoid&& other);
    ~Trapezoid();

    virtual operator double() override;
    virtual double get_area() override;
    virtual double get_centre_x() override;
    virtual double get_centre_y() override;

    Trapezoid& operator=(const Trapezoid& other);
    Trapezoid& operator=(Trapezoid&& other);
    bool operator==(const Trapezoid& other) const;

protected:

    double high;
    double AB;
    double CD;

};

inline std::istream& operator>>(std::istream& is, Trapezoid& trap){

    double coord[8];
    std::cout << "Введите координаты вершин трапеции в таком порядке через пробелы: A(x) A(y) B(x) B(y) C(x) C(y) D(x) D(y), где вершины A B C D идут по кругу: " << "\n";
    
    for (int q = 0; q < 8; q++){
        is >> coord[q];
        trap.coord[q] = coord[q];
    }
    std::cout << "Введите высоту трапеции: " << "\n";
    is >> trap.high;
    std::cout << "Введите длины оснований трапеции через пробел, сначала меньшую, затем большую: " << "\n";
    is >> trap.AB >> trap.CD;
    std::cout << "Ввод закончен." << "\n";

    return is;
}

inline std::ostream& operator<<(std::ostream& os, const Trapezoid& trap){

    os << "Координаты трапеции:" << "\n"; 
    os << "A: x = " << trap.coord[0] << "; y = " << trap.coord[1] << "\n";
    os << "B: x = " << trap.coord[2] << "; y = " << trap.coord[3] << "\n";
    os << "C: x = " << trap.coord[4] << "; y = " << trap.coord[5] << "\n";
    os << "D: x = " << trap.coord[6] << "; y = " << trap.coord[7] << "\n";
    os << "Высота трапеции: " << trap.high << "\n";
    os << "Длины оснований трапеции: " << trap.AB << "; " << trap.CD << "\n";

    return os;
}
```
### Trapezoid.cpp
```cpp
#include<iostream>
#include<cmath>
#include"Trapezoid.h"

Trapezoid::Trapezoid(): Figure()
{
    high = 0;
    AB = 0;
    CD = 0;
}

Trapezoid::Trapezoid(double coord[8],double& high, double& AB, double& CD): Figure(coord)
{
    this->high = high;
    this->AB = AB;
    this->CD = CD;
}

Trapezoid::Trapezoid(const Trapezoid& other): Figure(coord)
{
    this->high = other.high;
    this->AB = other.AB;
    this->CD = other.CD;
}

Trapezoid::Trapezoid(Trapezoid&& other): Figure(coord)
{
    this->high = other.high;
    other.high = 0;
    this->AB = other.AB;
    other.AB = 0;
    this->high = other.high;
    other.high = 0;

}

Trapezoid::~Trapezoid()
{
    AB = 0;
    CD = 0;
    high = 0;
}
/////////////////////////////////////////////////
Trapezoid::operator double()
{   
    area = (AB + CD) * high / 2;
    return area;
} 

double Trapezoid:: get_area()
{
    area = (AB + CD) * high / 2;
    return area;
}

double Trapezoid::get_centre_x()
{
    centre_x = (coord[0]+coord[2]+coord[4]+coord[6]) / 4;
    return centre_x;
}

double Trapezoid::get_centre_y()
{
    centre_y = (coord[1]+coord[3]+coord[5]+coord[7]) / 4;
    return centre_y;
}

Trapezoid& Trapezoid::operator=(const Trapezoid& other)
{
    if (this != &other){
    	// delete[] coord (указатель на динамический массив с координатами)
        // this->size = other.size; (размер массива)
        // coord = new double[size];
        for (int q = 0; q < 8; q++){
            this->coord[q] = other.coord[q];
        }
        this->AB = other.AB;
        this->CD = other.CD;
        this->high = other.high;
    }
    return *this;
}

Trapezoid& Trapezoid::operator=(Trapezoid&& other)
{
    if (this != &other){
    	// delete[] coord (указатель на динамический массив с координатами)
        // this->size = other.size; (размер массива)
        // coord = new double[size];
        for (int q = 0; q < 8; q++){
            this->coord[q] = other.coord[q];
            other.coord[q] = 0;
        }
        this->AB = other.AB;
        other.AB = 0;
        this->CD = other.CD;
        other.CD = 0;
        this->high = other.high;
        other.high = 0;
    }
    return *this;
}

bool Trapezoid::operator==(const Trapezoid& other) const
{
    if (this->AB != other.AB || this->CD != other.CD || this->high != other.high){
        return false;
    }
    return true;
}
```
### Tests.cpp
```cpp
#include <gtest/gtest.h>
#include"Figure.h"
#include"Square.h"
#include"Rectangle.h"
#include"Trapezoid.h"

TEST(test_1, AllMetods)
{   
// квадрат
    double coord_sq1[8] = {2.0, 4.0, 4.0, 4.0, 4.0, 2.0, 2.0, 2.0};
    double a_sq1 = 2.0;
    Square sq1(coord_sq1, a_sq1);

    double coord_sq2[8] = {-2.0, 2.0, 0.0, 2.0, 0.0, 0.0, -2.0, 0.0};
    double a_sq2 = 2.0;
    Square sq2(coord_sq2, a_sq2);

    double area1 = static_cast<double>(sq1);
    double expect_area1 = 4;
    double area2 = static_cast<double>(sq2);
    double expect_area2 = 4;

    double get_area1 = sq1.get_area();
    double expect_get_area1 = 4;
    double get_area2 = sq2.get_area();
    double expect_get_area2 = 4;

    double centre_x1 = sq1.get_centre_x();
    double expect_centre_x1 = 3;
    double centre_x2 = sq2.get_centre_x();
    double expect_centre_x2 = -1;

    double centre_y1 = sq1.get_centre_y();
    double expect_centre_y1 = 3;
    double centre_y2 = sq2.get_centre_y();
    double expect_centre_y2 = 1;

// проверка
    ASSERT_EQ(area1, expect_area1);
    ASSERT_EQ(area2, expect_area2);

    ASSERT_EQ(get_area1, expect_get_area1);
    ASSERT_EQ(get_area2, expect_get_area2);

    ASSERT_EQ(centre_x1, expect_centre_x1);
    ASSERT_EQ(centre_x2, expect_centre_x2);

    ASSERT_EQ(centre_y1, expect_centre_y1);
    ASSERT_EQ(centre_y2, expect_centre_y2);

    EXPECT_TRUE(sq1 == sq2);

}

TEST(test_2, AllMetods)
{   
// прямоугольник
    double coord_rec1[8] = {1.0, 4.0, 3.0, 4.0, 3.0, 1.0, 1.0, 1.0};
    double a_rec1 = 2.0;
    double b_rec1 = 3.0;
    Rectangle rec1(coord_rec1, a_rec1, b_rec1);

    double coord_rec2[8] = {1.0, 1.0, 2.0, 1.0, 2.0, -1.0, 1.0, -1.0};
    double a_rec2 = 1.0;
    double b_rec2 = 2.0;
    Rectangle rec2(coord_rec2, a_rec2, b_rec2);

    double area1 = static_cast<double>(rec1);
    double expect_area1 = 6;
    double area2 = static_cast<double>(rec2);
    double expect_area2 = 2;

    double get_area1 = rec1.get_area();
    double expect_get_area1 = 6;
    double get_area2 = rec2.get_area();
    double expect_get_area2 = 2;

    double centre_x1 = rec1.get_centre_x();
    double expect_centre_x1 = 2.0;
    double centre_x2 = rec2.get_centre_x();
    double expect_centre_x2 = 1.5;

    double centre_y1 = rec1.get_centre_y();
    double expect_centre_y1 = 2.5;
    double centre_y2 = rec2.get_centre_y();
    double expect_centre_y2 = 0;

// проверка
    ASSERT_EQ(area1, expect_area1);
    ASSERT_EQ(area2, expect_area2);

    ASSERT_EQ(get_area1, expect_get_area1);
    ASSERT_EQ(get_area2, expect_get_area2);

    ASSERT_EQ(centre_x1, expect_centre_x1);
    ASSERT_EQ(centre_x2, expect_centre_x2);

    ASSERT_EQ(centre_y1, expect_centre_y1);
    ASSERT_EQ(centre_y2, expect_centre_y2);

    EXPECT_FALSE(rec1 == rec2);

}

TEST(test_3, AllMetods)
{   
// трапеция
    double coord_trap1[8] = {2.0, 3.0, 4.0, 3.0, 5.0, 1.0, 1.0, 1.0};
    double high_trap1 = 2.0;
    double AB_trap1 = 2.0;
    double CD_trap1 = 4.0;
    Trapezoid trap1(coord_trap1, high_trap1, AB_trap1, CD_trap1);

    double coord_trap2[8] = {3.0, -1.0, 4.0, -1.0, 6.0, -3.0, 1.0, -3.0};
    double high_trap2 = 2.0;
    double AB_trap2 = 1.0;
    double CD_trap2 = 5.0;
    Trapezoid trap2(coord_trap2, high_trap2, AB_trap2, CD_trap2);

    double area1 = static_cast<double>(trap1);
    double expect_area1 = 6;
    double area2 = static_cast<double>(trap2);
    double expect_area2 = 6;

    double get_area1 = trap1.get_area();
    double expect_get_area1 = 6;
    double get_area2 = trap2.get_area();
    double expect_get_area2 = 6;

    double centre_x1 = trap1.get_centre_x();
    double expect_centre_x1 = 3.0;
    double centre_x2 = trap2.get_centre_x();
    double expect_centre_x2 = 3.5;

    double centre_y1 = trap1.get_centre_y();
    double expect_centre_y1 = 2.0;
    double centre_y2 = trap2.get_centre_y();
    double expect_centre_y2 = -2;

// проверка
    ASSERT_EQ(area1, expect_area1);
    ASSERT_EQ(area2, expect_area2);

    ASSERT_EQ(get_area1, expect_get_area1);
    ASSERT_EQ(get_area2, expect_get_area2);

    ASSERT_EQ(centre_x1, expect_centre_x1);
    ASSERT_EQ(centre_x2, expect_centre_x2);

    ASSERT_EQ(centre_y1, expect_centre_y1);
    ASSERT_EQ(centre_y2, expect_centre_y2);

    EXPECT_FALSE(trap1 == trap2);

}

TEST(test_4, COPY)
{   
// квадрат
    double coord_sq1[8] = {2.0, 4.0, 4.0, 4.0, 4.0, 2.0, 2.0, 2.0};
    double a_sq1 = 2.0;
    Square sq1(coord_sq1, a_sq1);

    double coord_sq2[8] = {-2.0, 2.0, 0.0, 2.0, 0.0, 0.0, -2.0, 0.0};
    double a_sq2 = 2.0;
    Square sq2(coord_sq2, a_sq2);

    sq2 = sq1;

// прямоугольник
    double coord_rec1[8] = {1.0, 4.0, 3.0, 4.0, 3.0, 1.0, 1.0, 1.0};
    double a_rec1 = 2.0;
    double b_rec1 = 3.0;
    Rectangle rec1(coord_rec1, a_rec1, b_rec1);

    double coord_rec2[8] = {1.0, 1.0, 2.0, 1.0, 2.0, -1.0, 1.0, -1.0};
    double a_rec2 = 1.0;
    double b_rec2 = 2.0;
    Rectangle rec2(coord_rec2, a_rec2, b_rec2);

    rec2 = rec1;

// трапеция
    double coord_trap1[8] = {2.0, 3.0, 4.0, 3.0, 5.0, 1.0, 1.0, 1.0};
    double high_trap1 = 2.0;
    double AB_trap1 = 2.0;
    double CD_trap1 = 4.0;
    Trapezoid trap1(coord_trap1, high_trap1, AB_trap1, CD_trap1);

    double coord_trap2[8] = {3.0, -1.0, 4.0, -1.0, 6.0, -3.0, 1.0, -3.0};
    double high_trap2 = 2.0;
    double AB_trap2 = 1.0;
    double CD_trap2 = 5.0;
    Trapezoid trap2(coord_trap2, high_trap2, AB_trap2, CD_trap2);

    trap2 = trap1;

// проверка
    EXPECT_EQ(sq1, Square(coord_sq1, a_sq1));
    EXPECT_EQ(rec1, Rectangle(coord_rec1, a_rec1, b_rec1));
    EXPECT_EQ(trap1, Trapezoid(coord_trap1, high_trap1, AB_trap1, CD_trap1));

    EXPECT_EQ(sq2, Square(coord_sq1, a_sq1));
    EXPECT_EQ(rec2, Rectangle(coord_rec1, a_rec1, b_rec1));
    EXPECT_EQ(trap2, Trapezoid(coord_trap1, high_trap1, AB_trap1, CD_trap1));
}

TEST(test_5, Move)
{   
// квадрат
    double coord_sq1[8] = {2.0, 4.0, 4.0, 4.0, 4.0, 2.0, 2.0, 2.0};
    double a_sq1 = 2.0;
    Square sq1(coord_sq1, a_sq1);

    double coord_sq2[8] = {-2.0, 2.0, 0.0, 2.0, 0.0, 0.0, -2.0, 0.0};
    double a_sq2 = 2.0;
    Square sq2(coord_sq2, a_sq2);

    sq2 = std::move (sq1);

// прямоугольник
    double coord_rec1[8] = {1.0, 4.0, 3.0, 4.0, 3.0, 1.0, 1.0, 1.0};
    double a_rec1 = 2.0;
    double b_rec1 = 3.0;
    Rectangle rec1(coord_rec1, a_rec1, b_rec1);

    double coord_rec2[8] = {1.0, 1.0, 2.0, 1.0, 2.0, -1.0, 1.0, -1.0};
    double a_rec2 = 1.0;
    double b_rec2 = 2.0;
    Rectangle rec2(coord_rec2, a_rec2, b_rec2);

    rec2 = std::move (rec1);

// трапеция
    double coord_trap1[8] = {2.0, 3.0, 4.0, 3.0, 5.0, 1.0, 1.0, 1.0};
    double high_trap1 = 2.0;
    double AB_trap1 = 2.0;
    double CD_trap1 = 4.0;
    Trapezoid trap1(coord_trap1, high_trap1, AB_trap1, CD_trap1);

    double coord_trap2[8] = {3.0, -1.0, 4.0, -1.0, 6.0, -3.0, 1.0, -3.0};
    double high_trap2 = 2.0;
    double AB_trap2 = 1.0;
    double CD_trap2 = 5.0;
    Trapezoid trap2(coord_trap2, high_trap2, AB_trap2, CD_trap2);

    trap2 = std::move (trap1);


    double coord[8] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    double a = 0.0;

// проверка
    EXPECT_EQ(sq1, Square(coord, a));
    EXPECT_EQ(rec1, Rectangle(coord, a, a));
    EXPECT_EQ(trap1, Trapezoid(coord, a, a, a));

    EXPECT_EQ(sq2, Square(coord_sq1, a_sq1));
    EXPECT_EQ(rec2, Rectangle(coord_rec1, a_rec1, b_rec1));
    EXPECT_EQ(trap2, Trapezoid(coord_trap1, high_trap1, AB_trap1, CD_trap1));
}
```
