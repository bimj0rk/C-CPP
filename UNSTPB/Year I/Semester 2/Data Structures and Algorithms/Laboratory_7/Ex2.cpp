//2
#include <iostream>
#include "../DSA_Headers/graph.h"

int main() {
    int i;
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(7, 5);
    g.addEdge(2, 4);
    g.addEdge(5, 8);
    g.addEdge(7, 9);
    g.addEdge(4, 3);
    g.addEdge(8, 9);
    g.addEdge(4, 7);

    visited = new char[g.N];
    for (i = 0; i < g.N; i++)
        visited[i] = 0;

    if(bipartite()) std::cout << "Yes";
    else std::cout << "No";
}
