namespace solution {
  std::istream* istream_pointer = &std::cin;
  std::ostream* ostream_pointer = &std::cout;
}

// @snippet<sh19910711/contest:headers.cpp>

// @snippet<sh19910711/contest:solution/interface.cpp>
namespace solution {
  class SolutionInterface {
  public:
    virtual int run() = 0;
    
  protected:
    SolutionInterface() {}
    virtual void pre_calc() {}
    virtual bool action() = 0;
    virtual void init() {};
    virtual bool input() { return false; };
    virtual void output() const {};
  };
}

// @snippet<sh19910711/contest:solution/solution-base-multi-tests.cpp>
namespace solution {
  class SolutionBase: public SolutionInterface {
  public:
    virtual int run() {
      int tests = 0;
      *istream_pointer >> tests;
      for ( int i = 0; i < tests; ++ i ) {
        *ostream_pointer << "Case #" << i + 1 << ": ";
        this->action();
      }
      return 0;
    }
    
  };
}

// @snippet<sh19910711/contest:misc/smart_pointer_reference_count.cpp>
namespace misc {
  class SmartPointerReferenceCount {
  public:
    void add() { count ++; }
    int release() { return -- count; }
  private:
    int count;
  };
}

// @snippet<sh19910711/contest:misc/smart_pointer.cpp>
namespace misc {
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
}

// @snippet<sh19910711/contest:graph/interface.cpp>
namespace graph {
  template <typename WeightType, typename EdgeType> class GraphInterface {
  public:
    typedef WeightType Weight;
    typedef EdgeType Edge;
    typedef typename misc::SmartPointer<EdgeType> EdgePointer;
    virtual void init( const int& num_vertices ) = 0;
    virtual void add_edge( EdgePointer edge )    = 0;
    virtual ~GraphInterface() {}
  };
}

// @snippet<sh19910711/contest:graph/adjacent_list.cpp>
namespace graph {
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
}

// @snippet<sh19910711/contest:setlib/disjoints_set.cpp>

// @snippet<sh19910711/contest:graph/get_minimum_spanning_forest.cpp>
namespace graph {
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
}

// @snippet<sh19910711/contest:storage/vector.cpp>
namespace storage {
  template <typename ValueType, int SIZE> class VectorClass {
  public:
    typedef ValueType Type;
    VectorClass() { data.resize(SIZE); }
    Type& operator [] ( const int& index ) { return data[index]; }
    const Type& operator [] ( const int& index ) const { return data[index]; }
  private:
    std::vector<Type> data;
  };
}

// @snippet<sh19910711/contest:storage/vector_types.cpp>
namespace storage {
  const int VECTOR_NONE = -1;
  template <typename ValueType, int SIZE_X = VECTOR_NONE, int SIZE_Y = VECTOR_NONE, int SIZE_Z = VECTOR_NONE> struct Vector {
    typedef storage::VectorClass<ValueType, SIZE_X> Type__;
    typedef storage::VectorClass<Type__, SIZE_Y> Type_;
    typedef storage::VectorClass<Type_, SIZE_Z> Type;
  };
  template <typename ValueType, int SIZE_X, int SIZE_Y> struct Vector<ValueType, SIZE_X, SIZE_Y, VECTOR_NONE> {
    typedef storage::VectorClass<ValueType, SIZE_X> Type_;
    typedef storage::VectorClass<Type_, SIZE_X> Type;
  };
  template <typename ValueType, int SIZE_X> struct Vector<ValueType, SIZE_X, VECTOR_NONE, VECTOR_NONE> {
    typedef storage::VectorClass<ValueType, SIZE_X> Type;
  };
}

// @snippet<sh19910711/contest:solution/typedef.cpp>
namespace solution {
  typedef std::istringstream ISS;
  typedef std::ostringstream OSS;
  typedef long long Int;
  typedef long double Double;
  typedef std::string String;
  
}

namespace solution {
  class Edge {
  public:
    int from;
    int to;
    Int weight;
    Edge( int from, int to, Int weight ): from(from), to(to), weight(weight) {}
    friend const bool operator < ( const Edge& l, const Edge& r ) { return l.weight < r.weight; }
    friend const bool operator > ( const Edge& l, const Edge& r ) { return ! operator <(l, r); }
    friend std::ostream& operator << ( std::ostream& os, const Edge& edge ) {
      return os << "{from = " << edge.from << ", to = " << edge.to << ", weight = " << edge.weight << "}";
    }
  };
}

