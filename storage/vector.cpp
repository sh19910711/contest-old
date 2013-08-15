template <typename ValueType, int SIZE> class Vector {
public:
  typedef ValueType Type;
  Vector() { data.resize(SIZE); }
  Type& operator [] ( const int& index ) { return data[index]; }
  const Type& operator [] ( const int& index ) const { return data[index]; }
private:
  std::vector<Type> data;
};
