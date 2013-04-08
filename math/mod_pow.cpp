template<class T> T mod_pow( T x, T n, T mod ) {
    if ( n == 0 ) return 1;
    T res = mod_pow( x * x % mod, n / 2, mod );
    if ( n & 1 ) res = res * x % mod;
    return res;
}
