namespace solution {
  std::istream* istream_pointer = &std::cin;
  std::ostream* ostream_pointer = &std::cout;
}

// @snippet<sh19910711/contest:headers.cpp>

// @snippet<sh19910711/contest:solution/define_classes.cpp>
namespace solution {
  class Solution;
  class Solver;
  class Storages;
}

// @snippet<sh19910711/contest:solution/interface.cpp>
namespace solution {
  class SolutionInterface {
  public:
    virtual ~SolutionInterface() {};
    virtual int run() = 0;
    
  protected:
    SolutionInterface() {}
    virtual void pre_calc() {}
    virtual bool action() = 0;
    virtual void init() {};
    virtual bool input( Storages& s ) { return false; };
    virtual void output( const Storages& s ) const {};
    virtual void before_action( const int& test_no ) const {}
    virtual void after_action( const int& test_no ) const {}
  };
}

// @snippet<sh19910711/contest:solution/solution-base.cpp>
namespace solution {
  class SolutionBase: public SolutionInterface {
  public:
    virtual ~SolutionBase() {}
    virtual int run() {
      this->pre_calc();
      for (;;) {
        this->before_action(-1);
        if ( ! this->action() ) { this->after_action(-1); break; }
        this->after_action(-1);
      };
      return 0;
    }
  protected:
    SolutionBase() {}
  };
}

// @snippet<sh19910711/contest:text/suffix_array.cpp>

// @snippet<sh19910711/contest:text/suffix_array_with_lcp.cpp>

// @snippet<sh19910711/contest:text/suffix_array_with_height.cpp>

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
  
  
}

// @snippet<sh19910711/contest:solution/storages-area.cpp>
namespace solution {
  typedef text::SuffixArrayWithHeight< text::SuffixArrayWithLCP<text::SuffixArray> > SuffixArray;
  
  // storages
  class Storages {
  public:
    String A;
    String B;
    SuffixArray SA;
    
    Int result;
  };
  
  Storages global_storages;
}

// @snippet<sh19910711/contest:solution/solver-area.cpp>
namespace solution {
  class Solver {
  public:
    void solve( Storages& s ) {
      init_suffix_array(s.A, s.SA);
      s.result = find_max_length(s.SA, s.B);
    }
    
  protected:
    static void init_suffix_array( const String& s, SuffixArray& sa ) {
      sa.init(s);
      sa.build();
      sa.buildHeight();
    }
    
    static Int find_max_length( const SuffixArray& sa, const String& s ) {
      Int len = 0;
      int n = s.size();
      for ( int i = 0; i + len < n; ) {
        if ( sa.find(s.substr(i, len + 1)) ) {
          len ++;
        } else {
          i ++;
        }
      }
      return len;
    }
    
  };
}

// @snippet<sh19910711/contest:solution/solution.cpp>
namespace solution {
  class Solution: public SolutionBase {
  public:
    Solution() {}
    Solution(Storages* p): storages(p) {}
    
  protected:
    virtual bool action() {
      this->init();
      if ( ! this->input(*this->storages) )
        return false;
      solver.solve(*this->storages);
      this->output(*this->storages);
      return true;
    }
    
    bool input( Storages& s ) {
      if ( ! ( *istream_pointer >> s.A ) )
        return false;
      return *istream_pointer >> s.B;
    }
    
    void output( const Storages& s ) const {
      *ostream_pointer << s.result << std::endl;
    }
    
  private:
    Solver solver;
    Storages* storages;
  };
}

// @snippet<sh19910711/contest:main.cpp>
#ifndef __MY_UNIT_TEST__
int main() {
  std::cin.sync_with_stdio(false);
  return solution::Solution(&solution::global_storages).run();
}
#endif




