class SolutionInterface {
public:
  virtual int run() = 0;

protected:
  SolutionInterface() {}
  virtual void pre_calc() {}
  virtual bool action() = 0;
  virtual void init() {};
  virtual bool input() { return false; };
  virtual void output() const {};
};
