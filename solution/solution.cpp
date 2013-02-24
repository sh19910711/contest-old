// @snip <sh19910711/contest:solution/interface.cpp>
class Solution: public ISolution {
public:
    int run() {
        while ( init(), input() ) {
            solve();
            output();
        }
        return 0;
    }
};
