// Segment Tree の実装
template <class T> class ISegmentTree {
public:
    virtual void init( int n ) {}
    virtual void update( int k, T a ) = 0;
};
