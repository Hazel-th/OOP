#include <gtest/gtest.h>
#include "Fabric.h"
#include "Box.h"
#include "Triangle.h"


TEST(test_01, triangle_square) {
    Point<double> point1(0, 0);
    Point<double> point2(2, 0);
    Point<double> point3(1, sqrt(3));

    Triangle<double> triangle(point1, point2, point3);

    double s = triangle.square();
    double res = 1.7320;

    EXPECT_NEAR(s, res, 4);
}



TEST(test_02, rectangle_square) {
    Point point1(0, 0);
    Point point2(0, 2);
    Point point3(4, 2);
    Point point4(4, 0);

    Rectangle rectangle(point1, point2, point3, point4);

    double s = rectangle.square();
    double res = 8;

    EXPECT_NEAR(s, res, 4);
}



TEST(test_03, box_square) {
    Point point1(0, 0);
    Point point2(0, 2);
    Point point3(2, 2);
    Point point4(2, 0);

    Box box(point1, point2, point3, point4);

    double s = box.square();
    double res = 4;

    EXPECT_NEAR(s, res, 4);
}


TEST(test_04, box_center) {
    Point point1(0, 0);
    Point point2(0, 2);
    Point point3(2, 2);
    Point point4(2, 0);

    Box box(point1, point2, point3, point4);

    Point center = box.center();
    Point point(1, 1);

    EXPECT_EQ(center, point);
}



TEST(test_05, rectangle_center) {
    Point point1(0, 0);
    Point point2(0, 2);
    Point point3(4, 2);
    Point point4(4, 0);

    Rectangle rectangle(point1, point2, point3, point4);

    Point center = rectangle.center();
    Point point(2, 1);

    EXPECT_EQ(center, point);
}


TEST(test_06, triangle_center) {
    Point<double> point1(0, 0);
    Point<double> point2(2, 0);
    Point<double> point3(1, sqrt(3));

    Triangle triangle(point1, point2, point3);

    Point center = triangle.center();
    Point<double> point(1, 0.57735);

    EXPECT_NEAR(center.x, point.x, 4);
    EXPECT_NEAR(center.y, point.y, 4);
}


TEST(test_07, triangle_ctor) {

    Triangle<double> triangle;

    std::shared_ptr<Point<double>[]> point = triangle.getPoint();
    Point<double> true_point(0, 0);
    EXPECT_EQ(point[0], true_point);
    EXPECT_EQ(point[1], true_point);
    EXPECT_EQ(point[2], true_point);

}


TEST(test_08, rectangle_ctor) {

    Rectangle<double> rectangle;

    std::shared_ptr<Point<double>[]> point = rectangle.getPoint();
    Point<double> true_point(0, 0);
    EXPECT_EQ(point[0], true_point);
    EXPECT_EQ(point[1], true_point);
    EXPECT_EQ(point[2], true_point);
    EXPECT_EQ(point[3], true_point);

}


TEST(test_09, box_ctor) {

    Box<double> box;

    std::shared_ptr<Point<double>[]> point = box.getPoint();
    Point<double> true_point(0, 0);
    EXPECT_EQ(point[0], true_point);
    EXPECT_EQ(point[1], true_point);
    EXPECT_EQ(point[2], true_point);
    EXPECT_EQ(point[3], true_point);

}


TEST(test_10, triangle_ctor_with_parametrs) {
    Point<double> point1(0, 0);
    Point<double> point2(2, 0);
    Point<double> point3(1, sqrt(3));


    Triangle<double> triangle(point1, point2, point3);

    std::shared_ptr<Point<double>[]> point = triangle.getPoint();

    EXPECT_EQ(point[0], point1);
    EXPECT_EQ(point[1], point2);
    EXPECT_EQ(point[2], point3);

}



TEST(test_11, rectangle_ctor_with_parametrs) {
    Point<double> point1(0, 0);
    Point<double> point2(0, 2);
    Point<double> point3(4, 2);
    Point<double> point4(4, 0);


    Rectangle<double> rectangle(point1, point2, point3, point4);

    std::shared_ptr<Point<double>[]> point = rectangle.getPoint();

    EXPECT_EQ(point[0], point1);
    EXPECT_EQ(point[1], point2);
    EXPECT_EQ(point[2], point3);
    EXPECT_EQ(point[3], point4);

}


TEST(test_12, box_ctor_with_parametrs) {
    Point<double> point1(0, 0);
    Point<double> point2(0, 2);
    Point<double> point3(2, 2);
    Point<double> point4(2, 0);


    Box<double> box(point1, point2, point3, point4);

    std::shared_ptr<Point<double>[]> point = box.getPoint();

    EXPECT_EQ(point[0], point1);
    EXPECT_EQ(point[1], point2);
    EXPECT_EQ(point[2], point3);
    EXPECT_EQ(point[3], point4);

}



