// @snip <sh19910711/contest:graph/interface.cpp>
// グラフ: 隣接行列を利用した実装
class AdjacentMatrixGraph: public IGraph {
public:
    typedef std::vector<int> VI;
    typedef std::vector<VI> Matrix;
    typedef std::vector<Weight> Weights;
    typedef std::vector<Weights> WeightMatrix;
    Matrix edge_exists;
    int num;
    WeightMatrix edge_weights;
    Weights vertex_weights;

    void init( int n ) {
        num = n;
        edge_exists = Matrix( num, VI( num, 0 ) );
        edge_weights = WeightMatrix( num, VI( num, 0 ) );
        vertex_weights = Weights( num, 0 );
        addVertices();
        addEdges();
    }
    void addEdge( int from, int to ) {
        edge_exists[from][to] = 1;
    }
    int countVertices() {
        return num;
    }
    Weight getEdgeCost( int from, int to ) {
        return edge_weights[from][to];
    }
    void setEdgeCost( int from, int to, Weight weight ) {
        edge_weights[from][to] = weight;
    }
    Weight getVertexCost( int v ) {
        return vertex_weights[v];
    }
    void setVertexCost( int v, Weight weight ) {
        vertex_weights[v] = weight;
    }
    Matrix getMatrix() {
        return edge_exists;
    }
};
