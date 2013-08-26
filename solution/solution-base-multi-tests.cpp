// @snip <sh19910711/contest:solution/interface.cpp>
class SolutionBase: public SolutionInterface {
public:
  virtual ~SolutionBase() {}
  virtual int run() {
    int tests = 0;
    std::cin >> tests;
    for ( int i = 0; i < tests; ++ i ) {
      this->action();
    }
    return 0;
  }
protected:
  SolutionBase() {}
};
