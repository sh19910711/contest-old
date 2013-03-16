// @snip <sh19910711/contest:hash/rolling_hash/interface.cpp>
// LIFOなローリングハッシュの実装, unsigned long longの溢れを利用
class RollingHash: public hash::rolling_hash::IRollingHash<unsigned long long> {
public:
    typedef unsigned long long ULL;
    int n, k;
    ULL b, *base, *hash;
    void init( int n_ ) {
        n = n_;
        k = 0;
        base = new ULL[n];
        hash = new ULL[n];
        base[0] = 1;
        for ( int i = 0; i < n; ++ i ) base[i+1] = base[i] * b;
        hash[k] = 0;
    }
    void push( const int& c ) { hash[k+1] = hash[k] + c * base[k]; }
    RollingHash( int n, ULL b ): b(b) { init(n); }
    ULL& get_base( const int& a ) { return base[a]; }
    ULL& operator []( const int& a ) { return hash[a]; }
};
