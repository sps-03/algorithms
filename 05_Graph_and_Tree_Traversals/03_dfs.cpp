/*
DEPTH FIRST SEARCH:
    Depth First Search (or Traversal) on a graph (or tree) is a type of search (or traversal) in 
    which any adjacent element of a node will be visited before exploring other adjacent elements.

    Stack data structure is used (recursive function).

    Time Complexity          : O(V)         // we need to visit all vertices.
    Auxiliary Space          : O(V)         // without considering space for graph.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <list>
using namespace std;


// struct to represent the graph with adjacency list representation
struct Graph {
    int V;                             // number of vertices
    list<int> *adj;                    // adjacency list

    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);           // undirected graph, so adding edge u--v and v--u
        adj[v].push_back(u);
    }
};

// helper function to do DFS
void recursive_DFS(Graph& graph, int vertex, bool visited[], vector<int>& dfs) {
	visited[vertex] = true;            // make the vertex visited
	dfs.push_back(vertex);             // add it to result

	for(auto i = graph.adj[vertex].begin(); i != graph.adj[vertex].end(); i++) {
		if(!visited[*i])
			recursive_DFS(graph, *i, visited, dfs);
	}
}

void DFS(Graph graph, int start) {
    vector<int> dfs;         // to store elements in the order they are visited.
    bool visited[graph.V];   // to keep track of visited elements.
    
    for(int i = 0; i < graph.V; i++)   // initially all vertices are non-visited
        visited[i] = false;

    // call the recursive helper function
    recursive_DFS(graph, start, visited, dfs);

    // print the result
    cout << "Depth First Search (Traversal) on the given graph will be :\n";
    for(int element: dfs)
        cout << element << "  ";
}

int main() {
    int start_vertex = 0, V = 5;
    Graph graph(V);                    // create a graph with V vertices

    graph.addEdge(0, 2);               // add all edges
    graph.addEdge(1, 2);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    DFS(graph, start_vertex);

    return 0;
}