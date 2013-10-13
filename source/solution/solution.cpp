// @snip <sh19910711/contest:solution/define_classes.cpp>
// @snip <sh19910711/contest:solution/solution-base.cpp>
// @snip <sh19910711/contest:solution/typedef.cpp>
// @snip <sh19910711/contest:solution/namespace-area.cpp>
// @snip <sh19910711/contest:solution/consts-area.cpp>
// @snip <sh19910711/contest:solution/storages-area.cpp>
// @snip <sh19910711/contest:solution/solver-area.cpp>
class Solution: public SolutionBase {
public:
  Solution() {}
  Solution(Storages* p): storages(p) {}

protected:
  virtual bool action() {
    this->init();
    if ( ! this->input(*this->storages) )
      return false;
    solver.solve(*this->storages);
    this->output(*this->storages);
    return true;
  }

private:
  Solver solver;
  Storages* storages;
};
