
namespace solution {
  std::istream* istream_pointer = &std::cin;
  std::ostream* ostream_pointer = &std::cout;
}

// @snippet<sh19910711/contest:solution/interface.cpp>
namespace solution {
  class SolutionInterface {
  public:
    virtual int run() = 0;
    
  protected:
    virtual void pre_calc() {}
    virtual bool action() = 0;
    virtual void init() {};
    virtual bool input() { return false; };
    virtual void output() {};
    
    SolutionInterface() {}
    
  private:
    
  };
}

// @snippet<sh19910711/contest:solution/solution-base.cpp>
namespace solution {
  class SolutionBase: public SolutionInterface {
  public:
    virtual int run() {
      pre_calc();
      while ( action() );
      return 0;
    }
    
  };
}

// @snippet<sh19910711/contest:solution/typedef.cpp>
namespace solution {
  typedef std::istringstream ISS;
  typedef std::ostringstream OSS;
  typedef std::vector<std::string> VS;
  typedef long long LL;
  typedef int INT;
  typedef std::vector<INT> VI;
  typedef std::vector<VI> VVI;
  typedef std::pair<INT,INT> II;
  typedef std::vector<II> VII;
}

// @snippet<sh19910711/contest:solution/namespace-area.cpp>
namespace solution {
  // namespaces, types
  using namespace std;
}

// @snippet<sh19910711/contest:solution/variables-area.cpp>
namespace solution {
  // constant vars
  const int ELEVATORS = 11;
  const int FLOORS = 100 + 11;
  const LL INF = std::numeric_limits<LL>::max() / 2LL;
  const string IMPOSSIBLE = "IMPOSSIBLE";
  // storages
  int n, K;
  int T[ELEVATORS];
  int E[ELEVATORS][FLOORS];
  int EC[ELEVATORS];
  
  int floor_elevators[FLOORS][ELEVATORS];
  int floor_elevators_num[FLOORS];
  bool floor_elevators_set[FLOORS][ELEVATORS];
  
  LL result;
}

namespace solution {
  typedef std::pair <int, int> State; // (floor, elevator)

  class Dijkstra: public search::DijkstraBase<State, LL> {
  protected:
    Cost get_none_cost() {
      return INF;
    }
    
    void init() {
      for ( int i = 0; i < n; ++ i ) {
        if ( E[i][0] == 0 ) {
          push(std::make_pair(0, State(0, i)));
        }
      }
    }
    
    bool is_goal( Node node ) {
      LL steps = node.first;
      int floor_id = node.second.first;
      int elevator_id = node.second.second;
      return floor_elevators_set[floor_id][elevator_id] && floor_id == K;
    }
    
    void find_next_node( Node node ) {
      LL steps = node.first;
      int floor_id = node.second.first;
      int elevator_id = node.second.second;
      
      if ( floor_elevators_set[floor_id][elevator_id] ) {
        for ( int i = 0; i < floor_elevators_num[floor_id]; ++ i ) {
          int next_elevator_id = floor_elevators[floor_id][i];
          LL next_steps = steps + 60;
          int next_floor_id = floor_id;
          push(Node(next_steps, State(next_floor_id, next_elevator_id)));
        }
      }
      
      for ( int i = -1; i <= 1; ++ i ) {
        int next_floor_id = floor_id + i;
        if ( next_floor_id < 0 || next_floor_id >= 100 )
          continue;
        LL next_steps = steps + T[elevator_id];
        int next_elevator_id = elevator_id;
        push(Node(next_steps, State(next_floor_id, next_elevator_id)));
      }
    }
  };
}

// @snippet<sh19910711/contest:solution/solver-area.cpp>
namespace solution {
  class Solver {
  public:
    void solve() {
      find_floor_elevators();
      result = dijkstra.search();
    }
    
    void find_floor_elevators() {
      for ( int i = 0; i < n; ++ i ) {
        int floors_num = EC[i];
        for ( int j = 0; j < floors_num; ++ j ) {
          int floor_id = E[i][j];
          floor_elevators[floor_id][floor_elevators_num[floor_id] ++] = i;
          floor_elevators_set[floor_id][i] = true;
        }
      }
    }
    
    Dijkstra dijkstra;
    
  private:
    
  };
}

// @snippet<sh19910711/contest:solution/solution.cpp>
namespace solution {
  class Solution: public SolutionBase {
  public:
  protected:
    virtual bool action() {
      init();
      if ( ! input() )
        return false;
      solver.solve();
      output();
      return true;
    }
    
    void init() {
      result = INF;
      for ( int i = 0; i < ELEVATORS; ++ i ) {
        EC[i] = 0;
      }
      for ( int i = 0; i < FLOORS; ++ i ) {
        floor_elevators_num[i] = 0;
        std::fill(floor_elevators_set[i], floor_elevators_set[i] + ELEVATORS, false);
      }
    }
    
    bool input_nk() {
      string line;
      getline(*istream_pointer, line);
      ISS iss(line);
      return iss >> n >> K;
    }
    
    bool input_t() {
      string line;
      getline(*istream_pointer, line);
      ISS iss(line);
      for ( int i = 0; i < n; ++ i )
        iss >> T[i];
      return true;
    }
    
    bool input_e() {
      for ( int i = 0; i < n; ++ i ) {
        string line;
        getline(*istream_pointer, line);
        ISS iss(line);
        int floor_id;
        while ( iss >> floor_id )
          E[i][EC[i] ++] = floor_id;
      }
      return true;
    }
    
    bool input() {
      if ( ! ( input_nk() ) )
        return false;
      input_t();
      input_e();
      return true;
    }
    
    void output() {
      if ( result == INF ) {
        *ostream_pointer << IMPOSSIBLE << endl;
      } else {
        *ostream_pointer << result << endl;
      }
    }
    
  private:
    Solver solver;
    
  };
}

// @snippet<sh19910711/contest:main.cpp>
#ifndef __MY_UNIT_TEST__
int main() {
  return solution::Solution().run();
}
#endif