TEST(test_13, box_copy_ctor) {
    Point<double> point1(0, 0);
    Point<double> point2(0, 2);
    Point<double> point3(2, 2);
    Point<double> point4(2, 0);


    Box<double> box(point1, point2, point3, point4);

    Box<double> box_copy(box);

    std::shared_ptr<Point<double>[]> point = box_copy.getPoint();

    EXPECT_EQ(point[0], point1);
    EXPECT_EQ(point[1], point2);
    EXPECT_EQ(point[2], point3);
    EXPECT_EQ(point[3], point4);

}



TEST(test_14, triangle_copy_ctor) {
    Point<double> point1(0, 0);
    Point<double> point2(0, 2);
    Point<double> point3(2, 2);


    Triangle<double> triangle(point1, point2, point3);

    Triangle<double> triangle_copy(triangle);

    std::shared_ptr<Point<double>[]> point = triangle_copy.getPoint();

    EXPECT_EQ(point[0], point1);
    EXPECT_EQ(point[1], point2);
    EXPECT_EQ(point[2], point3);

}


TEST(test_15, rectangle_copy_ctor) {
    Point<double> point1(0, 0);
    Point<double> point2(0, 2);
    Point<double> point3(2, 2);
    Point<double> point4(2, 0);


    Rectangle<double> rectangle(point1, point2, point3, point4);

    Rectangle<double> rectangle_copy(rectangle);

    std::shared_ptr<Point<double>[]> point = rectangle_copy.getPoint();

    EXPECT_EQ(point[0], point1);
    EXPECT_EQ(point[1], point2);
    EXPECT_EQ(point[2], point3);
    EXPECT_EQ(point[3], point4);

}



TEST(test_16, rectangle_operator_assign) {
    Point<double> point1(0, 0);
    Point<double> point2(0, 2);
    Point<double> point3(2, 2);
    Point<double> point4(2, 0);


    Rectangle<double> rectangle(point1, point2, point3, point4);

    Rectangle<double> rectangle_assign;

    rectangle_assign = rectangle;

    std::shared_ptr<Point<double>[]> point = rectangle_assign.getPoint();

    EXPECT_EQ(point[0], point1);
    EXPECT_EQ(point[1], point2);
    EXPECT_EQ(point[2], point3);
    EXPECT_EQ(point[3], point4);

}


TEST(test_17, box_operator_assign) {
    Point<double> point1(0, 0);
    Point<double> point2(0, 2);
    Point<double> point3(2, 2);
    Point<double> point4(2, 0);


    Box<double> box(point1, point2, point3, point4);

    Box<double> box_assign;

   box_assign = box;

    std::shared_ptr<Point<double>[]> point = box_assign.getPoint();

    EXPECT_EQ(point[0], point1);
    EXPECT_EQ(point[1], point2);
    EXPECT_EQ(point[2], point3);
    EXPECT_EQ(point[3], point4);

}



TEST(test_18, triangle_operator_assign) {
    Point<double> point1(0, 0);
    Point<double> point2(0, 2);
    Point<double> point3(2, 2);
    Point<double> point4(2, 0);


    Triangle<double> triangle(point1, point2, point3);

    Triangle<double> triangle_assign;

    triangle_assign = triangle;

    std::shared_ptr<Point<double>[]> point = triangle_assign.getPoint();

    EXPECT_EQ(point[0], point1);
    EXPECT_EQ(point[1], point2);
    EXPECT_EQ(point[2], point3);

}


TEST(test_19, triangle_operator_assign_rvalue) {
    Point<double> point1(0, 0);
    Point<double> point2(0, 2);
    Point<double> point3(2, 2);
    Point<double> point4(2, 0);


    Triangle<double> triangle_assign;

    triangle_assign = Triangle(point1, point2, point3);;

    std::shared_ptr<Point<double>[]> point = triangle_assign.getPoint();

    EXPECT_EQ(point[0], point1);
    EXPECT_EQ(point[1], point2);
    EXPECT_EQ(point[2], point3);

}


TEST(test_20, rectangle_operator_assign_rvalue) {
    Point<double> point1(0, 0);
    Point<double> point2(0, 2);
    Point<double> point3(2, 2);
    Point<double> point4(2, 0);


    Rectangle<double> rectangle_assign;

    rectangle_assign = Rectangle(point1, point2, point3, point4);

    std::shared_ptr<Point<double>[]> point = rectangle_assign.getPoint();

    EXPECT_EQ(point[0], point1);
    EXPECT_EQ(point[1], point2);
    EXPECT_EQ(point[2], point3);
    EXPECT_EQ(point[3], point4);

}


TEST(test_21, box_operator_assign_rvalue) {
    Point<double> point1(0, 0);
    Point<double> point2(0, 2);
    Point<double> point3(2, 2);
    Point<double> point4(2, 0);


    Box<double> box_assign;

    box_assign = Box(point1, point2, point3, point4);

    std::shared_ptr<Point<double>[]> point = box_assign.getPoint();

    EXPECT_EQ(point[0], point1);
    EXPECT_EQ(point[1], point2);
    EXPECT_EQ(point[2], point3);
    EXPECT_EQ(point[3], point4);

}