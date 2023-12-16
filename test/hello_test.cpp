#include <gtest/gtest.h>
#include "../include/Triangle.h"
#include "../include/Box.h"
#include <cmath>


TEST(test_02, rectangle_square) {
    Point point1(0, 0);
    Point point2(0, 2);
    Point point3(4, 2);
    Point point4(4, 0);

    Rectangle rectangle(point1, point2, point3, point4);

    double s = rectangle.square();
    double res = 8;

    EXPECT_EQ(s, res);
}


TEST(test_03, box_square) {
    Point point1(0, 0);
    Point point2(0, 2);
    Point point3(2, 2);
    Point point4(2, 0);

    Box box(point1, point2, point3, point4);

    double s = box.square();
    double res = 4;

    EXPECT_EQ(s, res);
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
    Point point1(0, 0);
    Point point2(2, 0);
    Point point3(1, sqrt(3));

    Triangle triangle(point1, point2, point3);

    Point center = triangle.center();
    Point point(1, 0.5773502691896257);

    EXPECT_EQ(center, point);
}


TEST(test_07, triangle_ctor) {

    Triangle triangle;

    Point * point = triangle.getPoint();
    Point true_point(0, 0);
    EXPECT_EQ(point[0], true_point);
    EXPECT_EQ(point[1], true_point);
    EXPECT_EQ(point[2], true_point);

}


TEST(test_08, rectangle_ctor) {

    Rectangle rectangle;

    Point * point = rectangle.getPoint();
    Point true_point(0, 0);
    EXPECT_EQ(point[0], true_point);
    EXPECT_EQ(point[1], true_point);
    EXPECT_EQ(point[2], true_point);
    EXPECT_EQ(point[3], true_point);

}


TEST(test_09, box_ctor) {

    Box box;

    Point * point = box.getPoint();
    Point true_point(0, 0);
    EXPECT_EQ(point[0], true_point);
    EXPECT_EQ(point[1], true_point);
    EXPECT_EQ(point[2], true_point);
    EXPECT_EQ(point[3], true_point);

}


TEST(test_10, triangle_ctor_with_parametrs) {
    Point point1(11 ,11);
    Point point2(22 ,22);
    Point point3(33 ,33);


    Triangle triangle(point1, point2, point3);

    Point * point = triangle.getPoint();

    EXPECT_EQ(point[0], point1);
    EXPECT_EQ(point[1], point2);
    EXPECT_EQ(point[2], point3);

}