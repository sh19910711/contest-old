// @snippet<sh19910711/contest:unit-tests.cpp>
#define __MY_UNIT_TEST__
#include "gtest/gtest.h"

// @snippet<sh19910711/contest:headers.cpp>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <limits>
#include <complex>
#include <functional>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include "./breadth_first_search.h"

namespace cf330d {
#include "./codeforces_330D.cpp"
}

namespace test {
  typedef cf330d::solution::Solution Solution;

  TEST(BreadthFirstSearch, codeforces_330D) {
    for ( int i = 1; i <= 9; ++ i ) {
      char input_name[256];
      char output_name[256];
      char expected_name[256];

      std::sprintf(input_name, "codeforces_330D.input.%003d.txt", i);
      std::sprintf(output_name, "codeforces_330D.output.%003d.txt", i);
      std::sprintf(expected_name, "codeforces_330D.expected.%003d.txt", i);

      {
        std::ifstream ifs(input_name);
        cf330d::solution::is = &ifs;
        std::ofstream ofs(output_name);
        cf330d::solution::os = &ofs;
        Solution sol;
        sol.run();
        ifs.close();
        ofs.close();
      }
      {
        std::ifstream ifs_output(output_name);
        std::ifstream ifs_expected(expected_name);
        std::string expected, output;
        while ( ifs_output >> output && ifs_expected >> expected ) {
          EXPECT_EQ(output, expected);
        }
      }
    }
  }
}

