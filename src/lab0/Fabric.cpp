#include "../include/Fabric.h"


Figure *FabricTriangle::create_figure(Point * points = nullptr) { return new Triangle(points[0], points[1], points[2]); }


Figure *FabricBox::create_figure(Point * points = nullptr) { return new Box(points[0], points[1], points[2], points[3]); }


Figure *FabricRectangle::create_figure(Point * points) { return new Rectangle(points[0], points[1], points[2], points[3]); }

Fabric::~Fabric() { delete this; }