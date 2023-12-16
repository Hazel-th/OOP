#pragma once


template <class T>
Figure<T> * FabricTriangle<T>::create_figure(std::shared_ptr<Point<T>[]> points) { return new Triangle<T>(points[0], points[1], points[2]); }


template <class T>
Figure<T> * FabricBox<T>::create_figure(std::shared_ptr<Point<T>[]> points) { return new Box<T>(points[0], points[1], points[2], points[3]); }


template <class T>
Figure<T> * FabricRectangle<T>::create_figure(std::shared_ptr<Point<T>[]> points) { return new Rectangle<T>(points[0], points[1], points[2], points[3]); }


template <class T>
Fabric<T>::~Fabric() = default;