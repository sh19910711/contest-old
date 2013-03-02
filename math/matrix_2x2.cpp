template <class T> class Matrix2x2 {
public:
    T mat[2][2];
    Matrix2x2() {};
    Matrix2x2( T a, T b, T c, T d ) { mat[0][0] = f(a), mat[0][1] = f(b), mat[1][0] = f(c), mat[1][1] = f(d); }
    friend Matrix2x2 operator *( const Matrix2x2& left, const Matrix2x2& right ) {
        return Matrix2x2( 
                f( f( left.mat[0][0] * right.mat[0][0] ) + f( left.mat[0][1] * right.mat[1][0] ) ),
                f( f( left.mat[0][0] * right.mat[0][1] ) + f( left.mat[0][1] * right.mat[1][1] ) ),
                f( f( left.mat[1][0] * right.mat[0][0] ) + f( left.mat[1][1] * right.mat[1][0] ) ),
                f( f( left.mat[1][0] * right.mat[0][1] ) + f( left.mat[1][1] * right.mat[1][1] ) ) );
    }
    Matrix2x2& operator =( const Matrix2x2& right ) {
        for ( int i = 0; i < 2; ++ i ) for ( int j = 0; j < 2; ++ j ) mat[i][j] = right.mat[i][j];
        return *this;
    }
    static T f( const T& n ) { return n; }
};
template<class U, class V> Matrix2x2<U> modpow( const Matrix2x2<U>& mat, V n ) {
    if ( n == 1 ) return mat; if ( n % 2 == 0 ) return modpow( mat * mat, n / 2 );
    return modpow( mat * mat, n / 2 ) * mat;
}
