template <class T> T lcm( T a, T b ) {
    T larger = a > b ? a : b;
    T smaller = a > b ? b : a;
    T res = larger;
    while ( res % smaller != 0 )
        res += larger;
    return res;
}
