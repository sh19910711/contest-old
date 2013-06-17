// @snip <sh19910711/contest:solution/solution-base.cpp>
// @snip <sh19910711/contest:solution/typedef.cpp>
// @snip <sh19910711/contest:solution/namespace-area.cpp>
// @snip <sh19910711/contest:solution/variables-area.cpp>
// @snip <sh19910711/contest:solution/solver-area.cpp>
class Solution: public SolutionBase {
public:
protected:
  virtual bool action( int test_no ) {
    init();
    if ( ! input() )
      return false;
    solver.solve();
    output();
    return true;
  }

private:
  Solver solver;

};
