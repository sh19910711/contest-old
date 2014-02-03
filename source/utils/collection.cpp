#ifdef __THIS_IS_CPP11__
// fill(begin, num, value)
template <class T, class V> void fill( T& v, const int& n, const V& value ) { std::fill(std::begin(v), std::begin(v) + n, value); }
// copy(from, to), copy(from, num, to)
template <class T> void copy( const T& s, T& t ) { std::copy(std::begin(s), std::end(s), std::begin(t)); }
template <class T> void copy( const T& s, const int& n, T& t ) { std::copy(std::begin(s), std::begin(s) + n, std::begin(t)); }
// sort(A), sort(begin, num)
template <class T> void sort( T& v ) { std::sort(std::begin(v), std::end(v)); }
template <class T> void sort( T& v, const int& n ) { std::sort(std::begin(v), std::begin(v) + n); }
#endif
