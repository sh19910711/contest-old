namespace test {
  using namespace std;

  const int SIZE = 10;

  int cnt;

  bool each_func_1( const int& v ) {
    cnt += v;
    return true;
  }

  class each: public ::testing::Test {
  protected:
    typedef array::Array<int, SIZE> Array;
    typedef array::Collection<Array> Collection;
    Collection col;

    virtual void SetUp() {
      for ( int i = 0; i < SIZE; ++ i ) {
        col[i] = i;
      }
      cnt = 0;
    }
  };

  TEST_F(each, test1) {
    col.each(misc::Range(0, SIZE), each_func_1);
    ASSERT_EQ(cnt, 45);
  }

  TEST_F(each, test2) {
    col.each(misc::Range(1, SIZE), each_func_1);
    ASSERT_EQ(cnt, 45);
  }

  TEST_F(each, test3) {
    col.each(misc::Range(2, SIZE), each_func_1);
    ASSERT_EQ(cnt, 44);
  }

  TEST_F(each, test4) {
    col.each(misc::Range(2, SIZE - 1), each_func_1);
    ASSERT_EQ(cnt, 35);
  }

}
