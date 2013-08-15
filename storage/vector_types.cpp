template <typename Type, int SIZE_X = 0, int SIZE_Y = 0, int SIZE_Z = 0> struct VectorTypes {
  typedef storage::Vector<Type   , SIZE_X> Type1D;
  typedef storage::Vector<Type1D , SIZE_Y> Type2D;
  typedef storage::Vector<Type2D , SIZE_Z> Type3D;
};
template <int SIZE_X = 0, int SIZE_Y = 0, int SIZE_Z = 0> struct BasicVectors {
  typedef VectorTypes<Int    , SIZE_X , SIZE_Y , SIZE_Z> IntVectors;
  typedef VectorTypes<Double , SIZE_X , SIZE_Y , SIZE_Z> DoubleVectors;
  typedef VectorTypes<String , SIZE_X , SIZE_Y , SIZE_Z> StringVectors;
};
