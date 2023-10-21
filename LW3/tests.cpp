#include <gtest/gtest.h>
#include"Figure.h"
#include"Square.h"
#include"Rectangle.h"
#include"Trapezoid.h"

TEST(test_1, AllMetods)
{   
// квадрат
    double coord_sq1[8] = {2.0, 4.0, 4.0, 4.0, 4.0, 2.0, 2.0, 2.0};
    double a_sq1 = 2.0;
    Square sq1(coord_sq1, a_sq1);

    double coord_sq2[8] = {-2.0, 2.0, 0.0, 2.0, 0.0, 0.0, -2.0, 0.0};
    double a_sq2 = 2.0;
    Square sq2(coord_sq2, a_sq2);

    double area1 = static_cast<double>(sq1);
    double expect_area1 = 4;
    double area2 = static_cast<double>(sq2);
    double expect_area2 = 4;

    double get_area1 = sq1.get_area();
    double expect_get_area1 = 4;
    double get_area2 = sq2.get_area();
    double expect_get_area2 = 4;

    double centre_x1 = sq1.get_centre_x();
    double expect_centre_x1 = 3;
    double centre_x2 = sq2.get_centre_x();
    double expect_centre_x2 = -1;

    double centre_y1 = sq1.get_centre_y();
    double expect_centre_y1 = 3;
    double centre_y2 = sq2.get_centre_y();
    double expect_centre_y2 = 1;

// проверка
    ASSERT_EQ(area1, expect_area1);
    ASSERT_EQ(area2, expect_area2);

    ASSERT_EQ(get_area1, expect_get_area1);
    ASSERT_EQ(get_area2, expect_get_area2);

    ASSERT_EQ(centre_x1, expect_centre_x1);
    ASSERT_EQ(centre_x2, expect_centre_x2);

    ASSERT_EQ(centre_y1, expect_centre_y1);
    ASSERT_EQ(centre_y2, expect_centre_y2);

    EXPECT_TRUE(sq1 == sq2);

}

TEST(test_2, AllMetods)
{   
// прямоугольник
    double coord_rec1[8] = {1.0, 4.0, 3.0, 4.0, 3.0, 1.0, 1.0, 1.0};
    double a_rec1 = 2.0;
    double b_rec1 = 3.0;
    Rectangle rec1(coord_rec1, a_rec1, b_rec1);

    double coord_rec2[8] = {1.0, 1.0, 2.0, 1.0, 2.0, -1.0, 1.0, -1.0};
    double a_rec2 = 1.0;
    double b_rec2 = 2.0;
    Rectangle rec2(coord_rec2, a_rec2, b_rec2);

    double area1 = static_cast<double>(rec1);
    double expect_area1 = 6;
    double area2 = static_cast<double>(rec2);
    double expect_area2 = 2;

    double get_area1 = rec1.get_area();
    double expect_get_area1 = 6;
    double get_area2 = rec2.get_area();
    double expect_get_area2 = 2;

    double centre_x1 = rec1.get_centre_x();
    double expect_centre_x1 = 2.0;
    double centre_x2 = rec2.get_centre_x();
    double expect_centre_x2 = 1.5;

    double centre_y1 = rec1.get_centre_y();
    double expect_centre_y1 = 2.5;
    double centre_y2 = rec2.get_centre_y();
    double expect_centre_y2 = 0;

// проверка
    ASSERT_EQ(area1, expect_area1);
    ASSERT_EQ(area2, expect_area2);

    ASSERT_EQ(get_area1, expect_get_area1);
    ASSERT_EQ(get_area2, expect_get_area2);

    ASSERT_EQ(centre_x1, expect_centre_x1);
    ASSERT_EQ(centre_x2, expect_centre_x2);

    ASSERT_EQ(centre_y1, expect_centre_y1);
    ASSERT_EQ(centre_y2, expect_centre_y2);

    EXPECT_FALSE(rec1 == rec2);

}

TEST(test_3, AllMetods)
{   
// трапеция
    double coord_trap1[8] = {2.0, 3.0, 4.0, 3.0, 5.0, 1.0, 1.0, 1.0};
    double high_trap1 = 2.0;
    double AB_trap1 = 2.0;
    double CD_trap1 = 4.0;
    Trapezoid trap1(coord_trap1, high_trap1, AB_trap1, CD_trap1);

    double coord_trap2[8] = {3.0, -1.0, 4.0, -1.0, 6.0, -3.0, 1.0, -3.0};
    double high_trap2 = 2.0;
    double AB_trap2 = 1.0;
    double CD_trap2 = 5.0;
    Trapezoid trap2(coord_trap2, high_trap2, AB_trap2, CD_trap2);

    double area1 = static_cast<double>(trap1);
    double expect_area1 = 6;
    double area2 = static_cast<double>(trap2);
    double expect_area2 = 6;

    double get_area1 = trap1.get_area();
    double expect_get_area1 = 6;
    double get_area2 = trap2.get_area();
    double expect_get_area2 = 6;

    double centre_x1 = trap1.get_centre_x();
    double expect_centre_x1 = 3.0;
    double centre_x2 = trap2.get_centre_x();
    double expect_centre_x2 = 3.5;

    double centre_y1 = trap1.get_centre_y();
    double expect_centre_y1 = 2.0;
    double centre_y2 = trap2.get_centre_y();
    double expect_centre_y2 = -2;

// проверка
    ASSERT_EQ(area1, expect_area1);
    ASSERT_EQ(area2, expect_area2);

    ASSERT_EQ(get_area1, expect_get_area1);
    ASSERT_EQ(get_area2, expect_get_area2);

    ASSERT_EQ(centre_x1, expect_centre_x1);
    ASSERT_EQ(centre_x2, expect_centre_x2);

    ASSERT_EQ(centre_y1, expect_centre_y1);
    ASSERT_EQ(centre_y2, expect_centre_y2);

    EXPECT_FALSE(trap1 == trap2);

}

