// @snip <sh19910711/contest:misc/range.cpp>
template <class Type> class Collection: public Type {
public:
  typedef misc::Range Range;
  // Func := bool func(Type::type)
  template <class Func> void each( Range r, Func func ) {
    for ( int i = r.begin(); i < r.end(); ++ i )
      if ( ! func(this->operator[](i)) )
        return;
  }
};
