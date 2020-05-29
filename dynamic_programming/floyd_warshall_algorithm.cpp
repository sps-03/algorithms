/*
FLOYD WARSHALL ALGORITHM:
    It is an algorithm to find the Shortest Path between every pair of vertices for a given connected 
    and directed (or undirected) graph.

    Steps:
    1) Initialize the solution matrix with the input graph matrix (adjacent matrix representation).
    2) Now considering every vertex one by one as an intermediate vertex update the solution matrix.
       While doing this there are two possibilities for every source-destination pair (i, j):
       a) The vertex considered is not an intermediate vertex in shortest path from i to j. 
          So we keep the value of solution[i][j] as it is.
       b) The vertex considered is an intermediate vertex in shortest path from i to j. 
          So we update the value of solution[i][j] as solution[i][k]+solution[k][j] where k is the 
          vertex under consideration as intermediate vertex.


    Time Complexity          : O(V*V*V)
    Auxiliary Space          : O(V*V)            // solution matrix
*/


#include <iostream>
#include <climits>
using namespace std;

#define INF INT_MAX          // to represent edge weight of non adjacent vertices.
const int V = 4;             // number of vertices in the graph.


void printSolution(int solution[V][V]) {
    cout << "Solution Matrix (row --> source vertex & column --> destination vertex) :\n";
    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            if(solution[i][j] == INF)
                cout << "INF\t";
            else
                cout << solution[i][j] << "\t";
        }
        cout << "\n";
    }
}

void floydWarshall(int graph[V][V]) {
    int solution[V][V];           // solution matrix

    for(int i=0; i<V; i++) {      // initialize with graph matrix
        for(int j=0; j<V; j++)
            solution[i][j] = graph[i][j];
    }

    for(int k=0; k<V; k++) {           // k represents intermediate vertex
        for(int i=0; i<V; i++) {       // i represents source vertex
            for(int j=0; j<V; j++) {   // j represents destination vertex
                if(solution[i][k] != INF && solution[k][j] != INF)
                    solution[i][j] = min(solution[i][j], solution[i][k] + solution[k][j]);
            }
        }
    }

    printSolution(solution);      // prints the solution matrix where row represent source vertex and
                                  // column represent destination vertex
}

int main() {
    // Adjacency Matrix to represent edge weighted graph (INF==infinite, means no edge between them)
    int graph[V][V] = {{0, 3, INF, 7},
                       {8, 0, 2, INF},
                       {5, INF, 0, 1},
                       {2, INF, INF, 0}
                      };

    floydWarshall(graph);

    return 0; 
}