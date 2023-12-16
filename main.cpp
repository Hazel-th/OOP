#include "../include/Fabric.h"
#include "../include/Validator.h"
#include <algorithm>


using namespace std;

int main() {

    try {
        Point point1(0, 1);
        Point point2(2, 0);
        Point point3(1, sqrt(3));
        Validator v;
        Triangle triangle(point1, point2, point3);
        v.validate_figure(triangle);
    }
    catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }


    return 0;
}