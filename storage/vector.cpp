template <typename ValueType, int SIZE> class Vector {
public:
  typedef ValueType Type;
  Type& operator [] ( const int& index ) { return data[index]; }
  const Type& operator [] ( const int& index ) const { return data[index]; }
private:
  Type data[SIZE];
};
