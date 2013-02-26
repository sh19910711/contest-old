template <class Key, class Data> class KeyMappingTable {
public:
    std::vector<Data> memory;
    void init( Key& limit ) {
        memory.resize(mapping(limit));
    }
    void fill( Data& value ) {
        std::fill( memory.begin(), memory.end(), value );
    }
    virtual int mapping( Key& key ) = 0;
    Data& operator []( Key& key ) {
        return memory[mapping(key)];
    }
    Data& operator =( Data& right ) {
        memory = right.memory;
    }
};
