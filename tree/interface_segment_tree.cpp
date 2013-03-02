template <class T> class ISegmentTree {
public:
    virtual void init( int n ) {}
    virtual T update( int k, T a ) = 0;
};
