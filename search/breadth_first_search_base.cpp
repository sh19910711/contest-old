// @snip <sh19910711/contest:search/breadth_first_search_interface.cpp>
template <class Node> class BreadthFirstSearchBase: public BreadthFirstSearchInterface<Node> {
public:
  Node search() {
    Node res = this->get_none_node();
    this->init();
    while ( this->has_next_node() ) {
      Node node = this->get_next_node();
      if ( this->is_goal_node(node) )
        res = node;
      this->visit_next_node(node);
    }
    return res;
  }
};
