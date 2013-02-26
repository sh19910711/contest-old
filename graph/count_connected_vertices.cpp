// @snip <sh19910711/contest:graph/adjacent_list.cpp>
int CountConnectedVertices( graph::AdjacentListGraph& graph, int start_vertex ) {
    int n = graph.num;
    bool used[n];
    std::fill( used, used+n, false );
    std::queue <int> Q;
    Q.push(start_vertex);
    used[start_vertex] = true;
    int res = 1;
    while ( ! Q.empty() ) {
        int current_vertex = Q.front();
        Q.pop();
        for ( std::vector<int>::iterator it_i = graph.begin(current_vertex);
                it_i != graph.end(current_vertex); ++ it_i ) {
            int& next_vertex = *it_i;
            if ( used[next_vertex] )
                continue;
            used[next_vertex] = true;
            res ++;
            Q.push(next_vertex);
        }
    }
    return res;
}
