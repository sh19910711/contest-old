TEST(tuple, test1) {
  using namespace utils;
  std::tuple <Int, Int, Int> t = std::make_tuple({1, 2, 3});
  std::ostringstream oss;
  oss << v1;
  ASSERT_EQ(oss.str(), "(1, 2, 3)");
}
