#pragma once


template <typename T>
Box<T>::Box(const Point<T> &point1,
            const Point<T> &point2,
            const Point<T> &point3,
            const Point<T> &point4)
            {
                this->point = std::shared_ptr<Point<T>[]>(::new Point<T>[4]);
                this->point[0] = point1;
                this->point[1] = point2;
                this->point[2] = point3;
                this->point[3] = point4;
                Validator<T> validator;
                validator.validate_figure(*this);
            }



template <typename T>
std::ostream& Box<T>::print(std::ostream &out) const {
    return Rectangle<T>::print(out);
}


template <typename T>
std::istream& Box<T>::scan(std::istream &in) {
    return Rectangle<T>::scan(in);
}


template <typename T>
Point<T> Box<T>::center() const {
    return Rectangle<T>::center();
}


template <typename T>
double Box<T>::square() const {
    return Rectangle<T>::square();
}


template <typename T>
Box<T> & Box<T>::operator=(const Box<T> & box) {
    for (int i = 0; i < 4; ++i) {
        ::new (this->point.get() + i) Point<T>(box.point[i]);
    }
    return *this;
}


template <class T>
Box<T>::Box(const Box & box) : Box<T>() {
    for (int i = 0; i < 4; ++i) {
        ::new (this->point.get() + i) Point<T>(box.point[i]);
    }
}

template <typename T>
Box<T> & Box<T>::operator=(Box<T> && box) {
    if (this != &box)
        this->point = std::move(box.getPoint());
    return *this;
}


template <typename T>
bool Box<T>::equal(const Figure<T> & figure) const {
    return Rectangle<T>::equal(figure);
}


template <typename T>
std::shared_ptr<Point<T>[]> Box<T>::getPoint() const { return this->point; }