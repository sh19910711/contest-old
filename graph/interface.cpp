// @snip <sh19910711/contest:graph/config.cpp>
// グラフ: インターフェースクラス。各メソッドを拡張する形式で利用する。
class IGraph {
public:
    virtual void init( int n ) = 0;
    virtual void addEdge( int from, int to ) = 0;
    virtual void addVertices() = 0;
    virtual void addEdges() = 0;
    virtual int countVertices() = 0;
    virtual Weight getEdgeCost( int from, int to ) = 0;
    virtual void setEdgeCost( int from, int to, Weight weight ) = 0;
    virtual Weight getVertexCost( int v ) = 0;
    virtual void setVertexCost( int v, Weight weight ) = 0;
};
