// @snip <sh19910711/contest:misc/smart_pointer.cpp>
template <typename ValueType, int SIZE> class VectorClass {
public:
  typedef misc::SmartPointer<ValueType> Pointer;
  VectorClass() { data = Pointer(new ValueType[SIZE]); }
  ValueType& operator [] ( const int& index ) { return *(data + index); }
  const ValueType& operator [] ( const int& index ) const { return *(data + index); }
private:
  Pointer data;
};
