//1
#include <iostream>
#include "../DSA_Headers/graph.h"

int main() {
    int i;
    g.addEdge(0, 4);    
    g.addEdge(2, 4);
    g.addEdge(4, 6);
    g.addEdge(4, 7);
    g.addEdge(6, 5);
    g.addEdge(5, 7);
    g.addEdge(7, 3);
    g.addEdge(3, 1);
    visited = new char[g.N];
    for (i = 0; i < g.N; i++)
        visited[i] = 0;
    dfs(4);
    std::cout << std::endl;
    for (i = 0; i < g.N; i++)
        visited[i] = 0;
    bfs(4);
    return 0;
}