#pragma once


template <typename T>
class IValidator {
public:
    virtual void oneLine(std::shared_ptr<Point<T>[]> points) const = 0;
    virtual bool goodType(Figure<T> & figure) const = 0;
    virtual void equilateral(std::shared_ptr<Point<T>[]> points) const = 0;
    virtual void corectPoints(std::shared_ptr<Point<T>[]> points) const {};
    virtual void validate(Figure<T> & figure) const = 0;
};


template <typename T>
class TriangleValidator : public IValidator<T> {
public:
    void oneLine(std::shared_ptr<Point<T>[]> points) const override;
    bool goodType(Figure<T> & figure) const override;
    void equilateral(std::shared_ptr<Point<T>[]> points) const override;
    void validate(Figure<T> &figure) const override;
};


template <typename T>
class RectangleValidator : public IValidator<T> {
public:
    void oneLine(std::shared_ptr<Point<T>[]> points) const override;
    bool goodType(Figure<T> & figure) const override;
    void equilateral(std::shared_ptr<Point<T>[]> points) const override;
    void corectPoints(std::shared_ptr<Point<T>[]> points) const override;
    void validate(Figure<T> &figure) const override;
};


template <typename T>
class BoxValidator : public IValidator<T> {
public:
    void oneLine(std::shared_ptr<Point<T>[]> points) const override;
    bool goodType(Figure<T> & figure) const override;
    void equilateral(std::shared_ptr<Point<T>[]> points) const override;
    void corectPoints(std::shared_ptr<Point<T>[]> points) const override;
    void validate(Figure<T> & figure) const override;
};


template <typename T>
class Validator {
private:
    std::vector<std::shared_ptr<IValidator<T>>> validations;

public:

    Validator();
    virtual ~Validator();
    void validate_figure(Figure<T> & figure) ;

};


#include "../src/Validator.inl"