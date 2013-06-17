// @snip <sh19910711/contest:solution/interface.cpp>
class SolutionBase: public ISolution {
public:
  virtual int run() {
    int test_no = 0;
    while ( action( test_no ++ ) );
    return 0;
  }

};
