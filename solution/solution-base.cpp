// @snip <sh19910711/contest:solution/interface.cpp>
class SolutionBase: public SolutionInterface {
public:
  virtual ~SolutionBase() {}
  virtual int run() {
    this->pre_calc();
    while () {
      this->before_action(-1);
      this->action();
      this->after_action(-1);
    };
    return 0;
  }
protected:
  SolutionBase() {}
};
