#pragma once
#include "Box.h"
#include "Triangle.h"


template <class T>
class Fabric {
public:
    virtual Figure<T> * create_figure(std::shared_ptr<Point<T>[]> points) = 0;
    virtual ~Fabric();

};


template <class T>
class FabricTriangle : public Fabric<T> {
public:
    Figure<T> * create_figure(std::shared_ptr<Point<T>[]> points) final;

};


template <class T>
class FabricRectangle : public Fabric<T> {
public:
    Figure<T> * create_figure(std::shared_ptr<Point<T>[]> points) final;

};


template <class T>
class FabricBox : public Fabric<T> {
public:
    Figure<T> * create_figure(std::shared_ptr<Point<T>[]> points) final;

};


#include "../src/Fabric.inl"