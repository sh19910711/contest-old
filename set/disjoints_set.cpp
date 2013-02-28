class DisjointSets {
public:
    std::vector<int> data;
    DisjointSets( int size ): data(size, -1) {};
    void init( int size ) { data.resize(size); std::fill( data.begin(), data.end(), -1 ); }
    bool merge( int x, int y ) {
        x = root(x), y = root(y);
        if ( x != y ) {
            if ( data[y] < data[x] ) std::swap( x, y );
            data[x] += data[y], data[y] = x;
        }
        return x != y;
    }
    bool same( int x, int y ) { return root(x) == root(y); }
    int root( int x ) { return data[x] < 0 ? x : data[x] = root(data[x]); }
};
