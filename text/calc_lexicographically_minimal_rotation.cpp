// 与えられた文字列を右から左へ向かって回転させたとき
// 辞書順で最小となるような回転回数を求める
int CalcLexicographicallyMinimalRotation( const std::string& s ) {
    int n = s.size();
    int i = 0, j = 1, k = 0;
    int x, y;
    while ( i < n && j < n && k < n ) {
        x = i + k >= n ? i + k - n : i + k;
        y = j + k >= n ? j + k - n : j + k;
        if ( s[x] == s[y] ) {
            k ++;
        } else {
            if ( s[x] > s[y] )
                i += k + 1;
            else
                j += k + 1;
            if ( i == j )
                j ++;
            k = 0;
        }
    }
    return i + 1;
}
