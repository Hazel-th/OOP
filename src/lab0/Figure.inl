#pragma once


template <class T>
std::ostream& operator<< (std::ostream& out, const Figure<T>& figure) {
    return figure.print(out);
}

template <class T>
std::istream& operator>> (std::istream& in, Figure<T>& figure) {
    return figure.scan(in);
}


template <class T>
bool operator==(const Figure<T>& figure1, const Figure<T>& figure2) {
    if (figure1.type() != figure2.type()) {
        return false;
    }
    return figure1.equal(figure2);
}


template <class T>
Figure<T>::~Figure() = default;
