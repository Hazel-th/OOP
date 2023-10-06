#include <gtest/gtest.h>
#include "twelve.h"

TEST(test_1, AllMetods)
{
	Twelve a("123");
    Twelve b("2");

	size_t sizea = a.GetSize();
	size_t expectSizea = 3;
    size_t sizeb = b.GetSize();
	size_t expectSizeb = 1;

	unsigned char* numsa = a.GetNums();
	unsigned char expectNumsa[] = {'3', '2', '1'};
    unsigned char* numsb = b.GetNums();
	unsigned char expectNumsb[] = {'2'};

    int to_10a = a.translate_to_10();
    int expectto_10a = 171;
    int to_10b = b.translate_to_10();
    int expectto_10b = 2;
    
    std::string ab = a.plus(b);
    std::string expectab = ("125");
    std::string a_b = a.minus(b);
    std::string expecta_b = ("121");
    std::string b_a = b.minus(a);
    std::string expectb_a = ("negative number");

    std::string aab = a.bigger(b);
    std::string expectaab = ("true");
    std::string abb = a.smaller(b);
    std::string expectabb = ("false");
    std::string aabb = a.equally(b);
    std::string expectaabb = ("false");

// проверка
    ASSERT_EQ(sizea, expectSizea);
    ASSERT_EQ(sizeb, expectSizeb);

	for (size_t q = 0; q < sizea; q++) 
		ASSERT_EQ(numsa[q], expectNumsa[q]);
    for (size_t q = 0; q < sizeb; q++) 
		ASSERT_EQ(numsb[q], expectNumsb[q]);

    ASSERT_EQ(to_10a, expectto_10a);
    ASSERT_EQ(to_10b, expectto_10b);

    ASSERT_EQ(ab, expectab);
    ASSERT_EQ(a_b, expecta_b);
    ASSERT_EQ(b_a, expectb_a);

    ASSERT_EQ(aab, expectaab);
    ASSERT_EQ(abb, expectabb);
    ASSERT_EQ(aabb, expectaabb);

}

TEST(test_2, AllMetods)
{
	Twelve a({'B', 'A', '0'});
    Twelve b({'A', '9', 'B'});

	size_t sizea = a.GetSize();
	size_t expectSizea = 3;
    size_t sizeb = b.GetSize();
	size_t expectSizeb = 3;

	unsigned char* numsa = a.GetNums();
	unsigned char expectNumsa[] = {'0', 'A', 'B'};
    unsigned char* numsb = b.GetNums();
	unsigned char expectNumsb[] = {'B', '9', 'A'};

    int to_10a = a.translate_to_10();
    int expectto_10a = 1704;
    int to_10b = b.translate_to_10();
    int expectto_10b = 1559;
    
    std::string ab = a.plus(b);
    std::string expectab = ("1A7B");
    std::string a_b = a.minus(b);
    std::string expecta_b = ("101");
    std::string b_a = b.minus(a);
    std::string expectb_a = ("negative number");

    std::string aab = a.bigger(b);
    std::string expectaab = ("true");
    std::string abb = a.smaller(b);
    std::string expectabb = ("false");
    std::string aabb = a.equally(b);
    std::string expectaabb = ("false");

// проверка
    ASSERT_EQ(sizea, expectSizea);
    ASSERT_EQ(sizeb, expectSizeb);

	for (size_t q = 0; q < sizea; q++) 
		ASSERT_EQ(numsa[q], expectNumsa[q]);
    for (size_t q = 0; q < sizeb; q++) 
		ASSERT_EQ(numsb[q], expectNumsb[q]);

    ASSERT_EQ(to_10a, expectto_10a);
    ASSERT_EQ(to_10b, expectto_10b);

    ASSERT_EQ(ab, expectab);
    ASSERT_EQ(a_b, expecta_b);
    ASSERT_EQ(b_a, expectb_a);

    ASSERT_EQ(aab, expectaab);
    ASSERT_EQ(abb, expectabb);
    ASSERT_EQ(aabb, expectaabb);

}

