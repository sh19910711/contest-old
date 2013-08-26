// @snip <sh19910711/contest:solution/interface.cpp>
class SolutionBase: public SolutionInterface {
public:
  virtual ~SolutionBase() {}
  virtual int run() {
    this->pre_calc();
    while ( this->action() );
    return 0;
  }
protected:
  SolutionBase() {}
};
