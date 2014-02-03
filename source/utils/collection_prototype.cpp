// collection
#ifdef __THIS_IS_CPP11__
// fill(begin, num, value)
template <class T, class V> void fill( T& v, const int& n, const V& value );
// copy(from, to), copy(from, num, to)
template <class T> void copy( const T& s, T& t );
template <class T> void copy( const T& s, const int& n, T& t );
// sort(A), sort(begin, num)
template <class T> void sort( T& v );
template <class T> void sort( T& v, const int& n );
#endif
