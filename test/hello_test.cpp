#include <gtest/gtest.h>
#include "from_Decimal_to_Turkish.h"
#include <string>

TEST(ExampleOfStandartUsageTest1, BasicAssertions) {
  string inputnum = "2";

  string res = from_Decimal_to_Turkish(inputnum);

  EXPECT_EQ(res, "iki");
}

TEST(ExampleOfStandartUsageTest2, BasicAssertions) {
  string inputnum = "0";

  string res = from_Decimal_to_Turkish(inputnum);

  EXPECT_EQ(res, "sifir");
}

TEST(ExampleOfStandartUsageTest3, BasicAssertions) {
  string inputnum = "10";

  string res = from_Decimal_to_Turkish(inputnum);

  EXPECT_EQ(res, "on");
}

TEST(ExampleOfStandartUsageTest4, BasicAssertions) {
  string inputnum = "11";

  string res = from_Decimal_to_Turkish(inputnum);

  EXPECT_EQ(res, "on bir");
}

TEST(incorect, BasicAssertions) {
  string inputnum = "bs";

  string res = from_Decimal_to_Turkish(inputnum);

  EXPECT_EQ(res, "It is not a number or number not in [0;99]");
}