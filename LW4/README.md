# Лабораторная 4
# Кайдалова Александра, М8О-212Б-22, Вариант 10
## Тема: Основы метапрограммирования
### Цель: 
    1. Изучение основ работы с шаблонами (template) в С++;
    2. Изучение шаблонов умных указателей
#### Требования к программе:
Разработать шаблоны классов согласно варианту задания. Параметром шаблона должен
являться скалярный тип данных задающий тип данных для оси координат. Классы должны иметь
только публичные поля. В классах не должно быть методов, только поля. Фигуры являются
фигурами вращения (равнобедренными), за исключением трапеции и прямоугольника. Для
хранения координат фигур необходимо использовать шаблон std::pair (или реализовать свой
шаблон template <class T> Point в качестве параметра шаблона должен быть тип для переменных
координат)
Например:
template <class T>
struct Square{
using vertex_t = std::pair<T,T>;
vertex_t a,b,c,d;
};

Разработать классы согласно варианту задания, классы должны наследоваться от базового
класса Figure. Фигуры являются фигурами вращения. Все классы должны поддерживать набор
общих методов:
    1. Вычисление геометрического центра фигуры вращения;
    2. Вывод в стандартный поток вывода std::cout координат вершин фигуры;
    3. Вычисление площади фигуры;
Создать программу, которая позволяет:
    • Запрещается использовать сырые указатели
    • Вводить из стандартного ввода std::cin фигуры, согласно варианту задания.
    • Сохранять созданные фигуры в динамический массив (переиспользовать от
предыдущей лабораторной работы) умных указатели на фигуру
(std::smart_ptr<Figure*>)
    • Динамический массив должен быть сделан в виде шаблона (параметр шаблона – класс
для хранения в массиве template <class T> Array {...})
    • Фигуры должны иметь переопределенные операции копирования, сравнения и
приведение к типу double (вычисление площади)
    • Вызывать для всего массива общие функции (1-3 см. выше).Т.е. распечатывать для
каждой фигуры в массиве геометрический центр, координаты вершин и площадь.
    • Необходимо уметь вычислять общую площадь фигур в массиве.
    • Удалять из массива фигуру по индексу;
