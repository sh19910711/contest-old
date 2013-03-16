// ローリングハッシュのインターフェース
template <class T> class IRollingHash {
public:
    virtual void init() {};
    virtual T getHash() = 0;
};
