#pragma once
#include "Box.h"
#include "Triangle.h"


class Fabric {
public:
    virtual Figure* create_figure(Point * points) = 0;
    virtual ~Fabric();

};


class FabricTriangle : public Fabric {
public:
    Figure* create_figure(Point * points) override final;

};


class FabricRectangle : public Fabric {
public:
    Figure* create_figure(Point * points) override final;

};


class FabricBox : public Fabric {
public:
    Figure* create_figure(Point * points) override final;

};