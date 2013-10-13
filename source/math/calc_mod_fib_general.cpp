// @snippet<sh19910711/contest:math/matrix_2x2.cpp>
template <class T> T CalcModFibGeneral( T first, T second, T n, T mod ) {
  if ( n == 0 ) return first;
  if ( n == 1 ) return second;
  Matrix2x2<T> mat( 1, 1, 1, 0 );
  mat = modpow( mat, n );
  return ( ( mat.mat[1][0] * first ) % mod + ( mat.mat[0][0] * second ) % mod + 2 * mod ) % mod;
}