// @snippet<sh19910711/contest:solution/namespace-area.cpp>
namespace solution {
  // namespaces, types
  using namespace std;
  typedef graph::AdjacentList<Int, Edge> Graph;
  typedef setlib::DisjointSets UnionFind;
  
  struct Result {
    Int cost;
    Int airports;
    Result(const Int& cost, const Int& airports): cost(cost), airports(airports) {}
  };
}

// @snippet<sh19910711/contest:solution/consts-area.cpp>
namespace solution {
  // constant vars
  const int MAX_VERTICES = 10000 + 11;
  const int MAX_EDGES = 100000 + 11;
}

// @snippet<sh19910711/contest:solution/storages-area.cpp>
namespace solution {
  // storage types
  typedef storage::Vector<Int, MAX_EDGES>::Type EdgeVertices;
  typedef storage::Vector<Int, MAX_EDGES>::Type EdgeCosts;
  typedef std::vector<Graph::Edge> Edges;
  
  // storages
  Int N;
  Int M;
  Int A;
  EdgeVertices X;
  EdgeVertices Y;
  EdgeCosts C;
  
  Graph G;
  Edges F;
  
  Int minimum_cost;
  Int minimum_airports;
}

// @snippet<sh19910711/contest:solution/solver-area.cpp>
namespace solution {
  class Solver {
  public:
    void solve() {
      X = normalize(X, M);
      Y = normalize(Y, M);
      G = generate_graph(N, X, Y, C, M, A);
      F = get_minimum_spanning_forest(G);
      Result ret = calc_result(N, F, A);
      minimum_cost = ret.cost;
      minimum_airports = ret.airports;
    }
    
    Result calc_result( const Int& num_vertices, const Edges& edges, const Int& A ) {
      Int cost = 0;
      Int airports = 0;
      UnionFind uf(num_vertices);
      for ( Edges::const_iterator it_i = edges.begin(); it_i != edges.end(); ++ it_i ) {
        const Edge& e = *it_i;
        cost += e.weight;
        if ( ! uf.same(e.from, e.to) ) {
          uf.merge(e.from, e.to);
        }
      }
      for ( int i = 0; i < num_vertices; ++ i ) {
        if ( uf.root(i) == i ) {
          airports ++;
        }
      }
      return Result(cost + airports * A, airports);
    }
    
    const Graph generate_graph( const Int& num_vertices, const EdgeVertices& X, const EdgeVertices& Y, const EdgeCosts& C, const Int& num_edges, const Int& A ) {
      Graph G;
      G.init(num_vertices);
      for ( int i = 0; i < num_edges; ++ i ) {
        if ( C[i] < A )
          G.add_edge(new Edge(X[i], Y[i], C[i]));
      }
      return G;
    }
    
    const EdgeVertices normalize( const EdgeVertices& vertices, const Int& num ) {
      EdgeVertices res;
      for ( int i = 0; i < num; ++ i ) {
        res[i] = vertices[i] - 1;
      }
      return res;
    }
    
  protected:
    
  };
}

// @snippet<sh19910711/contest:solution/solution.cpp>
namespace solution {
  class Solution: public SolutionBase {
  public:
  protected:
    virtual bool action() {
      this->init();
      if ( ! this->input() )
        return false;
      solver.solve();
      this->output();
      return true;
    }
    
    bool input() {
      if ( ! ( *istream_pointer >> N >> M >> A ) )
        return false;
      for ( int i = 0; i < M; ++ i )
        *istream_pointer >> X[i] >> Y[i] >> C[i];
      return true;
    }
    
    void output() {
      *ostream_pointer << minimum_cost << " " << minimum_airports << std::endl;
    }
    
    Solver solver;
  };
}

// @snippet<sh19910711/contest:main.cpp>
#ifndef __MY_UNIT_TEST__
int main() {
  std::cin.sync_with_stdio(false);
  return solution::Solution().run();
}
#endif

