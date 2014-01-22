// @snip <sh19910711/contest:misc/smart_pointer.cpp>
// @snip <sh19910711/contest:graph/interface.cpp>
template <typename WeightType, typename EdgeType> class AdjacentList: public GraphInterface<WeightType, EdgeType> {
public:
  typedef misc::SmartPointer<EdgeType> EdgePointer;
  typedef std::vector<EdgePointer> Edges;
  typedef std::vector<Edges> VertexEdges;

  void init( const int& num_vertices ) {
    this->num_vertices = num_vertices;
    this->vertex_edges = VertexEdges(this->num_vertices);
  }

  void add_edge( EdgePointer edge ) {
    this->vertex_edges[edge->from].push_back(edge);
  }

  int num_vertices;
  VertexEdges vertex_edges;

};
