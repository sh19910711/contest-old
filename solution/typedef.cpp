typedef std::istringstream ISS;
typedef std::ostringstream OSS;
typedef long long Int;
typedef long double Double;
typedef std::string String;

template <typename Type, int SIZE_X, int SIZE_Y, int SIZE_Z> struct VectorTypes {
  typedef storage::Vector<Type   , SIZE_X> Type1D;
  typedef storage::Vector<Type1D , SIZE_Y> Type2D;
  typedef storage::Vector<Type2D , SIZE_Z> Type3D;
};
template <int SIZE_X, int SIZE_Y, int SIZE_Z> struct BasicVectors {
  typedef VectorTypes<Int    , SIZE_X , SIZE_Y , SIZE_Z> IntVectors;
  typedef VectorTypes<Double , SIZE_X , SIZE_Y , SIZE_Z> DoubleVectors;
  typedef VectorTypes<String , SIZE_X , SIZE_Y , SIZE_Z> StringVectors;
};
