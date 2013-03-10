// @snip <sh19910711/contest:solution/interface.cpp>
class Solution: public ISolution {
public:
    int run() {
        int tests;
        std::cin >> tests;
        for ( int i = 0; i < tests; ++ i ) {
            init();
            input();
            solve();
            output();
        }
        return 0;
    }
};

