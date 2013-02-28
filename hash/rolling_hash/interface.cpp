template <class T> class IRollingHash {
public:
    virtual void init() {};
    virtual void pushBack( int c ) {};
    virtual void popBack() {};
    virtual void pushFront( int c ) {};
    virtual void popFront() {};
    virtual T getHash() = 0;
};
