class SmartPointerReferenceCount {
public:
  void add() { count ++; }
  int release() { return -- count; }
private:
  int count;
};
