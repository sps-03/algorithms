/*
PRIM'S MST ALGORITHM:
    It is a Greedy approach to find the Minimum Spanning Tree for a given connected 
    and undirected graph.

    Steps:
    1) Create a set mstSet that keeps track of vertices already included in MST.
    2) Assign a key value to all vertices in the input graph. Initialize all key values as INFINITE.
       Assign key value as 0 for the first vertex so that it is picked first.
    3) While mstSet doesn’t include all vertices
        a) Pick a vertex 'u' which is not there in mstSet and has minimum key value.
        b) Include 'u' to mstSet.
        c) Update key value of all adjacent vertices of 'u'. To update the key values, iterate 
           through all adjacent vertices. For every adjacent vertex 'v', if weight of edge u-v is less 
           than the previous key value of v, update the key value as weight of u-v

    Time Complexity (using Adjacency Matrix)     : O(V*V)
    Time Complexity (using Adjacency List)       : O(E*log(V))
    Auxiliary Space                              : O(V)         // arrays - parent, key & mstSet
*/



// in this program 'Adjacency Matrix' representation is used
#include <iostream>
#include <climits>
using namespace std;

const int V = 5;             // number of vertices in the graph

// function to find the vertex with minimum key value, from the set of 
// vertices not yet included in the MST
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;      // initialize min value

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int graph[V][V]) {
    cout<<"Following are the edges in the constructed MST.\n(source--destination = weight)\n";
    for(int i = 1; i < V; i++)
        cout << parent[i] << "--" << i << " = " << graph[i][parent[i]] <<"\n";
}

void primMST(int graph[V][V]) {
    int parent[V];                     // array to store constructed MST
    int key[V];                        // key values used to pick minimum weight edge in cut
    bool mstSet[V];                    // to represent set of vertices not yet included in MST

    for(int i = 0; i < V; i++)         // initialize all keys as INFINITE
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;  // make key 0 so that this vertex is picked.(Always include 1st vertex first in MST)
    parent[0] = -1;                    // first node is always root of MST

    for(int count = 0; count < V - 1; count++) {      // the MST will have V-1 edges
        int u = minKey(key, mstSet);   // pick the minimum key vertex from the set of 
                                       // vertices not yet included in MST

        mstSet[u] = true;              // add the picked vertex to the MST Set

        // update key value and parent index of the adjacent vertices of the picked vertex.
        // consider only those vertices which are not yet included in MST.
        for(int v = 0; v < V; v++)
            // graph[u][v] is non zero only for adjacent vertices only.
            // mstSet[v] is false for vertices not yet included in MST.
            // update the key only if graph[u][v] is smaller than key[v].
            if(graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph);           // print the constructed MST
}

int main() {
    // Adjacency Matrix to represent edge weights
    int graph[V][V] = {{ 0, 2, 0, 6, 0 },
                       { 2, 0, 3, 8, 5 },
                       { 0, 3, 0, 0, 7 },
                       { 6, 8, 0, 0, 9 },
                       { 0, 5, 7, 9, 0 }};

    primMST(graph);

    return 0;
}