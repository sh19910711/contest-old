// @snip <sh19910711/contest:solution/interface.cpp>
// @snip <sh19910711/contest:typedef.cpp>
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
