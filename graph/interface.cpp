template <typename WeightType, typename EdgeType> class GraphInterface {
public:
  typedef WeightType Weight;
  typedef EdgeType Edge;
  typedef typename misc::SmartPointer<EdgeType> EdgePointer;
  virtual void init( const int& num_vertices ) = 0;
  virtual void add_edge( EdgePointer edge )    = 0;
  virtual ~GraphInterface() {}
};