TEST(test_3, AllMetods)
{
	Twelve a({'9', '8'});
    Twelve b("B450");

	size_t sizea = a.GetSize();
	size_t expectSizea = 2;
    size_t sizeb = b.GetSize();
	size_t expectSizeb = 4;

	unsigned char* numsa = a.GetNums();
	unsigned char expectNumsa[] = {'8', '9'};
    unsigned char* numsb = b.GetNums();
	unsigned char expectNumsb[] = {'0', '5', '4', 'B'};

    int to_10a = a.translate_to_10();
    int expectto_10a = 116;
    int to_10b = b.translate_to_10();
    int expectto_10b = 19644;
    
    std::string ab = a.plus(b);
    std::string expectab = ("B528");
    std::string a_b = a.minus(b);
    std::string expecta_b = ("negative number");
    std::string b_a = b.minus(a);
    std::string expectb_a = ("B374");

    std::string aab = a.bigger(b);
    std::string expectaab = ("false");
    std::string abb = a.smaller(b);
    std::string expectabb = ("true");
    std::string aabb = a.equally(b);
    std::string expectaabb = ("false");

// проверка
    ASSERT_EQ(sizea, expectSizea);
    ASSERT_EQ(sizeb, expectSizeb);

	for (size_t q = 0; q < sizea; q++) 
		ASSERT_EQ(numsa[q], expectNumsa[q]);
    for (size_t q = 0; q < sizeb; q++) 
		ASSERT_EQ(numsb[q], expectNumsb[q]);

    ASSERT_EQ(to_10a, expectto_10a);
    ASSERT_EQ(to_10b, expectto_10b);

    ASSERT_EQ(ab, expectab);
    ASSERT_EQ(a_b, expecta_b);
    ASSERT_EQ(b_a, expectb_a);

    ASSERT_EQ(aab, expectaab);
    ASSERT_EQ(abb, expectabb);
    ASSERT_EQ(aabb, expectaabb);

}

TEST(test_4, AllMetods)
{
	Twelve a("9");
    Twelve b("9");

	size_t sizea = a.GetSize();
	size_t expectSizea = 1;
    size_t sizeb = b.GetSize();
	size_t expectSizeb = 1;

	unsigned char* numsa = a.GetNums();
	unsigned char expectNumsa[] = {'9'};
    unsigned char* numsb = b.GetNums();
	unsigned char expectNumsb[] = {'9'};

    int to_10a = a.translate_to_10();
    int expectto_10a = 9;
    int to_10b = b.translate_to_10();
    int expectto_10b = 9;
    
    std::string ab = a.plus(b);
    std::string expectab = ("16");
    std::string a_b = a.minus(b);
    std::string expecta_b = ("0");
    std::string b_a = b.minus(a);
    std::string expectb_a = ("0");

    std::string aab = a.bigger(b);
    std::string expectaab = ("false");
    std::string abb = a.smaller(b);
    std::string expectabb = ("false");
    std::string aabb = a.equally(b);
    std::string expectaabb = ("true");

// проверка
    ASSERT_EQ(sizea, expectSizea);
    ASSERT_EQ(sizeb, expectSizeb);

	for (size_t q = 0; q < sizea; q++) 
		ASSERT_EQ(numsa[q], expectNumsa[q]);
    for (size_t q = 0; q < sizeb; q++) 
		ASSERT_EQ(numsb[q], expectNumsb[q]);

    ASSERT_EQ(to_10a, expectto_10a);
    ASSERT_EQ(to_10b, expectto_10b);

    ASSERT_EQ(ab, expectab);
    ASSERT_EQ(a_b, expecta_b);
    ASSERT_EQ(b_a, expectb_a);

    ASSERT_EQ(aab, expectaab);
    ASSERT_EQ(abb, expectabb);
    ASSERT_EQ(aabb, expectaabb);

}

TEST(test_5, InvalidArgument)
{

    ASSERT_THROW(Twelve("-1765"), std::invalid_argument);
}

TEST(test_6, InvalidArgument)
{

    ASSERT_THROW(Twelve("q0w"), std::invalid_argument);
}

TEST(test_7, InvalidArgument)
{

    ASSERT_THROW(Twelve("Пгш"), std::invalid_argument);
}

TEST(test_8, InvalidArgument)
{

    ASSERT_THROW(Twelve({'7', '8', 'R', 'Y'}), std::invalid_argument);
}

TEST(test_9, InvalidArgument)
{

    ASSERT_THROW(Twelve({'*', '7', '6', '5', '5'}), std::invalid_argument);
}

TEST(test_10, InvalidArgument)
{

    ASSERT_THROW(Twelve("76A-9"), std::invalid_argument);
}