#include <gtest/gtest.h>
#include "from_Вecimal_to_Greek.h"
#include <string>

TEST(ExampleOfStandartUsageTest1, BasicAssertions) {
  string inputnum = "2";

  string res = from_Becimal_to_Greek(inputnum);

  EXPECT_EQ(res, "iki");
}

TEST(ExampleOfStandartUsageTest2, BasicAssertions) {
  string inputnum = "0";

  string res = from_Becimal_to_Greek(inputnum);

  EXPECT_EQ(res, "sifir");
}

TEST(ExampleOfStandartUsageTest3, BasicAssertions) {
  string inputnum = "10";

  string res = from_Becimal_to_Greek(inputnum);

  EXPECT_EQ(res, "on");
}

TEST(ExampleOfStandartUsageTest4, BasicAssertions) {
  string inputnum = "11";

  string res = from_Becimal_to_Greek(inputnum);

  EXPECT_EQ(res, "on bir");
}

TEST(incorect, BasicAssertions) {
  string inputnum = "bs";

  string res = from_Becimal_to_Greek(inputnum);

  EXPECT_EQ(res, "error");
}