// @desc 素数判定用の配列を生成する。P[i] = iが素数かどうか
void prime_init( bool* P, const int& SIZE ) {
    std::fill( P, P+SIZE, false );
    for ( int i = 3; i < SIZE; i += 2 )
        P[i] = true;
    P[2] = true;
    for ( int i = 3; i < SIZE; i += 2 ) {
        if ( P[i] )
            for ( int j = i + i; j < SIZE; j += i )
                P[j] = false;
    }
}
