#include <gtest/gtest.h>
#include "Four.h"
#include "Builder.h"
#include <string>

TEST(errorTest, BasicAssertions) {
  int n = 3;
  char x = 'd';

  EXPECT_THROW(Four test_obj(n, x), std::invalid_argument);
}

TEST(BaseConstructorTest, BasicAssertions) {
  Four test_obj {};

  EXPECT_EQ(test_obj.getArray(), nullptr);
  EXPECT_EQ(test_obj.getSize(), 0);
}

TEST(ConstructorTest2, BasicAssertions) {
  int n = 4;
  char val = '0';

  Four test_obj(n, val);
  int test_size = test_obj.getSize(); 
  unsigned char* test_arr = test_obj.getArray();
  
  unsigned char ans_arr [] = "0000";
  int ans_size = 4;
  Four ans = Builder().size(ans_size).arr(ans_arr).build();

  EXPECT_EQ(test_size, ans.getSize());
  for (int i = 0; i < test_size; i++){
    EXPECT_EQ(test_arr[i], ans.getArray()[i]);
  }

}

TEST(StringConstructorTest, BasicAssertions) {

  Four test_obj("0000");
  int test_size = test_obj.getSize(); 
  unsigned char* test_arr = test_obj.getArray();
  
  unsigned char ans_arr [] = "0000";
  int ans_size = 4;
  Four ans = Builder().size(ans_size).arr(ans_arr).build();

  EXPECT_EQ(test_size, ans.getSize());
  for (int i = 0; i < test_size; i++){
    EXPECT_EQ(test_arr[i], ans.getArray()[i]);
  }
}

TEST(StringConstructorError, BasicAssertions) {

  EXPECT_THROW(Four obj{"dafas"};, std::invalid_argument);

}

TEST(CopyConstructor, BasicAssertions){
  unsigned char ans_arr[] = "00000";
  int ans_size = 5;
  Four ans = Builder().size(ans_size).arr(ans_arr).build();

  Four test {ans};
  int test_size = test.getSize();

  EXPECT_EQ(test_size, ans.getSize());

  for (int i = 0; i<test_size; i++){
    EXPECT_EQ(test.getArray()[i], ans.getArray()[i]);
  }
}

TEST(SumTest, BasicAssertions){
  int FirstNum_size = 2;
  int SecondNum_size = 2;

  unsigned char FirstNum[] = "10";
  unsigned char SecondNum[] = "10";

  Four First = Builder().size(FirstNum_size).arr(FirstNum).build();
  Four Second = Builder().size(SecondNum_size).arr(SecondNum).build();

  unsigned char ans_arr[] = "20";
  int ans_size = 2; 


  Four res {First.operator+(Second)};
  
  EXPECT_EQ(res.getSize(), ans_size);
  for (int i = 0; i < res.getSize(); i++){
    EXPECT_EQ(res.getArray()[i], ans_arr[ans_size - i - 1]);
  }
}


TEST(SumTest2, BasicAssertions){
  int FirstNum_size = 3;
  int SecondNum_size = 2;

  unsigned char FirstNum[] = "100";
  unsigned char SecondNum[] = "10";

  Four First = Builder().size(FirstNum_size).arr(FirstNum).build();
  Four Second = Builder().size(SecondNum_size).arr(SecondNum).build();

  unsigned char ans_arr[] = "110";
  int ans_size = 3; 


  Four res {First.operator+(Second)};
  
  EXPECT_EQ(res.getSize(), ans_size);
  for (int i = 0; i < res.getSize(); i++){
    EXPECT_EQ(res.getArray()[i], ans_arr[ans_size - i - 1]);
  }
}

TEST(SubtractionTest, BasicAssertions){
  int FirstNum_size = 3;
  int SecondNum_size = 2;

  unsigned char FirstNum[] = "110";
  unsigned char SecondNum[] = "10";

  Four First = Builder().size(FirstNum_size).arr(FirstNum).build();
  Four Second = Builder().size(SecondNum_size).arr(SecondNum).build();

  unsigned char ans_arr[] = "100";
  int ans_size = 3; 


  Four res {First.operator-(Second)};
  
  EXPECT_EQ(res.getSize(), ans_size);
  for (int i = 0; i < res.getSize(); i++){
    EXPECT_EQ(res.getArray()[i], ans_arr[ans_size - i - 1]);
  }
}

TEST(SubtractionTestError, BasicAssertions){
  int FirstNum_size = 3;
  int SecondNum_size = 2;

  unsigned char FirstNum[] = "110";
  unsigned char SecondNum[] = "10";

  Four First = Builder().size(FirstNum_size).arr(FirstNum).build();
  Four Second = Builder().size(SecondNum_size).arr(SecondNum).build();

  EXPECT_THROW(Second.operator-(First);, std::logic_error);
}

TEST(EqualTest, BasicAssertions){
  int FirstNum_size = 2;
  int SecondNum_size = 2;

  unsigned char FirstNum[] = "10";
  unsigned char SecondNum[] = "10";

  Four First = Builder().size(FirstNum_size).arr(FirstNum).build();
  Four Second = Builder().size(SecondNum_size).arr(SecondNum).build();

  bool ans = First.equal(Second);

  EXPECT_EQ(ans, 1);  
}

TEST(EqualTest2, BasicAssertions){
  int FirstNum_size = 2;
  int SecondNum_size = 3;

  unsigned char FirstNum[] = "10";
  unsigned char SecondNum[] = "100";

  Four First = Builder().size(FirstNum_size).arr(FirstNum).build();
  Four Second = Builder().size(SecondNum_size).arr(SecondNum).build();

  bool ans = First.equal(Second);

  EXPECT_EQ(ans, 0);  
}

TEST(MoreTest, BasicAssertions){
  int FirstNum_size = 2;
  int SecondNum_size = 3;

  unsigned char FirstNum[] = "10";
  unsigned char SecondNum[] = "100";

  Four First = Builder().size(FirstNum_size).arr(FirstNum).build();
  Four Second = Builder().size(SecondNum_size).arr(SecondNum).build();

  bool ans = First.more(Second);

  EXPECT_EQ(ans, 0);  
}

TEST(MoreTest2, BasicAssertions){
  int FirstNum_size = 2;
  int SecondNum_size = 3;

  unsigned char FirstNum[] = "10";
  unsigned char SecondNum[] = "100";

  Four First = Builder().size(FirstNum_size).arr(FirstNum).build();
  Four Second = Builder().size(SecondNum_size).arr(SecondNum).build();

  bool ans = Second.more(First);

  EXPECT_EQ(ans, 1);  
}

TEST(LessTest, BasicAssertions){
  int FirstNum_size = 2;
  int SecondNum_size = 3;

  unsigned char FirstNum[] = "10";
  unsigned char SecondNum[] = "100";

  Four First = Builder().size(FirstNum_size).arr(FirstNum).build();
  Four Second = Builder().size(SecondNum_size).arr(SecondNum).build();

  bool ans = Second.less(First);

  EXPECT_EQ(ans, 0);  
}

TEST(LessTest1, BasicAssertions){
  int FirstNum_size = 2;
  int SecondNum_size = 3;

  unsigned char FirstNum[] = "10";
  unsigned char SecondNum[] = "100";

  Four First = Builder().size(FirstNum_size).arr(FirstNum).build();
  Four Second = Builder().size(SecondNum_size).arr(SecondNum).build();

  bool ans = First.less(Second);

  EXPECT_EQ(ans, 1);  
}



