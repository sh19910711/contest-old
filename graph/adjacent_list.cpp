// @snip <sh19910711/contest:graph/interface.cpp>
// グラフ: 隣接リスト
class AdjacentListGraph: public IGraph {
public:
    typedef std::vector<int> VI;
    typedef std::vector<VI> Edges;
    typedef std::vector<Weight> Weights;
    typedef std::vector<Weights> EdgeWeights;
    typedef std::vector<VI> Matrix;
    typedef VI::iterator VertexIterator;

    Edges edges;
    EdgeWeights edge_weights;
    Weights vertex_weights;
    Matrix edge_exists;
    int num;

    void init( int n ) {
        num = n;
        edges.resize(num);
        vertex_weights.resize(num);
        edge_weights.resize(num);
        edge_exists.resize(num);
        std::fill( edges.begin(), edges.end(), VI() );
        std::fill( edge_weights.begin(), edge_weights.end(), Weights( num, 0 ) );
        std::fill( edge_exists.begin(), edge_exists.end(), VI( num, false ) );
        addVertices();
        addEdges();
    }
    void addEdge( int from, int to ) {
        if ( edge_exists[from][to] )
            return;
        edge_exists[from][to] = true;
        edges[from].push_back(to);
    }
    void addEdge( int from, int to, Weight weight ) {
        addEdge( from, to );
        setEdgeCost( from, to, weight );
    }
    int countVertices() {
        return num;
    }
    Weight getVertexCost( int from ) {
        return vertex_weights[from];
    }
    void setVertexCost( int from, Weight weight ) {
        vertex_weights[from] = weight;
    }
    Weight getEdgeCost( int from, int to ) {
        return edge_weights[from][to];
    }
    void setEdgeCost( int from, int to, Weight weight ) {
        edge_weights[from][to] = weight;
    }
    VertexIterator begin( int from ) {
        return edges[from].begin();
    }
    VertexIterator end( int from ) {
        return edges[from].end();
    }
};
