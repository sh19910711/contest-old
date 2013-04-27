// @snip <sh19910711/contest:solution/typedef.cpp>
// @snip <sh19910711/contest:solution/interface.cpp>
using namespace std;

class Solution: public ISolution {
public:

    bool input() {
    }

    void solve() {
    }

    int run() {
        while ( init(), input() ) {
            solve();
            output();
        }
        return 0;
    }

};
