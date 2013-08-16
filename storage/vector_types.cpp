// @snip <sh19910711/contest:storage/vector.cpp>
const int VECTOR_NONE = -1;
template <typename ValueType, int SIZE_X = VECTOR_NONE, int SIZE_Y = VECTOR_NONE, int SIZE_Z = VECTOR_NONE> struct Vector {
  typedef storage::VectorClass<ValueType, SIZE_X> Type__;
  typedef storage::VectorClass<Type__, SIZE_Y> Type_;
  typedef storage::VectorClass<Type_, SIZE_Z> Type;
};
template <typename ValueType, int SIZE_X, int SIZE_Y> struct Vector<ValueType, SIZE_X, SIZE_Y, VECTOR_NONE> {
  typedef storage::VectorClass<ValueType, SIZE_X> Type_;
  typedef storage::VectorClass<Type_, SIZE_X> Type;
};
template <typename ValueType, int SIZE_X> struct Vector<ValueType, SIZE_X, VECTOR_NONE, VECTOR_NONE> {
  typedef storage::VectorClass<ValueType, SIZE_X> Type;
};
