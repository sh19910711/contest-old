class ISolution {
public:
    virtual void init() {};
    virtual bool input() { return false; };
    virtual void output() {};
    virtual int run() = 0;
};
