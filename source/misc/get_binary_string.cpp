// @desc 2進表記した文字列を求める
template <class T> std::string GetBinaryString( const T& v ) {
    std::ostringstream oss;
    for ( int i = 0; i < static_cast<int>(sizeof v) * 8; ++ i ) {
        int bi = ( v >> i ) & 1;
        oss << bi;
    }
    std::string res = oss.str();
    std::reverse( res.begin(), res.end() );
    return res;
}
