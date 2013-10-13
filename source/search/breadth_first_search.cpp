// @snip <sh19910711/contest:search/breadth_first_search_base.cpp>
template <class Node> class BreadthFirstSearch: public BreadthFirstSearchBase<Node> {
protected:
  virtual void init() {}

  bool has_next_node() {
    return ! Q.empty();
  }

  Node get_next_node() {
    Node res = Q.front();
    Q.pop();
    return res;
  }

  void push_next_node( const Node& node ) {
    if ( this->is_visited_node(node) )
      return;
    Q.push(node);
    this->set_visited(node);
  }

protected:
  std::queue <Node> Q;
};
