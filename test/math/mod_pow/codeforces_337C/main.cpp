namespace solution {
  std::istream* istream_pointer = &std::cin;
  std::ostream* ostream_pointer = &std::cout;
}

// @snippet<sh19910711/contest:headers.cpp>

// @snippet<sh19910711/contest:solution/interface.cpp>
namespace solution {
  class SolutionInterface {
  public:
    virtual int run() = 0;
    
  protected:
    SolutionInterface() {}
    virtual void pre_calc() {}
    virtual bool action() = 0;
    virtual void init() {};
    virtual bool input() { return false; };
    virtual void output() const {};
  };
}

// @snippet<sh19910711/contest:solution/solution-base.cpp>
namespace solution {
  class SolutionBase: public SolutionInterface {
  public:
    virtual int run() {
      this->pre_calc();
      while ( this->action() );
      return 0;
    }
    
  };
}

// @snippet<sh19910711/contest:math/mod_pow.cpp>

// @snippet<sh19910711/contest:solution/typedef.cpp>
namespace solution {
  typedef std::istringstream ISS;
  typedef std::ostringstream OSS;
  typedef long long Int;
  typedef long double Double;
  typedef std::string String;
  
}

// @snippet<sh19910711/contest:solution/namespace-area.cpp>
namespace solution {
  // namespaces, types
  using namespace std;
}

// @snippet<sh19910711/contest:solution/consts-area.cpp>
namespace solution {
  // constant vars
  const Int MOD = 1000000009;
  
}

// @snippet<sh19910711/contest:solution/storages-area.cpp>
namespace solution {
  // storages
  Int N;
  Int M;
  Int K;
  
  Int result;
}

// @snippet<sh19910711/contest:solution/solver-area.cpp>
namespace solution {
  class Solver {
  public:
    void solve() {
      result = find_minimum_score(N, M, K);
    }
    
    const Int find_minimum_score( const Int& N, const Int& M, const Int& K ) {
      Int bad = N - M;
      Int x = std::min(bad, M / ( K - 1 ));
      Int y = x * ( K - 1 );
      Int z = M - y;

      Int rem = z % K;
      Int t = z / K;

      Int a = y;
      Int b = ( ( ( K + K ) % MOD ) * ( math::mod_pow(Int(2), t, MOD) - 1 + MOD ) % MOD ) % MOD;
      Int c = rem;
      
      Int res = ( a + b + c + MOD ) % MOD;
      return res;
    }
    
  protected:
    
  };
}

// @snippet<sh19910711/contest:solution/solution.cpp>
namespace solution {
  class Solution: public SolutionBase {
  public:
  protected:
    virtual bool action() {
      this->init();
      if ( ! this->input() )
        return false;
      solver.solve();
      this->output();
      return true;
    }
    
    bool input() {
      return *istream_pointer >> N >> M >> K;
    }
    
    void output() {
      *ostream_pointer << result << std::endl;
    }
    
    Solver solver;
  };
}

// @snippet<sh19910711/contest:main.cpp>
#ifndef __MY_UNIT_TEST__
int main() {
  std::cin.sync_with_stdio(false);
  return solution::Solution().run();
}
#endif


