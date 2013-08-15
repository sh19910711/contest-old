template <typename ValueType, int SIZE> class VectorClass {
public:
  typedef ValueType Type;
  VectorClass() { data.resize(SIZE); }
  Type& operator [] ( const int& index ) { return data[index]; }
  const Type& operator [] ( const int& index ) const { return data[index]; }
private:
  std::vector<Type> data;
};
