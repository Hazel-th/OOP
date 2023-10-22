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
    figures.add(sq, 0);

    double coord_rec[8] = {1.0, 4.0, 3.0, 4.0, 3.0, 1.0, 1.0, 1.0};
    double a_rec = 2.0;
    double b_rec = 3.0;
    Rectangle* rec = new Rectangle(coord_rec, a_rec, b_rec);
    figures.add(rec, 1);

    double coord_trap[8] = {2.0, 3.0, 4.0, 3.0, 5.0, 1.0, 1.0, 1.0};;
    double h_trap = 2.0;
    double a_trap = 2.0;
    double b_trap = 4.0;
    Trapezoid* trap = new Trapezoid(coord_trap, h_trap, a_trap, b_trap);
    figures.add(trap, 2);

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