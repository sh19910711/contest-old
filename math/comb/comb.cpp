const int MOD = 1000000000 + 7;
const int SIZE = 1001;
long long C[SIZE][SIZE];
void init() {
    for ( int i = 0; i < SIZE; ++ i ) {
        for ( int j = 0; j <= i; ++ j ) {
            if ( j == 0 || j == i )
                C[i][j] = 1;
            else
                C[i][j] = ( C[i-1][j-1] + C[i-1][j] ) % MOD;
        }
    }
}
long long calc( int n, int r ) {
    return C[n][r];
}
