#include <iostream>

namespace test1 {
  using namespace std;
  TEST(Array, test1) {
    const int SIZE = 10;
    storage::Array<int, SIZE> A;
    for ( int i = 0; i < 10; ++ i ) {
      A[i] = i;
    }
    ASSERT_EQ(A[0], 0);
    ASSERT_EQ(A[1], 1);
    ASSERT_EQ(A[2], 2);
    ASSERT_EQ(A[3], 3);
    ASSERT_EQ(A[4], 4);
    ASSERT_EQ(A[5], 5);
    ASSERT_EQ(A[6], 6);
    ASSERT_EQ(A[7], 7);
    ASSERT_EQ(A[8], 8);
    ASSERT_EQ(A[9], 9);
  }
}

/*
 *  # Example
 *
 *  int add( int x, int y ) {
 *    return x + y;
 *  }
 *
 *  TEST(AddTest, Test1) {
 *    ASSERT_EQ(2, add(1, 1));
 *  }
 */


