TEST(max, MAX_A_B_CHANGE) {
  int a = 1;
  int b = 3;
  utils::max(a, b);
  ASSERT_EQ(a, 3);
}

TEST(max, MAX_A_B_UNCHANGE) {
  int a = 3;
  int b = 1;
  utils::max(a, b);
  ASSERT_EQ(a, 3);
}

TEST(min, MIN_A_B_CHANGE) {
  int a = 3;
  int b = 1;
  utils::min(a, b);
  ASSERT_EQ(a, 1);
}

TEST(min, MIN_A_B_UNCHANGE) {
  int a = 1;
  int b = 3;
  utils::min(a, b);
  ASSERT_EQ(a, 1);
}

TEST(to_string, test1) {
  int a = 12345;
  ASSERT_EQ(
    utils::to_string(a),
    "12345"
  );
}

TEST(to_type, test1) {
  ASSERT_EQ(
    utils::to_type<int>("12345"),
    12345
  );
}