#### Вариант 10: 
Фигура №1 - Квадрат;
Фигура №2 - Прямоугольник;
Фигура №3 - Трапеция.
#### Main.cpp
```cpp
#include<iostream>
#include<utility>
#include<memory>
#include"Figure.h"
#include"Square.h"
#include"Rectangle.h"
#include"Trapezoid.h"
#include"Array.h"

int main(){   

    Array<std::shared_ptr<Figure<double>>> array(3);

    std::pair<double, double> coord_sq[4] = {{2.0, 4.0}, {4.0, 4.0}, {4.0, 2.0}, {2.0, 2.0}};
    double a_sq = 2.0;  
    std::shared_ptr<Square<double>> sq = std::make_shared<Square<double>>(coord_sq, a_sq);
    array.add(sq, 0);

    std::pair<double, double> coord_rec[4] = {{1.0, 4.0}, {3.0, 4.0}, {3.0, 1.0}, {1.0, 1.0}};
    double a_rec = 2.0;
    double b_rec = 3.0;
    std::shared_ptr<Rectangle<double>> rec = std::make_shared<Rectangle<double>>(coord_rec, a_rec, b_rec);
    array.add(rec, 1);
    
    std::pair<double, double> coord_trap[4] = {{2.0, 3.0}, {4.0, 3.0}, {5.0, 1.0}, {1.0, 1.0}};
    double high_trap = 2.0;
    double AB_trap = 2.0;
    double CD_trap = 4.0;
    std::shared_ptr<Trapezoid<double>> trap = std::make_shared<Trapezoid<double>>(coord_trap, AB_trap, CD_trap, high_trap);
    array.add(trap, 2);

    array.all();
    std::cout << "\n" << "Общая площадь фигур в массиве: " << array.all_area() << "\n" << "\n";

    std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||| " << "\n";
    std::cout << "Введите номер фигуры, которую вы хотите удалить: " << "\n";
    int a;
    std::cin >> a;
    array.del(a);
    std::cout << "Фигуры в массиве:" << "\n";
    array.all();
    std::cout << "\n" << "Общая площадь фигур в массиве: " << array.all_area() << "\n";


    // КВАДРАТ
    Square<int> sq1;
    std::cin >> sq1;
    std::cout << sq1;
    std::cout << "Площадь квадрата: " << sq1.get_area() << "\n";
    std::pair<int, int> centre1 = sq1.get_centre();
    std::cout << "Координаты геометрического центра квадрата: " << centre1.first << "; " << centre1.second << "\n";

    Square<int> sq2;
    std::cin >> sq2;
    std::cout << sq2;
    std::cout << "Площадь квадрата: " << sq2.get_area() << "\n";
    std::pair<int, int> centre2 = sq2.get_centre();
    std::cout << "Координаты геометрического центра квадрата: " << centre2.first << "; " << centre2.second << "\n";

    if (sq1 == sq2){
        std::cout << "Квадраты равны." << "\n";
    } 
    else{
        std::cout << "Квадраты не равны." << "\n";
    }

    // ПРЯМОУГОЛЬНИК
    Rectangle<double> rec1;
    std::cin >> rec1;
    std::cout << rec1;
    std::cout << "Площадь прямоугольника: " << rec1.get_area() << "\n";
    std::pair<double, double> centre3 = rec1.get_centre();
    std::cout << "Координаты геометрического центра прямоугольника: " << centre3.first << "; " << centre3.second << "\n";

    Rectangle<double> rec2;
    std::cin >> rec2;
    std::cout << rec2;
    std::cout << "Площадь прямоугольника: " << rec2.get_area() << "\n";
    std::pair<double, double> centre4 = rec2.get_centre();
    std::cout << "Координаты геометрического центра прямоугольника: " << centre4.first << "; " << centre4.second << "\n";

    if (rec1 == rec2){
        std::cout << "Прямоугольники равны." << "\n";
    } 
    else{
        std::cout << "Прямоугольники не равны." << "\n";
    }
    
    // ТРАПЕЦИЯ
    Trapezoid<float> trap1;
    std::cin >> trap1;
    std::cout << trap1;
    std::cout << "Площадь трапеции: " << trap1.get_area() << "\n";
    std::pair<float, float> centre5 = trap1.get_centre();
    std::cout << "Координаты геометрического центра прямоугольника: " << centre5.first << "; " << centre5.second << "\n";

    Trapezoid<float> trap2;
    std::cin >> trap2;
    std::cout << trap2;
    std::cout << "Площадь трапеции: " << trap2.get_area() << "\n";
    std::pair<float, float> centre6 = trap2.get_centre();
    std::cout << "Координаты геометрического центра прямоугольника: " << centre6.first << "; " << centre6.second << "\n";

    if (trap1 == trap2){
        std::cout << "Трапеции равны." << "\n";
    } 
    else{
        std::cout << "Трапеции не равны." << "\n";
    }

    return 0;
}
```
#### Array.h
```cpp
#pragma once
#include<iostream>
#include<utility>
#include <memory>
#include"Figure.h"

template <typename Ary>
class Array {
public:
    Array(int size){
        lot = 0;
        this->size = size;
        array = std::shared_ptr<Ary[]>(new Ary[size]);
        for (int q = 0; q < size; q++) {
            array[q] = nullptr;
        }
    }

    ~Array(){
        size = 0;
        areas = 0;
        lot = 0;
    }

    void add(Ary figure, int index){
        if (index >= 0 && index < size) {
            if (array[index] == nullptr){
                ++lot;
                array[index] = figure;
                std::cout << "Фигура с номером " << index  << " добавлена в массив." << "\n";
                std::cout << "Количество фигур в массиве: " << lot << "\n";
            }
            else{
                std::cout << "Фигура с таким номером уже существует." << "\n";
            }
        }
    }

    void del(int index){
        if (index >= 0 && index < size && index < lot){
            if (array[index] != nullptr){
                --lot;
                array[index].reset();
                array[index] = nullptr;
                std::cout << "Фигура с номером " << index << " удалена из массива." << "\n";
                std::cout << "Осталось фигур в массиве: " << lot << "\n";
            }
        }
        else{
            std::cout << "Фигуры с таким номером не существует." << "\n";
        }
    }

    void all() const{
        int all = 0;
        for (int q = 0; q < size; ++q) {
            if (array[q] != nullptr) {
                all += array[q]->get_area();
                std::cout << "Фигура номер: " << q << "\n";
                std::cout << *array[q];
                std::cout << "Площадь фигуры: " << array[q]->get_area() << "\n";
                std::pair<double, double> centre = array[q]->get_centre();
                std::cout << "Координаты гометрического центра фигуры: " << centre.first << "; " << centre.second << "\n";
                std::cout << "\n";
            }
        }
        std::cout << "Количество фигур в массиве: " << lot << "\n";
    }

        
    double all_area() const{
        double areas = 0;
        for (int q = 0; q < size; q++){
            if (array[q] != nullptr){
                areas += array[q]->get_area();
            }
        }
        return areas;
    }

private:
    int size;
    int areas;
    int lot;
    std::shared_ptr<Ary[]> array;
};
```
#### Figure.h
```cpp
#pragma once
#include<iostream>
#include<utility>

template <typename Fig>
class Figure 
{
    template <typename T>
    friend std::istream& operator>>(std::istream& is, Figure<T>& figure);
    template <typename T>
    friend std::ostream& operator<<(std::ostream& os, const Figure<T>& figure);

public:

    Figure(){
    for (int q = 0; q < 4; q++){
        coord[q].first = 0;
        coord[q].second = 0;
        }
    }

    Figure(std::pair<Fig, Fig> coord[4]){
     for (int q = 0; q < 4; q++){
        this->coord[q].first = coord[q].first;
        this->coord[q].second = coord[q].second;
        }
    } 

    Figure(const Figure<Fig>& other){
    for (int q = 0; q < 4; q++){
        this->coord[q].first = other.coord[q].first;
        this->coord[q].second = other.coord[q].second;
        }
    }

    Figure(Figure<Fig>&& other){
    for (int q = 0; q < 4; q++){
        this->coord[q].first = other.coord[q].first;
        other.coord[q].first = 0;
        this->coord[q].second = other.coord[q].second;
        other.coord[q].second = 0;
        }
    }

    ~Figure(){
    for (int q = 0; q < 4; q++){
        coord[q].first = 0;
        coord[q].second = 0;
        }
    }

    virtual Fig get_area() = 0;
    std::pair<Fig, Fig> get_centre(){
        this->centre.first = (this->coord[0].first + this->coord[1].first + this->coord[2].first + this->coord[3].first) / 4;
        this->centre.second = (this->coord[0].second + this->coord[1].second + this->coord[2].second + this->coord[3].second) / 4;
        return this->centre;
    }


    std::pair<Fig, Fig> coord[4];
    Fig area;
    std::pair<Fig, Fig> centre;

};

template <typename T>
inline std::istream& operator>>(std::istream& is, Figure<T>& figure){

    std::cout << "Введите координаты вершин фигуры в таком порядке через пробелы: A(x) A(y) B(x) B(y) C(x) C(y) D(x) D(y), где вершины A B C D идут по кругу: " << "\n";
    
    for (int q = 0; q < 4; q++){
        is >> figure.coord[q].first >> figure.coord[q].second;
    }
    std::cout << "Ввод закончен." << "\n";
    return is;
}

template <typename T>
inline std::ostream& operator<<(std::ostream& os, const Figure<T>& figure){

    os << "Координаты фигуры:" << "\n"; 
    os << "A: x = " << figure.coord[0].first << "; y = " << figure.coord[0].second << "\n";
    os << "B: x = " << figure.coord[1].first << "; y = " << figure.coord[1].second << "\n";
    os << "C: x = " << figure.coord[2].first << "; y = " << figure.coord[2].second << "\n";
    os << "D: x = " << figure.coord[3].first << "; y = " << figure.coord[3].second << "\n";

    return os;
}
```
#### Square.h
```cpp
#pragma once
#include<iostream>
#include<cmath>
#include"Figure.h"

template <typename Sq>
class Square: public Figure<Sq>
{
    template <typename T>
    friend std::istream& operator>>(std::istream& is, Square<T>& square);
    template <typename T>
    friend std::ostream& operator<<(std::ostream& os, const Square<T>& square);

public:

    Square(): Figure<Sq>(){
        a = 0;
    }

    Square(std::pair<Sq, Sq> coord[4], Sq& a): Figure<Sq>(coord){
        this->a = a;
    }

    Square(const Square& other): Figure<Sq>(other){
        this->a = other.a;
    }

    Square(Square&& other): Figure<Sq>(std::move(other)){
        this->a = other.a;
        other.a = 0;
    }

    ~Square(){
        a = 0;
    }


    virtual Sq get_area() override{
        this->area = pow(a,2);
        return (this->area);
    }


    Square<Sq>& operator=(const Square<Sq>& other){
        if (this != &other){
            for (int q = 0; q < 4; q++){
                this->coord[q] = other.coord[q];
            }
            this->a = other.a;
        }
        return *this;
    }

    Square<Sq>& operator=(Square<Sq>&& other){
        if (this != &other){
            for (int q = 0; q < 4; q++){
                this->coord[q] = other.coord[q];
                other.coord[q] = {0, 0};
            }
            this->a = other.a;
            other.a = 0;
        }
        return *this;
    }

    bool operator==(const Square<Sq>& other) const{
        if (this->a != other.a){
            return false;
        }
        return true;
    }


    Sq a;

};

template <typename T>
inline std::istream& operator>>(std::istream& is, Square<T>& square){

    std::cout << "Введите координаты вершин квадрата в таком порядке через пробелы: A(x) A(y) B(x) B(y) C(x) C(y) D(x) D(y), где вершины A B C D идут по кругу: " << "\n";
    
    for (int q = 0; q < 4; q++){
        is >> square.coord[q].first >> square.coord[q].second;
    }
    std::cout << "Введите длину стороны квадрата: " << "\n";
    is >> square.a;
    std::cout << "Ввод закончен." << "\n";

    return is;
}

template <typename T>
inline std::ostream& operator<<(std::ostream& os, const Square<T>& square){

    os << "Координаты квадрата:" << "\n"; 
    os << "A: x = " << square.coord[0].first << "; y = " << square.coord[0].second << "\n";
    os << "B: x = " << square.coord[1].first << "; y = " << square.coord[1].second << "\n";
    os << "C: x = " << square.coord[2].first << "; y = " << square.coord[2].second << "\n";
    os << "D: x = " << square.coord[3].first << "; y = " << square.coord[3].second << "\n";
    os << "Длина стороны квадрата квадрата: " << square.a << "\n";

    return os;
}
```
#### Rectangle.h
```cpp
#pragma once
#include<iostream>
#include"Figure.h"

template <typename Rec>
class Rectangle: public Figure<Rec>
{

    template <typename T>
    friend std::istream& operator>>(std::istream& is, Rectangle<T>& rect);
    template <typename T>
    friend std::ostream& operator<<(std::ostream& os, const Rectangle<T>& rect);

public:

    Rectangle(): Figure<Rec>(){
        a = 0;
        b = 0;
    }

    Rectangle(std::pair<Rec, Rec> coord[4], Rec& a, Rec& b): Figure<Rec>(coord){
        this->a = a;
        this->b = b;
    }

    Rectangle(const Rectangle& other): Figure<Rec>(other){
        this->a = other.a;
        this->b = other.b;
    }

    Rectangle(Rectangle&& other): Figure<Rec>(std::move(other)){
        this->a = other.a;
        other.a = 0;
        this->b = other.b;
        other.b = 0;
    }

    ~Rectangle(){
        a = 0;
        b = 0;
    }


    virtual Rec get_area() override{
        this->area = a * b;
        return (this->area);
    }


    Rectangle<Rec>& operator=(const Rectangle<Rec>& other){
        if (this != &other){
            for (int q = 0; q < 4; q++){
                this->coord[q] = other.coord[q];
            }
            this->a = other.a;
            this->b = other.b;
        }
        return *this;
    }

    Rectangle<Rec>& operator=(Rectangle<Rec>&& other){
        if (this != &other){
            for (int q = 0; q < 4; q++){
                this->coord[q] = other.coord[q];
                other.coord[q] = {0, 0};
            }
            this->a = other.a;
            other.a = 0;
            this->b = other.b;
            other.b = 0;
        }
        return *this;
    }

    bool operator==(const Rectangle<Rec>& other) const{
        if (this->a != other.a || this->b != other.b){
            return false;
        }
        return true;
    }


    Rec a;
    Rec b;

};

template <typename T>
inline std::istream& operator>>(std::istream& is, Rectangle<T>& rect){

    std::cout << "Введите координаты вершин прямоугольника в таком порядке через пробелы: A(x) A(y) B(x) B(y) C(x) C(y) D(x) D(y), где вершины A B C D идут по кругу: " << "\n";
    
    for (int q = 0; q < 4; q++){
        is >> rect.coord[q].first >> rect.coord[q].second;
    }
    std::cout << "Введите длины сторон через пробел, сначала меньшую, затем большую: " << "\n";
    is >> rect.a >> rect.b;
    std::cout << "Ввод закончен." << "\n";

    return is;
}

template <typename T>
inline std::ostream& operator<<(std::ostream& os, const Rectangle<T>& rect){

    os << "Координаты прямоугольника:" << "\n"; 
    os << "A: x = " << rect.coord[0].first << "; y = " << rect.coord[0].second << "\n";
    os << "B: x = " << rect.coord[1].first << "; y = " << rect.coord[1].second << "\n";
    os << "C: x = " << rect.coord[2].first << "; y = " << rect.coord[2].second << "\n";
    os << "D: x = " << rect.coord[3].first << "; y = " << rect.coord[3].second << "\n";
    os << "Длины сторон прямоугольника: " << rect.a << "; " << rect.b << "\n";

    return os;
}
```
#### Trapezoid.h
```cpp
#pragma once
#include<iostream>
#include"Figure.h"

template <typename Trap>
class Trapezoid: public Figure<Trap>
{

    template <typename T>
    friend std::istream& operator>>(std::istream& is, Trapezoid<T>& trap);
    template <typename T>
    friend std::ostream& operator<<(std::ostream& os, const Trapezoid<T>& trap);

public:

    Trapezoid(): Figure<Trap>(){
        AB = 0;
        CD = 0;
        high = 0;
    }

    Trapezoid(std::pair<Trap, Trap> coord[4], Trap& AB, Trap& CD, Trap& high): Figure<Trap>(coord){
        this->AB = AB;
        this->CD = CD;
        this->high = high;
    }

    Trapezoid(const Trapezoid& other): Figure<Trap>(other){
        this->AB = other.AB;
        this->CD = other.CD;
        this->high = other.high;
    }

    Trapezoid(Trapezoid&& other): Figure<Trap>(std::move(other)){
        this->AB = other.AB;
        other.AB = 0;
        this->CD = other.CD;
        other.CD = 0;
        this->high = other.high;
        other.high = 0;
    }

    ~Trapezoid(){
        AB = 0;
        CD = 0;
        high = 0;
    }


    virtual Trap get_area() override{
        this->area = ((AB + CD) * high) / 2;
        return (this->area);
    }


    Trapezoid<Trap>& operator=(const Trapezoid<Trap>& other){
        if (this != &other){
            for (int q = 0; q < 4; q++){
                this->coord[q] = other.coord[q];
            }
            this->AB = other.AB;
            this->CD = other.CD;
            this->high = other.high;
        }
        return *this;
    }

    Trapezoid<Trap>& operator=(Trapezoid<Trap>&& other){
        if (this != &other){
            for (int q = 0; q < 4; q++){
                this->coord[q] = other.coord[q];
                other.coord[q] = {0, 0};
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

    bool operator==(const Trapezoid<Trap>& other) const{
        if (this->AB != other.AB || this->CD != other.CD || this->high != other.high){
            return false;
        }
        return true;
    }


    Trap AB;
    Trap CD;
    Trap high;

};

template <typename T>
inline std::istream& operator>>(std::istream& is, Trapezoid<T>& trap){

    std::cout << "Введите координаты вершин трапеции в таком порядке через пробелы: A(x) A(y) B(x) B(y) C(x) C(y) D(x) D(y), где вершины A B C D идут по кругу: " << "\n";
    
    for (int q = 0; q < 4; q++){
        is >> trap.coord[q].first >> trap.coord[q].second;
    }
    std::cout << "Введите высоту трапеции: " << "\n";
    is >> trap.high;
    std::cout << "Введите длины оснований трапеции через пробел, сначала меньшую, затем большую: " << "\n";
    is >> trap.AB >> trap.CD;
    std::cout << "Ввод закончен." << "\n";

    return is;
}

template <typename T>
inline std::ostream& operator<<(std::ostream& os, const Trapezoid<T>& trap){

    os << "Координаты трапеции:" << "\n"; 
    os << "A: x = " << trap.coord[0].first << "; y = " << trap.coord[0].second << "\n";
    os << "B: x = " << trap.coord[1].first << "; y = " << trap.coord[1].second << "\n";
    os << "C: x = " << trap.coord[2].first << "; y = " << trap.coord[2].second << "\n";
    os << "D: x = " << trap.coord[3].first << "; y = " << trap.coord[3].second << "\n";
    os << "Высота трапеции: " << trap.high << "\n";
    os << "Длины оснований трапеции: " << trap.AB << "; " << trap.CD << "\n";

    return os;
}
```
#### tests.cpp
```cpp
#include<gtest/gtest.h>
#include"Figure.h"
#include"Square.h"
#include"Rectangle.h"
#include"Trapezoid.h"

TEST(test_1, AllMetods)
{   
// квадрат
    std::pair<double, double> coord_sq1[4] = {{2.0, 4.0}, {4.0, 4.0}, {4.0, 2.0}, {2.0, 2.0}};
    double a_sq1 = 2.0;
    Square<double> sq1(coord_sq1, a_sq1);

    std::pair<double, double> coord_sq2[4] = {{-2.0, 2.0}, {0.0, 2.0}, {0.0, 0.0}, {-2.0, 0.0}};
    double a_sq2 = 2.0;
    Square<double> sq2(coord_sq2, a_sq2);

    double get_area1 = sq1.get_area();
    double expect_get_area1 = 4;
    double get_area2 = sq2.get_area();
    double expect_get_area2 = 4;

    std::pair<double, double> centre_1 = sq1.get_centre();
    std::pair<double, double> expect_centre_1 = {3, 3};
    std::pair<double, double> centre_2 = sq2.get_centre();
    std::pair<double, double> expect_centre_2 = {-1, 1};

// проверка

    ASSERT_EQ(get_area1, expect_get_area1);
    ASSERT_EQ(get_area2, expect_get_area2);

    ASSERT_EQ(centre_1, expect_centre_1);
    ASSERT_EQ(centre_2, expect_centre_2);

    EXPECT_TRUE(sq1 == sq2);

}

TEST(test_2, AllMetods)
{   
// прямоугольник
    std::pair<double, double> coord_rec1[4] = {{1.0, 4.0}, {3.0, 4.0}, {3.0, 1.0}, {1.0, 1.0}};
    double a_rec1 = 2.0;
    double b_rec1 = 3.0;
    Rectangle<double> rec1(coord_rec1, a_rec1, b_rec1);

    std::pair<double, double> coord_rec2[4] = {{1.0, 1.0}, {2.0, 1.0}, {2.0, -1.0}, {1.0, -1.0}};
    double a_rec2 = 1.0;
    double b_rec2 = 2.0;
    Rectangle<double> rec2(coord_rec2, a_rec2, b_rec2);

    double get_area1 = rec1.get_area();
    double expect_get_area1 = 6;
    double get_area2 = rec2.get_area();
    double expect_get_area2 = 2;

    std::pair<double, double> centre_1 = rec1.get_centre();
    std::pair<double, double> expect_centre1 = {2.0, 2.5};
    std::pair<double, double> centre_2 = rec2.get_centre();
    std::pair<double, double> expect_centre2 = {1.5, 0.0};

// проверка

    ASSERT_EQ(get_area1, expect_get_area1);
    ASSERT_EQ(get_area2, expect_get_area2);

    ASSERT_EQ(centre_1, expect_centre1);
    ASSERT_EQ(centre_2, expect_centre2);

    EXPECT_FALSE(rec1 == rec2);

}

TEST(test_3, AllMetods)
{   
// трапеция
    std::pair<double, double> coord_trap1[4] = {{2.0, 3.0}, {4.0, 3.0}, {5.0, 1.0}, {1.0, 1.0}};
    double high_trap1 = 2.0;
    double AB_trap1 = 2.0;
    double CD_trap1 = 4.0;
    Trapezoid<double> trap1(coord_trap1, AB_trap1, CD_trap1, high_trap1);

    std::pair<double, double> coord_trap2[4] = {{3.0, -1.0}, {4.0, -1.0}, {6.0, -3.0}, {1.0, -3.0}};
    double high_trap2 = 2.0;
    double AB_trap2 = 1.0;
    double CD_trap2 = 5.0;
    Trapezoid<double> trap2(coord_trap2, AB_trap2, CD_trap2, high_trap2);

    double get_area1 = trap1.get_area();
    double expect_get_area1 = 6;
    double get_area2 = trap2.get_area();
    double expect_get_area2 = 6;

    std::pair<double, double> centre_1 = trap1.get_centre();
    std::pair<double, double> expect_centre1 = {3.0, 2.0};
    std::pair<double, double> centre_2 = trap2.get_centre();
    std::pair<double, double> expect_centre2 = {3.5, -2.0};

// проверка

    ASSERT_EQ(get_area1, expect_get_area1);
    ASSERT_EQ(get_area2, expect_get_area2);

    ASSERT_EQ(centre_1, expect_centre1);
    ASSERT_EQ(centre_2, expect_centre2);

    EXPECT_FALSE(trap1 == trap2);

}

TEST(test_4, COPY)
{   
// квадрат
    std::pair<double, double> coord_sq1[4] = {{2.0, 4.0}, {4.0, 4.0}, {4.0, 2.0}, {2.0, 2.0}};
    double a_sq1 = 2.0;
    Square<double> sq1(coord_sq1, a_sq1);

    std::pair<double, double> coord_sq2[4] = {{-2.0, 2.0}, {0.0, 2.0}, {0.0, 0.0}, {-2.0, 0.0}};
    double a_sq2 = 2.0;
    Square<double> sq2(coord_sq2, a_sq2);

    sq2 = sq1;

// прямоугольник
    std::pair<double, double> coord_rec1[4] = {{1.0, 4.0}, {3.0, 4.0}, {3.0, 1.0}, {1.0, 1.0}};
    double a_rec1 = 2.0;
    double b_rec1 = 3.0;
    Rectangle<double> rec1(coord_rec1, a_rec1, b_rec1);

    std::pair<double, double> coord_rec2[4] = {{1.0, 1.0}, {2.0, 1.0}, {2.0, -1.0}, {1.0, -1.0}};
    double a_rec2 = 1.0;
    double b_rec2 = 2.0;
    Rectangle<double> rec2(coord_rec2, a_rec2, b_rec2);

    rec2 = rec1;

// трапеция
    std::pair<double, double> coord_trap1[4] = {{2.0, 3.0}, {4.0, 3.0}, {5.0, 1.0}, {1.0, 1.0}};
    double high_trap1 = 2.0;
    double AB_trap1 = 2.0;
    double CD_trap1 = 4.0;
    Trapezoid<double> trap1(coord_trap1, AB_trap1, CD_trap1, high_trap1);

    std::pair<double, double> coord_trap2[4] = {{3.0, -1.0}, {4.0, -1.0}, {6.0, -3.0}, {1.0, -3.0}};
    double high_trap2 = 2.0;
    double AB_trap2 = 1.0;
    double CD_trap2 = 5.0;
    Trapezoid<double> trap2(coord_trap2, AB_trap2, CD_trap2, high_trap2);

    trap2 = trap1;

// проверка
    EXPECT_EQ(sq1, Square(coord_sq1, a_sq1));
    EXPECT_EQ(rec1, Rectangle(coord_rec1, a_rec1, b_rec1));
    EXPECT_EQ(trap1, Trapezoid(coord_trap1, AB_trap1, CD_trap1, high_trap1));

    EXPECT_EQ(sq2, Square(coord_sq1, a_sq1));
    EXPECT_EQ(rec2, Rectangle(coord_rec1, a_rec1, b_rec1));
    EXPECT_EQ(trap2, Trapezoid(coord_trap1, AB_trap1, CD_trap1, high_trap2));
}

TEST(test_5, Move)
{   
// квадрат
     std::pair<double, double> coord_sq1[4] = {{2.0, 4.0}, {4.0, 4.0}, {4.0, 2.0}, {2.0, 2.0}};
    double a_sq1 = 2.0;
    Square<double> sq1(coord_sq1, a_sq1);

    std::pair<double, double> coord_sq2[4] = {{-2.0, 2.0}, {0.0, 2.0}, {0.0, 0.0}, {-2.0, 0.0}};
    double a_sq2 = 2.0;
    Square<double> sq2(coord_sq2, a_sq2);

    sq2 = std::move (sq1);

// прямоугольник
    std::pair<double, double> coord_rec1[4] = {{1.0, 4.0}, {3.0, 4.0}, {3.0, 1.0}, {1.0, 1.0}};
    double a_rec1 = 2.0;
    double b_rec1 = 3.0;
    Rectangle<double> rec1(coord_rec1, a_rec1, b_rec1);

    std::pair<double, double> coord_rec2[4] = {{1.0, 1.0}, {2.0, 1.0}, {2.0, -1.0}, {1.0, -1.0}};
    double a_rec2 = 1.0;
    double b_rec2 = 2.0;
    Rectangle<double> rec2(coord_rec2, a_rec2, b_rec2);


    rec2 = std::move (rec1);

// трапеция
    std::pair<double, double> coord_trap1[4] = {{2.0, 3.0}, {4.0, 3.0}, {5.0, 1.0}, {1.0, 1.0}};
    double high_trap1 = 2.0;
    double AB_trap1 = 2.0;
    double CD_trap1 = 4.0;
    Trapezoid<double> trap1(coord_trap1, AB_trap1, CD_trap1, high_trap1);

    std::pair<double, double> coord_trap2[4] = {{3.0, -1.0}, {4.0, -1.0}, {6.0, -3.0}, {1.0, -3.0}};
    double high_trap2 = 2.0;
    double AB_trap2 = 1.0;
    double CD_trap2 = 5.0;
    Trapezoid<double> trap2(coord_trap2, AB_trap2, CD_trap2, high_trap2);

    trap2 = std::move (trap1);


    std::pair<double, double> coord[4] = {{0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}};
    double a = 0.0;

// проверка
    EXPECT_EQ(sq1, Square(coord, a));
    EXPECT_EQ(rec1, Rectangle(coord, a, a));
    EXPECT_EQ(trap1, Trapezoid(coord, a, a, a));

    EXPECT_EQ(sq2, Square(coord_sq1, a_sq1));
    EXPECT_EQ(rec2, Rectangle(coord_rec1, a_rec1, b_rec1));
    EXPECT_EQ(trap2, Trapezoid(coord_trap1, AB_trap1, CD_trap1, high_trap1));
}
```