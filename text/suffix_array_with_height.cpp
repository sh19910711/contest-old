// @snip <sh19910711/contest:text/suffix_array.cpp>
// @snip <sh19910711/contest:text/suffix_array_with_lcp.cpp>
template <class SuffixArrayBase> class SuffixArrayWithHeight: public SuffixArrayBase {
public:
  typedef typename SuffixArrayBase::VI VI;

  void buildHeight() {
    int h = 0;
    for ( int i = 0; i < this->n; ++ i ) {
      int j = this->rank[i];
      if ( j == this->n - 1 ) {
        h = 0;
        continue;
      }
      int k = this->sa[j+1];
      if ( h > 0 )
        h = h - 1 + this->lcp( i + h - 1, k + h - 1 );
      else
        h = this->lcp( i, k );
      this->height[j] = h;
    }
  }
  void init( const std::string& s_ ) {
    SuffixArrayBase::init(s_);
    height.resize(std::max(0, this->n - 1));
  }

protected:
  VI height;
};
