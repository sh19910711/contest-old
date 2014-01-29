template <int SIZE, long long MOD = 1000000007LL> struct ModFact {
  long long data[SIZE];
  ModFact() {
    data[0] = data[1] = 1;
    for ( int i = 2; i < SIZE; ++ i ) {
      data[i] = data[i - 1] * i;
      data[i] %= MOD;
    }
  }
};
