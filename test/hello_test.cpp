#include <gtest/gtest.h>
#include "./../src/lab0/aloc.cpp"
#include "./../src/lab0/Vector.cpp"
#include <map>


TEST(VectorDefaultConstructor, BasicAssertions) {
    // arrange 
    int expectedSize = 0;
    // act
   MyVector::Vector<int, mai::allocator<int, 10>> vect;
    
    // assert
   EXPECT_EQ(vect.getSize(), 0);
}


TEST(PushBack, BasicAssertions) {
    // arrange 
    MyVector::Vector<int, mai::allocator<int, 10>> vect;
    int expectedSize = 1;
    // act
    vect.push_back(2);
    
    // assert
    EXPECT_EQ(vect.getSize(), 1);
    EXPECT_EQ(vect[0], 2);
}

TEST(PushBackOutOfBoundsExeption, BasicAssertions) {
    // arrange 
    MyVector::Vector<int, mai::allocator<int, 10>> vect;
    int expectedSize = 1;
    // act
    vect.push_back(2);
    
    // assert
   EXPECT_THROW(vect[12];, std::out_of_range);
}


TEST(Iterators, BasicAssertions) {
    // arrange 
    int expectedSize = 0;
    MyVector::Vector<int, mai::allocator<int, 10>> vect;
    for (int i = 0; i < 10; ++i){
        vect.push_back(i);
    }
    int res = 1;
    int i = 0;
    // act
    for (auto e : vect){
        if (e != i){
            res = 0;
            break;
        }
        i++;
    }
    
    // assert
    EXPECT_EQ(res, 1);
}

TEST(UsingAllocatorWidthMap, BasicAssertions) {
    // arrange 
     int n = 5;
    std::map<int, int, std::less<int>, mai::allocator<std::pair<const int, int>, 10>> map;

   
    int i = 1;
    // act
    for (int i = 1; i < n; ++i){
        map.insert(std::pair<int, int>(i, i+1));
    }
    
    // assert
    int res = 1;
    for (auto p : map){
        if (p.first != i || p.second != (i+1)){
            res = 0;
            break;
        }

        i++;
    }
    EXPECT_EQ(res, 1);
}