/*
DIJKSTRA'S SHORTEST PATH ALGORITHM:
    It is a Greedy approach to find the Shortest Path from the source vertex to any other vertex 
    for a given connected and directed (or undirected) graph.

    Steps:
    1) Create a set sptSet that keeps track of vertices already included in Shortest Path Tree.
       (Initially, this set is empty.)
    2) Assign a distance value to all vertices in the input graph. Initialize all distance values as 
       INFINITE.
       Assign distance value as 0 for the source vertex so that it is picked first.
    3) While sptSet doesn’t include all vertices
        a) Pick a vertex 'u' which is not there in sptSet and has minimum distance value.
        b) Include 'u' to sptSet.
        c) Update distance value of all adjacent vertices of 'u'. To update the distance values, 
           iterate through all adjacent vertices. For every adjacent vertex 'v', if sum of distance 
           value of 'u' (from source) and weight of edge u-v, is less than the distance value of v, 
           then update the distance value of 'v'.

    Time Complexity (using Adjacency Matrix)     : O(V*V)
    Time Complexity (using Adjacency List)       : O(E*log(V))
    Auxiliary Space                              : O(V)         // arrays - dist & sptSet

    # Dijkstra’s algorithm may fail for graphs with negative weight edges.
*/



// in this program 'Adjacency Matrix' representation is used
#include <iostream>
#include <climits>
using namespace std;
 
const int V = 9;             // number of vertices in the graph
  
// function to find the vertex with minimum distance value, from 
// the set of vertices not yet included in shortest path tree 
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;      // initialize min value

    for(int v = 0; v < V; v++)
        if(sptSet[v] == false && dist[v] < min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[]) {
    printf("Vertex \t\t Distance from Source\n");
    for(int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];                  // dist[i] will hold the shortest distance from src to i
    bool sptSet[V];               // sptSet[i] will be true if path to vertex i is found

    for(int i = 0; i < V; i++)   // initialize all distances as INFINITE and stpSet[] as false
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;                // distance of source vertex from itself is always 0

    for(int count = 0; count < V - 1; count++) { // find shortest path for all vertices
        // pick the minimum distance vertex from the set of vertices not 
        // yet processed. u is always equal to src in the first iteration. 
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;              // mark the picked vertex as processed

        // update distance value of the adjacent vertices of the picked vertex.
        for(int v = 0; v < V; v++)
            // update dist[v] only if is not in sptSet, there is an edge from 
            // u to v, and total weight of path from src to  v through u is 
            // smaller than current value of dist[v]
            if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist);               // print the constructed distance array
}

int main() {
    // Adjacency Matrix to represent edge weights
    int graph[V][V] = {{ 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                       { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                       { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                       { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                       { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                       { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                       { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                       { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                       { 0, 0, 2, 0, 0, 0, 6, 7, 0 }};

    dijkstra(graph, 0);      // args => (graph, source_vertex)

    return 0;
}