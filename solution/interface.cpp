class ISolution {
public:
  virtual int run() = 0;

protected:
  virtual bool action() = 0;
  virtual void init() {};
  virtual bool input() { return false; };
  virtual void output() {};

};
