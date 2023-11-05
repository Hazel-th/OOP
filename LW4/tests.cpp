#include<gtest/gtest.h>
#include"Figure.h"
#include"Square.h"
#include"Rectangle.h"
#include"Trapezoid.h"

TEST(test_1, AllMetods)
{   
// квадрат
    std::pair<double, double> coord_sq1[4] = {{2.0, 4.0}, {4.0, 4.0}, {4.0, 2.0}, {2.0, 2.0}};
    double a_sq1 = 2.0;
    Square<double> sq1(coord_sq1, a_sq1);

    std::pair<double, double> coord_sq2[4] = {{-2.0, 2.0}, {0.0, 2.0}, {0.0, 0.0}, {-2.0, 0.0}};
    double a_sq2 = 2.0;
    Square<double> sq2(coord_sq2, a_sq2);

    double get_area1 = sq1.get_area();
    double expect_get_area1 = 4;
    double get_area2 = sq2.get_area();
    double expect_get_area2 = 4;

    std::pair<double, double> centre_1 = sq1.get_centre();
    std::pair<double, double> expect_centre_1 = {3, 3};
    std::pair<double, double> centre_2 = sq2.get_centre();
    std::pair<double, double> expect_centre_2 = {-1, 1};

// проверка

    ASSERT_EQ(get_area1, expect_get_area1);
    ASSERT_EQ(get_area2, expect_get_area2);

    ASSERT_EQ(centre_1, expect_centre_1);
    ASSERT_EQ(centre_2, expect_centre_2);

    EXPECT_TRUE(sq1 == sq2);

}

TEST(test_2, AllMetods)
{   
// прямоугольник
    std::pair<double, double> coord_rec1[4] = {{1.0, 4.0}, {3.0, 4.0}, {3.0, 1.0}, {1.0, 1.0}};
    double a_rec1 = 2.0;
    double b_rec1 = 3.0;
    Rectangle<double> rec1(coord_rec1, a_rec1, b_rec1);

    std::pair<double, double> coord_rec2[4] = {{1.0, 1.0}, {2.0, 1.0}, {2.0, -1.0}, {1.0, -1.0}};
    double a_rec2 = 1.0;
    double b_rec2 = 2.0;
    Rectangle<double> rec2(coord_rec2, a_rec2, b_rec2);

    double get_area1 = rec1.get_area();
    double expect_get_area1 = 6;
    double get_area2 = rec2.get_area();
    double expect_get_area2 = 2;

    std::pair<double, double> centre_1 = rec1.get_centre();
    std::pair<double, double> expect_centre1 = {2.0, 2.5};
    std::pair<double, double> centre_2 = rec2.get_centre();
    std::pair<double, double> expect_centre2 = {1.5, 0.0};

// проверка

    ASSERT_EQ(get_area1, expect_get_area1);
    ASSERT_EQ(get_area2, expect_get_area2);

    ASSERT_EQ(centre_1, expect_centre1);
    ASSERT_EQ(centre_2, expect_centre2);

    EXPECT_FALSE(rec1 == rec2);

}

TEST(test_3, AllMetods)
{   
// трапеция
    std::pair<double, double> coord_trap1[4] = {{2.0, 3.0}, {4.0, 3.0}, {5.0, 1.0}, {1.0, 1.0}};
    double high_trap1 = 2.0;
    double AB_trap1 = 2.0;
    double CD_trap1 = 4.0;
    Trapezoid<double> trap1(coord_trap1, AB_trap1, CD_trap1, high_trap1);

    std::pair<double, double> coord_trap2[4] = {{3.0, -1.0}, {4.0, -1.0}, {6.0, -3.0}, {1.0, -3.0}};
    double high_trap2 = 2.0;
    double AB_trap2 = 1.0;
    double CD_trap2 = 5.0;
    Trapezoid<double> trap2(coord_trap2, AB_trap2, CD_trap2, high_trap2);

    double get_area1 = trap1.get_area();
    double expect_get_area1 = 6;
    double get_area2 = trap2.get_area();
    double expect_get_area2 = 6;

    std::pair<double, double> centre_1 = trap1.get_centre();
    std::pair<double, double> expect_centre1 = {3.0, 2.0};
    std::pair<double, double> centre_2 = trap2.get_centre();
    std::pair<double, double> expect_centre2 = {3.5, -2.0};

// проверка

    ASSERT_EQ(get_area1, expect_get_area1);
    ASSERT_EQ(get_area2, expect_get_area2);

    ASSERT_EQ(centre_1, expect_centre1);
    ASSERT_EQ(centre_2, expect_centre2);

    EXPECT_FALSE(trap1 == trap2);

}

