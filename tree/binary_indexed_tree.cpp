template <class T> class BinaryIndexedTree {
public:
  int n;
  std::vector<T> data;

  BinaryIndexedTree() {}
  BinaryIndexedTree( const int& n ): n(n) {
    data = std::vector<T>(n + 1, 0);
  }

  T sum( int i ) {
    i ++;
    int res = 0;
    while ( i > 0 ) { res += data[i]; i -= i & -i; }
    return res;
  }

  void add( int i, const T& x ) {
    i ++;
    while ( i <= n ) { data[i] += x; i += i & -i; }
  }

  T get( const int& x ) {
    return sum(x) - sum(x - 1);
  }

  void set( const int& x, const T& new_value ) {
    add(x, new_value - get(x));
  }
};
