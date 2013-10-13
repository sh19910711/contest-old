template <class T, int SIZE> class Array {
public:
  T& operator []( const int& id ) { return data[id]; }
  const T& operator []( const int& id ) const { return data[id]; }
  T* operator +( const int& id ) { return &data[id]; }
  const T* operator +( const int& id ) const { return &data[id]; }
private:
  T data[SIZE];
};
