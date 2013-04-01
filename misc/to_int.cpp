template <class T> T to_int( const std::string& s ) {
    std::istringstream iss(s); T res; iss >> res; return res;
}
