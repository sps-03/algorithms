/*
KRUSKAL'S MST ALGORITHM:
    It is a Greedy approach to find the Minimum Spanning Tree for a given connected 
    and undirected graph. (a minimum spanning tree has (V – 1) edges where V is the 
    number of vertices)

    Steps:
    1) Sort all the edges in increasing (or, non-decreasing) order of their weight.
    2) Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far.
       If cycle is not formed, include this edge. Else, discard it.
    3) Repeat step2 until there are (V-1) edges in the spanning tree.
    (The step2 uses Find-Union algorithm to detect cycle)


    Time Complexity          : O(E*log(V) + E*log(E))
    Auxiliary Space          : O(V)              // to store results and subsets

    Sorting of edges takes O(E*logE) time.
    After sorting, we iterate through all edges and apply find-union algorithm.
    The find and union operations can take atmost O(log(V)) time.
*/

#include <iostream>
using namespace std;


// structure to represent a weighted edge in graph
class Edge {
    public:
        int src, dest, weight;
};

// structure to represent a connected, undirected and weighted graph
class Graph {
    public:
        int V, E;            // V-> number of vertices, E-> number of edges

        // graph is represented as an array of edges. Since the graph is undirected, the edge 
        // from src to dest is also edge from dest to src. Both are counted as 1 edge here.
        Edge* edge;
};

// creates a graph with V vertices and E edges
Graph* createGraph(int V, int E) {
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

// structure to represent a subset for union-find
class subset {
    public:
        int parent;
        int rank;
};

// function to find set of an element i (uses path compression technique)
int find(subset subsets[], int i) {
    // find root and make root as parent of i (path compression)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

// function that does union of two sets of x and y (uses union by rank)
void Union(subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    // attach smaller rank tree under root of high rank tree (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    // if ranks are same, then make one as root and increment its rank by one
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// compare two edges according to their weights. Used in qsort() for sorting an array of edges
int myComp(const void* a, const void* b) {
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight;
}

// function to construct MST using Kruskal's algorithm
void KruskalMST(Graph* graph) {
    int V = graph->V;
    Edge result[V-1];        // this will store the resultant MST
    int e = 0;               // an index variable, used for result[]
    int i = 0;               // an index variable, used for sorted edges

    // step 1: Sort all the edges in non-decreasing order of their weight. If we are not allowed to 
    // change the given graph, we can create a copy of array of edges
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);

    // allocate memory for creating V subsets
    subset *subsets = new subset[V * sizeof(subset)];

    // create V subsets with single elements
    for(int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // number of edges to be taken is equal to V-1
    while (e < V-1 && i < graph->E) {
        // step 2: Pick the smallest edge and increment the index for the next iteration
        Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // if including this edge does't cause cycle, include it in result and 
        // increment the index of result for next edge
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
        // else discard the next_edge
    }

    // print the contents of result[] to display the built MST
    cout<<"Following are the edges in the constructed MST.\n(source--destination = weight)\n";
    for (i = 0; i < e; i++)
        cout << result[i].src << "--" << result[i].dest << " = " << result[i].weight << "\n";
}

int main() {
    int V = 4;     // number of vertices in graph
    int E = 5;     // number of edges in graph
    Graph* graph = createGraph(V, E);

    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;

    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;

    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;

    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;

    // add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;

    KruskalMST(graph);

    return 0;
}