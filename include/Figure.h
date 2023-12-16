#pragma once
#include "Point.h"
#include <memory>

template <class T>
class Figure {
protected:
    std::shared_ptr<Point<T>[]> point;

public:
    virtual std::shared_ptr<Point<T>[]> getPoint() const { return point; };

    Figure() = default;
    ~Figure();

    virtual Point<T> center() const = 0;

    template<class U>
    friend std::ostream& operator<< (std::ostream& out, const Figure<U>& figure);

    template<class U>
    friend std::istream& operator>> (std::istream& in, Figure<U>& figure);

    virtual double square() const = 0;
    virtual std::ostream& print(std::ostream& out) const = 0;
    virtual std::istream& scan(std::istream& in) = 0;
    virtual bool equal(const Figure& figure) const = 0;
    virtual std::string type() const { return "Figure"; };


};


template <class T>
std::ostream& operator<< (std::ostream& out, const Figure<T>& figure);

template <class T>
std::istream& operator>> (std::istream& in, Figure<T>& figure);

template <class T>
bool operator==(const Figure<T>& figure1, const Figure<T>& figure2);



template <class T, class... Args>
std::shared_ptr<Point<T>[]> create_array_of_points(size_t size, Args&&... args) {
    std::shared_ptr<Point<T>[]> pointer(new Point<T>[size]{std::forward<Args>(args)...});
    return pointer;
}



#include "../src/Figure.inl"