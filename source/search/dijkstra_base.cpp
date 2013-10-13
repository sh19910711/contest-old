// @snip <sh19910711/contest:search/dijkstra_interface.cpp>
template <class StateType, class CostType> class DijkstraBase: public DijkstraInterface<StateType, CostType> {
public:
  typedef CostType Cost;
  typedef StateType State;
  typedef std::pair <Cost, State> Node;
  typedef std::priority_queue<Node, std::vector<Node>, std::greater<Node> > Queue;
  typedef std::map <State, Cost> MinCost;

  virtual Cost search() {
    Q = Queue();
    MC.clear();
    init();

    while ( ! Q.empty() ) {
      Node node = Q.top();
      Q.pop();

      if ( is_goal(node) )
        return node.first;

      find_next_node(node);
    }

    return get_none_cost();
  }
protected:
  virtual Cost get_none_cost()             = 0;
  virtual void init()                      = 0;
  virtual bool is_goal( Node node )        = 0;
  virtual void find_next_node( Node node ) = 0;

  virtual void push( Node node ) {
    if ( ! is_min_cost(node) )
      return;
    MC[node.second] = node.first;
    Q.push(node);
  }

  virtual bool is_min_cost( Node node ) {
    if ( ! MC.count(node.second) )
      return true;
    return node.first < MC[node.second];
  }

private:
  Queue Q;
  MinCost MC;

};
