#define DEFINE_TEST(CATEGORY, NAMESPACE) \
  namespace test_NAMESPACE { \
    using namespace std; \
    TEST(CATEGORY, NAMESPACE) { \
      ifstream ifs_num(#NAMESPACE "/num.txt"); \
      int num = 0; \
      ifs_num >> num; \
      for ( int i = 1; i <= num; ++ i ) { \
        char input_name[256]; \
        char output_name[256]; \
        char expect_name[256]; \
        sprintf(input_name, #NAMESPACE "/input.%03d.txt", i); \
        sprintf(output_name, #NAMESPACE "/output.%03d.txt", i); \
        sprintf(expect_name, #NAMESPACE "/expected.%03d.txt", i); \
        { \
          ifstream ifs(input_name); \
          ofstream ofs(output_name); \
          NAMESPACE::solution::is = &ifs; \
          NAMESPACE::solution::os = &ofs; \
          NAMESPACE::solution::Solution sol; \
          sol.run(); \
        } \
        { \
          ifstream ifs_output(output_name); \
          ifstream ifs_expect(expect_name); \
          string output, expect; \
          while ( ifs_output >> output && ifs_expect >> expect ) { \
            EXPECT_EQ(expect, output); \
          } \
        } \
      } \
    } \
  } 

#define DEFINE_INPUT_TEST(CATEGORY, NAMESPACE, TEST_NO) \
  namespace test_NAMESPACE { \
    using namespace std; \
    TEST(CATEGORY, NAMESPACE ## _ ## TEST_NO) { \
      char input_name[256]; \
      char output_name[256]; \
      char expect_name[256]; \
      sprintf(input_name, #NAMESPACE "/input." #TEST_NO ".txt"); \
      sprintf(output_name, #NAMESPACE "/output." #TEST_NO ".txt"); \
      sprintf(expect_name, #NAMESPACE "/expected." #TEST_NO ".txt"); \
      { \
        ifstream ifs(input_name); \
        ofstream ofs(output_name); \
        NAMESPACE::solution::istream_pointer = &ifs; \
        NAMESPACE::solution::ostream_pointer = &ofs; \
        NAMESPACE::solution::Solution sol; \
        sol.run(); \
      } \
      { \
        ifstream ifs_output(output_name); \
        ifstream ifs_expect(expect_name); \
        string output, expect; \
        while ( ifs_output >> output && ifs_expect >> expect ) { \
          EXPECT_EQ(expect, output); \
        } \
      } \
    } \
  } 
