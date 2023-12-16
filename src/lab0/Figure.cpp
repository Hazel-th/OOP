#include "../include/Figure.h"


std::ostream& operator<< (std::ostream& out, const Figure& figure) {
    return figure.print(out);
}
std::istream& operator>> (std::istream& in, Figure& figure) {
    return figure.scan(in);
}


bool operator==(const Figure& figure1, const Figure& figure2) {
    if (figure1.type() != figure2.type()) {
        return false;
    }
    return figure1.equal(figure2);
}


Figure::~Figure() {
    delete[] point;
    point = nullptr;
}