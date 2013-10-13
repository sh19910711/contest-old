// 与えられた範囲についてfuncがtrueを返す要素のみを返す
template <class Iterator, class Func> std::vector<typename Iterator::value_type> filter(
        Iterator it, Iterator end, Func func ) {
    std::vector<typename Iterator::value_type> res;
    for ( ; it != end; ++ it )
        if ( func(*it) )
            res.push_back(*it);
    return res;
}
