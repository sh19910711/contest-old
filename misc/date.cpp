class Date {
public:
    static bool isLeapYear( int y ) {
        return y % 100 == 0 ? y % 400 == 0 : y % 4 == 0;
    }
};
