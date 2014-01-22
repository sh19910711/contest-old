// 拡張ユークリッド互除法: a*x+b*y=gcd(x,y)
template <class T> T extgcd( T a, T b, T& x, T& y ) {
    for ( T u = y = 1, v = x = 0; a; ) {
        T q = b / a;
        std::swap( x -= q * u, u );
        std::swap( y -= q * v, v );
        std::swap( b -= q * a, a );
    }
    return b;
}
