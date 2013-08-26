class SolutionInterface {
public:
  virtual ~SolutionInterface() {};
  virtual int run() = 0;

protected:
  SolutionInterface() {}
  virtual void pre_calc() {}
  virtual bool action() = 0;
  virtual void init() {};
  virtual bool input( Storages& s ) { return false; };
  virtual void output( const Storages& s ) const {};
};
