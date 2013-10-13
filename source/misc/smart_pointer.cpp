// @snip <sh19910711/contest:misc/smart_pointer_reference_count.cpp>
template <typename Type> class SmartPointer {
public:
  SmartPointer(): pointer(0), reference(0) {
    reference = new misc::SmartPointerReferenceCount();
    reference->add();
  }
  SmartPointer(Type* value): pointer(value) {
    reference = new misc::SmartPointerReferenceCount();
    reference->add();
  }
  SmartPointer(const SmartPointer<Type>& sp): pointer(sp.pointer), reference(sp.reference) {
    reference->add();
  }
  ~SmartPointer() {
    if ( reference->release() == 0 ) {
      delete pointer;
      delete reference;
    }
  }
  Type& operator *() { return *pointer; }
  const Type& operator *() const { return *pointer; }
  Type* operator +( const int& x ) { return pointer + x; }
  const Type* operator +( const int& x ) const { return pointer + x; }
  Type* operator ->() { return pointer; }
  SmartPointer<Type>& operator = ( const SmartPointer<Type>& sp ) {
    if ( this != &sp ) {
      if ( reference->release() == 0 ) {
        delete pointer;
        delete reference;
      }
      pointer = sp.pointer;
      reference = sp.reference;
      reference->add();
    }
    return *this;
  }
private:
  Type* pointer;
  misc::SmartPointerReferenceCount* reference;
};
