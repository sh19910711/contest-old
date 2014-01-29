template <int SIZE> struct Prime {
  bool data[SIZE];
  Prime() {
    std::fill( data, data + SIZE, false );
    for ( int i = 3; i < SIZE; i += 2 )
      data[i] = true;
    data[2] = true;
    for ( int i = 3; i * i < SIZE; i += 2 ) {
      if ( data[i] )
        for ( int j = i + i; j < SIZE; j += i )
          data[j] = false;
    }
  }
};
