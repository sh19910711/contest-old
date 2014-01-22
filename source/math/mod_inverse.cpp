// @snip <sh19910711/contest:math/extgcd.cpp>
// @desc mod mでaの逆元を求める
template <class T> T mod_inverse( T a, T m ) {
    T x, y;
    extgcd( a, m, x, y );
    x %= m;
    while ( x < 0 )
        x += m;
    return x;
}
