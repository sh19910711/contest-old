// @snip <sh19910711/contest:search/search_interface.cpp>
template <class Node> class BreadthFirstSearchInterface: public SearchInterface<Node> {
public:
  virtual Node search()                            = 0;
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
