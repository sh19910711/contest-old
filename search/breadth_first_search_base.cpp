// @snip <sh19910711/contest:search/search_interface.cpp>
template <class Node> class BreadthFirstSearchBase: public SearchInterface<Node> {
public:
  virtual Node search() {
    Node res = get_none_node();
    init();
    while ( has_next_node() ) {
      Node node = get_next_node();
      if ( is_goal_node(node) )
        res = node;
      visit_next_node(node);
    }
    return res;
  }

protected:
  virtual void init()                              = 0; 
  virtual bool has_next_node()                     = 0;
  virtual void visit_next_node( const Node& node ) = 0;
  virtual void push_next_node( const Node& node )  = 0;
  virtual Node get_next_node()                     = 0;
  virtual Node get_none_node()                     = 0;
  virtual bool is_visited_node( const Node& node ) = 0;
  virtual void set_visited( const Node& node )     = 0;
  virtual bool is_goal_node( const Node& node )    = 0;

};
