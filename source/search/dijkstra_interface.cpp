template <class StateType, class CostType> class DijkstraInterface {
public:
  typedef CostType Cost;
  typedef StateType State;
  typedef std::pair <Cost, State> Node;
  virtual Cost search()                    = 0;
protected:
  virtual Cost get_none_cost()             = 0;
  virtual void init()                      = 0;
  virtual void push( Node node )           = 0;
  virtual bool is_goal( Node node )        = 0;
  virtual void find_next_node( Node node ) = 0;
  virtual bool is_min_cost( Node node )    = 0;
};
