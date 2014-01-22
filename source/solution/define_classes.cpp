struct InputStorage;
struct OutputStorage;
struct Storages {
  InputStorage* in;
  OutputStorage* out;
};
class SolverInterface {
public:
  virtual const OutputStorage* solve( const InputStorage* in, OutputStorage* out ) = 0;
};
