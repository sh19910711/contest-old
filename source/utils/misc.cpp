// max(a, b), min(a, b)
template <class T> void max( T& a, const T& b ) { a = std::max(a, b); }
template <class T> void min( T& a, const T& b ) { a = std::min(a, b); }
// to_s(v), ret = to_type(str)
template <class T> std::string to_string( const T& v ) { std::ostringstream oss; oss << v; return oss.str(); }
template <class T> T to_type( const std::string& s ) { std::istringstream iss(s); T res; iss >> res; return res; }

