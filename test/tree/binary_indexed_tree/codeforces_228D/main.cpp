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
  std::istream* istream_pointer = &std::cin;
  std::ostream* ostream_pointer = &std::cout;
  typedef tree::BinaryIndexedTree<LL> BIT;
}

// @snippet<sh19910711/contest:solution/variables-area.cpp>
namespace solution {
  // constant vars
  const int SIZE = 100000 + 11;
  const int NONE = -1;
  const int Z_MAX = 6;
  const int QUERY_A = 1;
  const int QUERY_B = 2;
  const int BIT_SIZE = 100;
  
  // storages
  int n;
  int A[SIZE];
  int m;
  int T[SIZE];
  int X[SIZE];
  int Y[SIZE];
  int Z[SIZE];
  
  LL query_result[SIZE];
  BIT bit[BIT_SIZE];
}

// @snippet<sh19910711/contest:solution/solver-area.cpp>
namespace solution {
  class Solver {
  public:
    void solve() {
      generate_bit();

      for ( int i = 0; i < m; ++ i ) {
        if ( T[i] == QUERY_A ) {
          query_result[i] = query_a(X[i], Y[i]);
        } else if ( T[i] == QUERY_B ) {
          query_result[i] = query_b(X[i], Y[i], Z[i]);
        }
      }
    }

    void set_value( int p, LL v ) {
      for ( int z = 2; z <= Z_MAX; ++ z ) {
        bit[get_bit_index(z, p)].set(p, v);
      }
    }

    void generate_bit() {
      for ( int i = 1; i <= n; ++ i ) {
        set_value(i, A[i]);
      }
    }

    int get_bit_index( int z, int k ) {
      int offset = ( z - 1 ) * ( z - 0 );
      return offset + ( k - 1 ) % ( 2 * ( z - 1 ) );
    }
    
    LL query_a( int p, int v ) {
      set_value(p, v);
      return NONE;
    }

    int calc_zigzag_seq( int z, int x ) {
      int mod = x % ( 2 * ( z - 1 ) );
      if ( mod == 0 )
        return 2;
      if ( mod <= z )
        return mod;
      return 2 * z - mod;
    }

    LL range_sum( int bit_id, int l, int r, int z ) {
      LL res = bit[bit_id].sum(r) - bit[bit_id].sum(l - 1);
      return res;
    }
    
    LL query_b( int l, int r, int z ) {
      LL res = 0;
      for ( int p = 1; p < z; ++ p ) {
        LL ret = calc_zigzag_seq(z, p) * range_sum(get_bit_index(z, l + p - 1), l, r, z); 
        res += ret;
      }
      for ( int p = z; p >= 2; -- p ) {
        LL ret = calc_zigzag_seq(z, p) * range_sum(get_bit_index(z, l + 2 * z - p - 1), l, r, z); 
        res += ret;
      }
      return res;
    }
    
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
      std::fill(query_result, query_result + SIZE, NONE);
      for ( int i = 0; i < BIT_SIZE; ++ i )
        bit[i] = BIT(SIZE);
    }
    
    bool input() {
      if ( ! ( *istream_pointer >> n ) )
        return false;
      for ( int i = 1; i <= n; ++ i ) {
        *istream_pointer >> A[i];
      }
      *istream_pointer >> m;
      for ( int i = 0; i < m; ++ i ) {
        *istream_pointer >> T[i];
        if ( T[i] == QUERY_A ) {
          *istream_pointer >> X[i] >> Y[i];
        } else if ( T[i] == QUERY_B ) {
          *istream_pointer >> X[i] >> Y[i] >> Z[i];
        }
      }
      return true;
    }
    
    void output() {
      for ( int i = 0; i < m; ++ i ) {
        if ( query_result[i] != NONE ) {
          *ostream_pointer << query_result[i] << endl;
        }
      }
    }
    
  private:
    Solver solver;
    
  };
}


