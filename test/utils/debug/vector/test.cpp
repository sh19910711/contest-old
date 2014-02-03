TEST(vector, test1) {
  using namespace utils;
  std::vector<int> v1;
  v1.push_back(1);
  v1.push_back(2);
  v1.push_back(3);
  v1.push_back(4);
  std::ostringstream oss;
  oss << v1;
  ASSERT_EQ(oss.str(), "1, 2, 3, 4");
}