TEST(test_4, COPY)
{   
// квадрат
    std::pair<double, double> coord_sq1[4] = {{2.0, 4.0}, {4.0, 4.0}, {4.0, 2.0}, {2.0, 2.0}};
    double a_sq1 = 2.0;
    Square<double> sq1(coord_sq1, a_sq1);

    std::pair<double, double> coord_sq2[4] = {{-2.0, 2.0}, {0.0, 2.0}, {0.0, 0.0}, {-2.0, 0.0}};
    double a_sq2 = 2.0;
    Square<double> sq2(coord_sq2, a_sq2);

    sq2 = sq1;

// прямоугольник
    std::pair<double, double> coord_rec1[4] = {{1.0, 4.0}, {3.0, 4.0}, {3.0, 1.0}, {1.0, 1.0}};
    double a_rec1 = 2.0;
    double b_rec1 = 3.0;
    Rectangle<double> rec1(coord_rec1, a_rec1, b_rec1);

    std::pair<double, double> coord_rec2[4] = {{1.0, 1.0}, {2.0, 1.0}, {2.0, -1.0}, {1.0, -1.0}};
    double a_rec2 = 1.0;
    double b_rec2 = 2.0;
    Rectangle<double> rec2(coord_rec2, a_rec2, b_rec2);

    rec2 = rec1;

// трапеция
    std::pair<double, double> coord_trap1[4] = {{2.0, 3.0}, {4.0, 3.0}, {5.0, 1.0}, {1.0, 1.0}};
    double high_trap1 = 2.0;
    double AB_trap1 = 2.0;
    double CD_trap1 = 4.0;
    Trapezoid<double> trap1(coord_trap1, AB_trap1, CD_trap1, high_trap1);

    std::pair<double, double> coord_trap2[4] = {{3.0, -1.0}, {4.0, -1.0}, {6.0, -3.0}, {1.0, -3.0}};
    double high_trap2 = 2.0;
    double AB_trap2 = 1.0;
    double CD_trap2 = 5.0;
    Trapezoid<double> trap2(coord_trap2, AB_trap2, CD_trap2, high_trap2);

    trap2 = trap1;

// проверка
    EXPECT_EQ(sq1, Square(coord_sq1, a_sq1));
    EXPECT_EQ(rec1, Rectangle(coord_rec1, a_rec1, b_rec1));
    EXPECT_EQ(trap1, Trapezoid(coord_trap1, AB_trap1, CD_trap1, high_trap1));

    EXPECT_EQ(sq2, Square(coord_sq1, a_sq1));
    EXPECT_EQ(rec2, Rectangle(coord_rec1, a_rec1, b_rec1));
    EXPECT_EQ(trap2, Trapezoid(coord_trap1, AB_trap1, CD_trap1, high_trap2));
}

TEST(test_5, Move)
{   
// квадрат
     std::pair<double, double> coord_sq1[4] = {{2.0, 4.0}, {4.0, 4.0}, {4.0, 2.0}, {2.0, 2.0}};
    double a_sq1 = 2.0;
    Square<double> sq1(coord_sq1, a_sq1);

    std::pair<double, double> coord_sq2[4] = {{-2.0, 2.0}, {0.0, 2.0}, {0.0, 0.0}, {-2.0, 0.0}};
    double a_sq2 = 2.0;
    Square<double> sq2(coord_sq2, a_sq2);

    sq2 = std::move (sq1);

// прямоугольник
    std::pair<double, double> coord_rec1[4] = {{1.0, 4.0}, {3.0, 4.0}, {3.0, 1.0}, {1.0, 1.0}};
    double a_rec1 = 2.0;
    double b_rec1 = 3.0;
    Rectangle<double> rec1(coord_rec1, a_rec1, b_rec1);

    std::pair<double, double> coord_rec2[4] = {{1.0, 1.0}, {2.0, 1.0}, {2.0, -1.0}, {1.0, -1.0}};
    double a_rec2 = 1.0;
    double b_rec2 = 2.0;
    Rectangle<double> rec2(coord_rec2, a_rec2, b_rec2);


    rec2 = std::move (rec1);

// трапеция
    std::pair<double, double> coord_trap1[4] = {{2.0, 3.0}, {4.0, 3.0}, {5.0, 1.0}, {1.0, 1.0}};
    double high_trap1 = 2.0;
    double AB_trap1 = 2.0;
    double CD_trap1 = 4.0;
    Trapezoid<double> trap1(coord_trap1, AB_trap1, CD_trap1, high_trap1);

    std::pair<double, double> coord_trap2[4] = {{3.0, -1.0}, {4.0, -1.0}, {6.0, -3.0}, {1.0, -3.0}};
    double high_trap2 = 2.0;
    double AB_trap2 = 1.0;
    double CD_trap2 = 5.0;
    Trapezoid<double> trap2(coord_trap2, AB_trap2, CD_trap2, high_trap2);

    trap2 = std::move (trap1);


    std::pair<double, double> coord[4] = {{0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}};
    double a = 0.0;

// проверка
    EXPECT_EQ(sq1, Square(coord, a));
    EXPECT_EQ(rec1, Rectangle(coord, a, a));
    EXPECT_EQ(trap1, Trapezoid(coord, a, a, a));

    EXPECT_EQ(sq2, Square(coord_sq1, a_sq1));
    EXPECT_EQ(rec2, Rectangle(coord_rec1, a_rec1, b_rec1));
    EXPECT_EQ(trap2, Trapezoid(coord_trap1, AB_trap1, CD_trap1, high_trap1));
}