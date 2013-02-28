// @snip <sh19910711/contest:hash/rolling_hash/interface.cpp>
// @snip <sh19910711/contest:math/mod_inverse.cpp>
class RollingHash: public IRollingHash<long long> {
public:
    typedef long long LL;
    LL B, MOD, hash, bases, mod, b_inv;
    std::deque<int> Q;
    RollingHash( LL B, LL MOD ): B(B), MOD(MOD) { init(); }
    void init() {
        hash = 0, bases = 1, b_inv = math::mod_inverse( B, MOD ) % MOD;
        Q.clear();
    }
    void pushBack( int c ) {
        hash = ( hash * B + c ) % MOD, bases = ( bases * B ) % MOD;
        Q.push_back(c);
    }
    void popBack() {
        char c = Q.back();
        hash = ( ( hash - c + MOD ) % MOD * b_inv ) % MOD;
        bases = ( bases * b_inv ) % MOD;
        Q.pop_back();
    }
    void pushFront( int c ) {
        hash = ( hash + ( c * bases ) % MOD ) % MOD;
        bases = ( bases * B ) % MOD;
        Q.push_front(c);
    }
    void popFront() {
        char c = Q.front();
        hash = ( hash - ( bases * b_inv * c ) % MOD + MOD ) % MOD;
        bases = ( bases * b_inv ) % MOD;
        Q.pop_front();
    }
    void init( std::string s ) { int n = s.size(); for ( int i = 0; i < n; ++ i ) pushBack(s[i]); }
    long long getHash() { return hash; }
};
