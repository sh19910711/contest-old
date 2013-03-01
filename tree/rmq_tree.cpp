// @snip <sh19910711/contest:tree/interface_segment_tree.cpp>
template <class T> class RMQTree: public ISegmentTree {
public:
    T INF;
    int n;
    std::vector<T> D;
    RMQTree( int n_, T INF = std::numeric_limits<T>::max() ): INF(INF) {init(n);}
    void init( int n_ ) {
        n = 1;
        while ( n < n_ ) n *= 2;
        D.resize( 2 * n - 1 );
        for ( int i = 0; i < 2 * n - 1; ++ i ) D[i] = INF;
    }
    int parent( const int k ) { return ( k - 1 ) / 2; }
    int left( const int k ) { return 2 * k + 1; }
    int right( const int k ) { return 2 * k + 2; }
    // D[k] = a;
    void update( int k, int a ) {
        k += n - 1, D[k] = a;
        while ( k > 0 ) k = parent(k), D[k] = std::min( D[left(k)], D[right(k)] );
    }
    T query( int a, int b, int k, int l, int r ) {
        if ( r <= a || b <= l ) return INF;
        if ( a <= l && r <= b ) return D[k];
        T vl = query( a, b, left(k), l, ( l + r ) / 2 );
        T vr = query( a, b, right(k), ( l + r ) / 2, r );
        return std::min( vl, vr );
    }
};
