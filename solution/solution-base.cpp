// @snip <sh19910711/contest:solution/interface.cpp>
class SolutionBase: public SolutionInterface {
public:
  virtual int run() {
    pre_calc();
    while ( action() );
    return 0;
  }

};
