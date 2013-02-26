
// @snip <sh19910711/contest:graph/interface.cpp>
class AdjacentListGraph: public IGraph {
public:
    typedef std::vector<int> VI;
    typedef std::vector<VI> Edges;
    typedef std::vector<Weight> Weights;
    typedef std::vector<Weights> EdgeWeights;
    typedef VI::iterator VertexIterator;

    Edges edges;
    EdgeWeights edge_weights;
    Weights vertex_weights;
    int num;
    
    void init( int n ) {
        num = n;
        edges.resize(num);
        vertex_weights.resize(num);
        edge_weights.resize(num);
        std::fill( edges.begin(), edges.end(), VI() );
        std::fill( edge_weights.begin(), edge_weights.end(), Weights( num ) );
        addVertices();
        addEdges();
    }
    void addEdge( int from, int to, Weight weight ) {
        edges[from].push_back(to);
        setCost( from, to, weight );
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
    Weight getCost( int from, int to ) {
        return edge_weights[from][to];
    }
    void setCost( int from, int to, Weight weight ) {
        edge_weights[from][to] = weight;
    }
    VertexIterator begin( int from ) {
        return edges[from].begin();
    }
    VertexIterator end( int from ) {
        return edges[from].end();
    }
};