TEST(test_4, COPY)
{   
// квадрат
    double coord_sq1[8] = {2.0, 4.0, 4.0, 4.0, 4.0, 2.0, 2.0, 2.0};
    double a_sq1 = 2.0;
    Square sq1(coord_sq1, a_sq1);

    double coord_sq2[8] = {-2.0, 2.0, 0.0, 2.0, 0.0, 0.0, -2.0, 0.0};
    double a_sq2 = 2.0;
    Square sq2(coord_sq2, a_sq2);

    sq2 = sq1;

// прямоугольник
    double coord_rec1[8] = {1.0, 4.0, 3.0, 4.0, 3.0, 1.0, 1.0, 1.0};
    double a_rec1 = 2.0;
    double b_rec1 = 3.0;
    Rectangle rec1(coord_rec1, a_rec1, b_rec1);

    double coord_rec2[8] = {1.0, 1.0, 2.0, 1.0, 2.0, -1.0, 1.0, -1.0};
    double a_rec2 = 1.0;
    double b_rec2 = 2.0;
    Rectangle rec2(coord_rec2, a_rec2, b_rec2);

    rec2 = rec1;

// трапеция
    double coord_trap1[8] = {2.0, 3.0, 4.0, 3.0, 5.0, 1.0, 1.0, 1.0};
    double high_trap1 = 2.0;
    double AB_trap1 = 2.0;
    double CD_trap1 = 4.0;
    Trapezoid trap1(coord_trap1, high_trap1, AB_trap1, CD_trap1);

    double coord_trap2[8] = {3.0, -1.0, 4.0, -1.0, 6.0, -3.0, 1.0, -3.0};
    double high_trap2 = 2.0;
    double AB_trap2 = 1.0;
    double CD_trap2 = 5.0;
    Trapezoid trap2(coord_trap2, high_trap2, AB_trap2, CD_trap2);

    trap2 = trap1;

// проверка
    EXPECT_EQ(sq1, Square(coord_sq1, a_sq1));
    EXPECT_EQ(rec1, Rectangle(coord_rec1, a_rec1, b_rec1));
    EXPECT_EQ(trap1, Trapezoid(coord_trap1, high_trap1, AB_trap1, CD_trap1));

    EXPECT_EQ(sq2, Square(coord_sq1, a_sq1));
    EXPECT_EQ(rec2, Rectangle(coord_rec1, a_rec1, b_rec1));
    EXPECT_EQ(trap2, Trapezoid(coord_trap1, high_trap1, AB_trap1, CD_trap1));
}

TEST(test_5, Move)
{   
// квадрат
    double coord_sq1[8] = {2.0, 4.0, 4.0, 4.0, 4.0, 2.0, 2.0, 2.0};
    double a_sq1 = 2.0;
    Square sq1(coord_sq1, a_sq1);

    double coord_sq2[8] = {-2.0, 2.0, 0.0, 2.0, 0.0, 0.0, -2.0, 0.0};
    double a_sq2 = 2.0;
    Square sq2(coord_sq2, a_sq2);

    sq2 = std::move (sq1);

// прямоугольник
    double coord_rec1[8] = {1.0, 4.0, 3.0, 4.0, 3.0, 1.0, 1.0, 1.0};
    double a_rec1 = 2.0;
    double b_rec1 = 3.0;
    Rectangle rec1(coord_rec1, a_rec1, b_rec1);

    double coord_rec2[8] = {1.0, 1.0, 2.0, 1.0, 2.0, -1.0, 1.0, -1.0};
    double a_rec2 = 1.0;
    double b_rec2 = 2.0;
    Rectangle rec2(coord_rec2, a_rec2, b_rec2);

    rec2 = std::move (rec1);

// трапеция
    double coord_trap1[8] = {2.0, 3.0, 4.0, 3.0, 5.0, 1.0, 1.0, 1.0};
    double high_trap1 = 2.0;
    double AB_trap1 = 2.0;
    double CD_trap1 = 4.0;
    Trapezoid trap1(coord_trap1, high_trap1, AB_trap1, CD_trap1);

    double coord_trap2[8] = {3.0, -1.0, 4.0, -1.0, 6.0, -3.0, 1.0, -3.0};
    double high_trap2 = 2.0;
    double AB_trap2 = 1.0;
    double CD_trap2 = 5.0;
    Trapezoid trap2(coord_trap2, high_trap2, AB_trap2, CD_trap2);

    trap2 = std::move (trap1);


    double coord[8] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    double a = 0.0;

// проверка
    EXPECT_EQ(sq1, Square(coord, a));
    EXPECT_EQ(rec1, Rectangle(coord, a, a));
    EXPECT_EQ(trap1, Trapezoid(coord, a, a, a));

    EXPECT_EQ(sq2, Square(coord_sq1, a_sq1));
    EXPECT_EQ(rec2, Rectangle(coord_rec1, a_rec1, b_rec1));
    EXPECT_EQ(trap2, Trapezoid(coord_trap1, high_trap1, AB_trap1, CD_trap1));
}