template <class T> T gcd( T a, T b ) {
    T i, j;
    for ( i = 0; ! ( a & 1 ); ++ i ) a >>= 1;
    for ( j = 0; ! ( b & 1 ); ++ j ) b >>= 1;
    while ( b != a ) {
        b -= a;
        if ( b < 0 ) a += b, b = -b;
        while ( ! ( b & 1 ) ) b >>= 1;
    }
    return a << std::min( i, j );
}
