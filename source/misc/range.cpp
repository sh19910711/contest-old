class Range {
public:
  Range() {}
  Range( const int& begin, const int& end ): _begin(begin), _end(end) {}
  const int& begin() const { return this->_begin; }
  const int& end() const { return this->_end; }
private:
  int _begin;
  int _end;
};
