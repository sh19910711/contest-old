class IGraph {
public:
    virtual void init( int n ) = 0;
    virtual void addEdge( int from, int to, Weight weight ) = 0;
    virtual void addVertices() = 0;
    virtual void addEdges() = 0;
    virtual int countVertices() = 0;
    virtual Weight getCost( int from, int to ) = 0;
    virtual void setCost( int from, int to, Weight weight ) = 0;
};
