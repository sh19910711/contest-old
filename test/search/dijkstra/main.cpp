
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

#include "./dijkstra.h"
#include "define_test.h"

namespace uva10801 {
#include "./uva10801/main.cpp"
}

DEFINE_TEST(Dijkstra, uva10801)


