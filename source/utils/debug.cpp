//
// print std::tuple
//
namespace print_tuple_helpers {
  template<std::size_t...> struct seq{};
  template<std::size_t N, std::size_t... Is> struct gen_seq : gen_seq<N-1, N-1, Is...>{};
  template<std::size_t... Is> struct gen_seq<0, Is...> : seq<Is...>{};
  template<class Ch, class Tr, class Tuple, std::size_t... Is>
  void print_tuple(std::basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){
    using swallow = int[];
    (void)swallow{0, (void(os << (Is == 0? "" : ", ") << std::get<Is>(t)), 0)...};
  }
}

template<class Ch, class Tr, class... Args>
auto operator<<(std::basic_ostream<Ch, Tr>& os, std::tuple<Args...> const& t) -> std::basic_ostream<Ch, Tr>& {
  os << "(";
  print_tuple_helpers::print_tuple(os, t, print_tuple_helpers::gen_seq<sizeof...(Args)>());
  return os << ")";
}

//
// print std::vector
//
namespace print_vector_helpers {
  const std::string OUTPUT_VECTOR_DELIMITER = ", ";
}
template <typename T> std::ostream& operator <<( std::ostream& os, const std::vector<T>& v ) {
    typedef typename std::vector<T>::const_iterator Iterator;
    for ( Iterator it_i = v.begin(); it_i != v.end(); ++ it_i ) {
        os << *it_i;
        if ( it_i + 1 != v.end() )
            os << print_vector_helpers::OUTPUT_VECTOR_DELIMITER;
    }
    return os;
}
template <typename T> std::istream& operator >>( std::istream& is, std::vector<T>& v ) {
    int n = v.size();
    for ( int i = 0; i < n; ++ i ) {
        is >> v[i];
    }
    return is;
}

