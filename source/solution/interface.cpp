class SolutionInterface {
public:
  virtual ~SolutionInterface() {};
  virtual int run() = 0;

protected:
  SolutionInterface() {}
  virtual bool action() = 0;
  virtual bool input( InputStorage& s ) { return false; };
  virtual void output( const OutputStorage& s ) const {};
  virtual void before_all_actions() {}
  virtual void after_all_actions() {}
  virtual void before_action( const int& test_no ) const {}
  virtual void after_action( const int& test_no ) const {}
};
