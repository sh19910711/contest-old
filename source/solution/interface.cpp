struct InputStorage;
struct OutputStorage;
struct Storages {
  InputStorage* in;
  OutputStorage* out;
};
class SolverInterface {
public:
  virtual const OutputStorage* solve( const InputStorage* in, OutputStorage* out ) = 0;
};
class SolutionInterface {
public:
  virtual ~SolutionInterface() {};
  virtual int run() = 0;
  SolverInterface* solver;
  Storages* storages;
protected:
  virtual bool input( InputStorage* s ) = 0;
  virtual void output( const OutputStorage* s ) = 0; 
  virtual void before_all_actions() {}
  virtual void after_all_actions() {}
  virtual void before_action( const int& test_no ) {}
  virtual void after_action( const int& test_no ) {}
  virtual bool action() {
    if ( ! this->input(this->storages->in) ) {
      return false;
    }
    this->output(solver->solve(this->storages->in, this->storages->out));
    return true;
  }
};
