// @snip <sh19910711/contest:solution/solution-base.cpp>
// @snip <sh19910711/contest:storage/vector.cpp>
// @snip <sh19910711/contest:storage/vector_types.cpp>
// @snip <sh19910711/contest:solution/typedef.cpp>
// @snip <sh19910711/contest:solution/namespace-area.cpp>
// @snip <sh19910711/contest:solution/consts-area.cpp>
// @snip <sh19910711/contest:solution/storages-area.cpp>
// @snip <sh19910711/contest:solution/solver-area.cpp>
class Solution: public SolutionBase {
public:
protected:
  virtual bool action() {
    init();
    if ( ! input() )
      return false;
    solver.solve();
    output();
    return true;
  }

  Solver solver;

private:

};
