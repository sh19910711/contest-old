// @snip <sh19910711/contest:setlib/disjoints_set.cpp>
template <typename GraphType> const typename std::vector<typename GraphType::Edge> get_minimum_spanning_forest( const GraphType& G ) {
  typedef typename std::vector<typename GraphType::Edge> Edges;
  typedef typename GraphType::Edge GraphEdge;
  typedef typename GraphType::Edges GraphEdges;
  typedef std::priority_queue<GraphEdge, Edges, std::greater<GraphEdge> > PriorityQueue;
  typedef setlib::DisjointSets UnionFind;

  Edges res;
  PriorityQueue E;
  UnionFind uf(G.num_vertices);

  for ( int i = 0; i < G.num_vertices; ++ i ) {
    for ( typename GraphEdges::const_iterator it_i = G.vertex_edges[i].begin(); it_i != G.vertex_edges[i].end(); ++ it_i ) {
      const GraphEdge& e = **it_i;
      E.push(GraphEdge(e.from, e.to, e.weight));
    }
  }

  while ( ! E.empty() ) {
    GraphEdge e = E.top();
    E.pop();
    if ( ! uf.same(e.from, e.to) ) {
      res.push_back(e);
      uf.merge(e.from, e.to);
    }
  }

  return res;
}
