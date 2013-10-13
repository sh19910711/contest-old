// @desc トライ木の実装
template <class ValueType> class Trie {
public:
    typedef std::string::const_iterator Iterator;
    static const int SIZE = 256;
    ValueType value;
    Trie *next[SIZE];
    Trie() { clear(); }
    void clear() { std::fill( next, next+SIZE, (Trie*)NULL ); }
    Trie& find( const std::string& s ) {
        Trie* res = this;
        for ( StringIterator it_i = s.begin(); it_i != s.end(); ++ it_i ) {
            const int& c = *it_i;
            if ( ! res->next[c] ) res->next[c] = new Trie;
            res = res->next[c];
        }
        return *res;
    }
    int count( const std::string& s ) {
        Trie* res = this;
        for ( Iterator it_i = s.begin(); it_i != s.end(); ++ it_i ) {
            const int& c = *it_i;
            if ( ! res->next[c] ) return 0;
            res = res->next[c];
        }
        return 1;
    }
    ValueType& operator []( const std::string& s ) { return find(s).value; }
};
