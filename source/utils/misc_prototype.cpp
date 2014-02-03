// max(a, b), min(a, b)
template <class T> void max( T& a, const T& b );
template <class T> void min( T& a, const T& b );
// to_s(v), ret = to_type(str)
template <class T> std::string to_string( const T& v );
template <class T> T to_type( const std::string& s );

