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
    if ( ! this->input(this->storages->in) )
      return false;
    this->output(solver.solve(this->storages->in, this->storages->out, this->storages->data));
    return true;
  }

private:
  Solver solver;
  Storages* storages;
};
