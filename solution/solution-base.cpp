// @snip <sh19910711/contest:solution/interface.cpp>
class SolutionBase: public ISolution {
public:
  virtual int run() {
    while ( action() );
    return 0;
  }

};
