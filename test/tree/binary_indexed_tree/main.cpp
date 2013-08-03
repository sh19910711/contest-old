
// @snippet<sh19910711/contest:unit-tests.cpp>
#define __MY_UNIT_TEST__
#include <gtest/gtest.h>

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

#include "./binary_indexed_tree.h"

namespace cf331b {
#include "./codeforces_331B.cpp"
}

namespace cf228d {
#include "./codeforces_228D.cpp"
}

namespace test {
  using namespace std;

  TEST(BinaryIndexedTree, Codeforces_331B) {
    ifstream ifs_num("codeforces_331B.num.txt");
    int num = 0;
    ifs_num >> num;
    for ( int i = 1; i <= num; ++ i ) {
      char input_name[256];
      char output_name[256];
      char expect_name[256];
      sprintf(input_name, "codeforces_331B.input.%03d.txt", i);
      sprintf(output_name, "codeforces_331B.output.%03d.txt", i);
      sprintf(expect_name, "codeforces_331B.expected.%03d.txt", i);
      
      {
        ifstream ifs(input_name);
        ofstream ofs(output_name);
        cf331b::solution::is = &ifs;
        cf331b::solution::os = &ofs;
        cf331b::solution::Solution sol;
        sol.run();
      }

      {
        ifstream ifs_output(output_name);
        ifstream ifs_expect(expect_name);
        string output, expect;
        while ( ifs_output >> output && ifs_expect >> expect ) {
          EXPECT_EQ(expect, output);
        }
      }
    }
  }

  TEST(BinaryIndexedTree, Codeforces_228D) {
    ifstream ifs_num("codeforces_228D.num.txt");
    int num = 0;
    ifs_num >> num;
    for ( int i = 1; i <= num; ++ i ) {
      char input_name[256];
      char output_name[256];
      char expect_name[256];
      sprintf(input_name, "codeforces_228D.input.%03d.txt", i);
      sprintf(output_name, "codeforces_228D.output.%03d.txt", i);
      sprintf(expect_name, "codeforces_228D.expected.%03d.txt", i);
      
      {
        ifstream ifs(input_name);
        ofstream ofs(output_name);
        cf228d::solution::is = &ifs;
        cf228d::solution::os = &ofs;
        cf228d::solution::Solution sol;
        sol.run();
      }

      {
        ifstream ifs_output(output_name);
        ifstream ifs_expect(expect_name);
        string output, expect;
        while ( ifs_output >> output && ifs_expect >> expect ) {
          EXPECT_EQ(expect, output);
        }
      }
    }
  }

}

