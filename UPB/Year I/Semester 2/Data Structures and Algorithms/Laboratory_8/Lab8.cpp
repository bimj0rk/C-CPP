#include <iostream>
#include <queue> 

template<typename TnodeInfo, typename TedgeInfo> 
class Graph {
    public:
        int N;
        char **A;
        TnodeInfo *nodeInfo;
        TedgeInfo **edgeInfo;

        Graph(int numNodes) {
            int i, j;

            N = numNodes;
            A = new char*[N];
            for (i = 0; i < N; i++)
                A[i] = new char[N];
	         for (i = 0; i < N; i++)
                for (j = 0; j < N; j++) A[i][j] = 0;
        
            edgeInfo = new TedgeInfo*[N];
            for (i = 0; i < N; i++)
                edgeInfo[i] = new TedgeInfo[N];
        }

        void setNodeInfo(int i, TnodeInfo info) {
            nodeInfo[i] = info;
        }

        TnodeInfo getNodeInfo(int i) {
            return nodeInfo[i];
        }

        void addEdge(int i, int j) {
            A[i][j] = A[j][i] = 1;
        }

        void removeEdge(int i, int j) {
            A[i][j] = A[j][i] = 0; 
        }

        void setEdgeInfo(int i, int j, TedgeInfo info) {
            edgeInfo[i][j] = edgeInfo[j][i] = info; 
        }

        TedgeInfo getEdgeInfo(int i, int j) {
            return edgeInfo[i][j]; 
        }

        

        ~Graph() {
            int i;
            for (i = 0; i < N; i++) {
                delete A[i];
                delete edgeInfo[i];
            }
            delete A;
            delete edgeInfo;
            delete nodeInfo;
        }
};

Graph<int, int> g(12);
char* visited;

void dfs(int x) {
    int y;
    printf("%d\n", x);
    visited[x] = 1;

    for (y = 0; y < g.N; y++)
        if (g.A[x][y] && !visited[y])
            dfs(y);
}

void bfs(int S) {
    std::queue<int> Q;
    int x, y;

    Q.push(S);
    visited[S] = 1;

    while (!Q.empty()) {
        x = Q.front();
        Q.pop();
        printf("%d\n", x);
        for (y = 0; y < g.N; y++)
            if (g.A[x][y] && !visited[y]) {
                visited[y] = 1;
               Q.push(y);
            }
    }
}

//1
void connexComponents(){
    for(int z = 0; z < g.N; z++)
        visited[z] = 0;
    
    for(int z = 0; z < g.N; z++){
        if(!visited[z]) dfs(z);
        printf("\n");
    }
}

int main(){
    g.addEdge(0, 4);    
    g.addEdge(2, 4);
    g.addEdge(4, 6);
    g.addEdge(4, 7);
    g.addEdge(6, 5);
    g.addEdge(5, 7);
    g.addEdge(7, 3);
    g.addEdge(3, 1);

    std::cout << "Following are connected components \n";
    connexComponents();
}