// @snip <sh19910711/contest:text/suffix_array.cpp>
template <class SuffixArrayBase> class SuffixArrayWithLCP: public SuffixArrayBase {
public:
  int lcp( int x, int y ) {
    int l = this->n - std::min( x, y );
    for ( int i = 0; i < l; ++ i )
      if ( this->s[x+i] != this->s[y+i] )
        return i;
    return l;
  }
  void init( const std::string& s_ ) {
    SuffixArrayBase::init(s_);
  }
};
