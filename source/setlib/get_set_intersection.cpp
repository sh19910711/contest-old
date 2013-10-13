template<class T> std::set<T> GetSetIntersection( const std::set<T>& a, const std::set<T>& b ) {
    std::set<T> c;
    set_intersection( a.begin(), a.end(), b.begin(), b.end(), inserter( c, c.begin() ) );
    return c;
}
