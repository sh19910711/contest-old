// @snip <sh19910711/contest:io/config.cpp>
template <typename T> std::ostream& operator <<( std::ostream& os, const std::vector<T>& v ) {
    typedef typename std::vector<T>::const_iterator Iterator;
    for ( Iterator it_i = v.begin(); it_i != v.end(); ++ it_i ) {
        os << *it_i;
        if ( it_i + 1 != v.end() )
            os << OUTPUT_VECTOR_DELIMITER;
    }
    return os;
}
template <typename T> std::istream& operator >>( std::istream& is, std::vector<T>& v ) {
    int n = v.size();
    for ( int i = 0; i < n; ++ i ) {
        is >> v[i];
    }
    return is;
}
