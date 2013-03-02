class SuffixArray {
public:
    typedef std::vector<int> VI;
    std::string s;
    int n, k;
    VI sa, rank, height;
    void build() {
        int maxlen = n;
        for ( int i = 0; i < n; ++ i ) rank[i] = s[i], maxlen = std::max( maxlen, s[i] + 1 );
        VI cnt(maxlen, 0);
        for ( int i = 0; i < n; ++ i ) cnt[rank[i]] ++;
        for ( int i = 1; i < maxlen; ++ i ) cnt[i] += cnt[i-1];
        for ( int i = 0; i < n; ++ i ) sa[--cnt[rank[i]]] = i;
        for ( k = 1; k < n; k *= 2 ) {
            VI r = rank;
            rank[sa[0]] = 0;
            for ( int i = 1; i < n; ++ i ) {
                int s1 = sa[i-1], s2 = sa[i];
                rank[s2] = r[s1] == r[s2] && std::max( s1, s2 ) + k < n && r[s1+k/2] == r[s2+k/2] ? rank[s1] : i;
            }
            for ( int i = 0; i < n; ++ i ) cnt[i] = i;
            VI s = sa;
            for ( int i = 0; i < n; ++ i ) {
                int s1 = s[i] - k;
                if ( s1 >= 0 ) sa[cnt[rank[s1]]++] = s1;
            }
        }
    }
    SuffixArray() { init(""); }
    SuffixArray( const std::string& s_ ) { init(s_); }
    void init( const std::string& s_ ) {
        s = s_; n = s.size(); sa.resize(n); rank.resize(n+1);height.resize(std::max(0,n-1));
    }
    VI::iterator begin() { return sa.begin(); }
    VI::iterator end() { return sa.end(); }
    int& operator []( int k ) { return sa[k]; }
    int size() { return n; }
    bool find( const std::string& key ) {
        int lb = 0, ub = n;
        while ( ub - lb > 1 ) {
            int mid = ( lb + ub ) / 2;
            std::string t = s.substr( sa[mid] );
            if ( t.substr( 0, key.size() ) == key ) {
                return true;
            } else if ( t < key ) {
                lb = mid;
            } else {
                ub = mid;
            }
        }
        return false;
    }

    int lcp( int x, int y ) {
        int l = n - std::min( x, y );
        for ( int i = 0; i < l; ++ i ) if ( s[x+i] != s[y+i] ) return i;
        return l;
    }

    void buildHeight() {
        int h = 0;
        for ( int i = 0; i < n; ++ i ) {
            int j = rank[i];
            if ( j == n - 1 ) { h = 0; continue; }
            int k = sa[j+1];
            if ( h > 0 ) h = h - 1 + lcp( i + h - 1, k + h - 1 );
            else h = lcp( i, k );
            height[j] = h;
        }
    }
};
