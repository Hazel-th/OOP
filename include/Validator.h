#pragma once
#include "Triangle.h"
#include "Box.h"
#include "vector"


class IValidator {
public:
    virtual void oneLine(Point *points) const = 0;
    virtual bool goodType(Figure &figure) const = 0;
    virtual void equilateral(Point *points) const = 0;
    virtual void corectPoints(Point *points) const {};
    virtual void validate(Figure &figure) const = 0;
};


class TriangleValidator : public IValidator {
public:
    void oneLine(Point *points) const override;
    bool goodType(Figure & figure) const override;
    void equilateral(Point *points) const override;
    void validate(Figure &figure) const override;
};


class RectangleValidator : public IValidator {
public:
    void oneLine(Point *points) const override;
    bool goodType(Figure & figure) const override;
    void equilateral(Point *points) const override;
    void corectPoints(Point *points) const override;
    void validate(Figure &figure) const override;
};


class BoxValidator : public IValidator {
public:
    void oneLine(Point *points) const override;
    bool goodType(Figure & figure) const override;
    void equilateral(Point *points) const override;
    void corectPoints(Point *points) const override;
    void validate(Figure &figure) const override;
};


class Validator {
private:
    std::vector<IValidator*> validations;

public:

    Validator();
    virtual ~Validator();
    void validate_figure(Figure & figure) ;

};