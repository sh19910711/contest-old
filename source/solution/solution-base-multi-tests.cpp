// @snip <sh19910711/contest:solution/interface.cpp>
class SolutionBase: public SolutionInterface {
public:
  virtual ~SolutionBase() {}; 
  virtual int run() {
    int tests = 0;
    std::cin >> tests;
    this->before_all_actions();
    for ( int i = 0; i < tests; ++ i ) {
      this->before_action(i);
      this->action();
      this->after_action(i);
    }
    this->after_all_actions();
    return 0;
  }
};
