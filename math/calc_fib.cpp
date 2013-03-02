// @snip<sh19910711/contest:math/matrix_2x2.cpp>
template <class T, class U> T calc_fib( U n ) {
    if ( n == 0 ) return 0;
    if ( n == 1 ) return 1;
    Matrix2x2<T> mat( 1, 1, 1, 0 );
    mat = modpow( mat, n - 1 );
    return mat.mat[0][0] % mod;
}
