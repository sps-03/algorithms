/*
BREADTH FIRST SEARCH:
    Breadth First Search (or Traversal) on a graph (or tree) is a type of search (or traversal) in 
    which all the adjacent elements of a node will be explored before visiting the next element.

    Queue data structure is used to keep track of explored but not yet visited elements.

    Time Complexity          : O(V)         // we need to visit all vertices.
    Auxiliary Space          : O(V)         // without considering space for graph.
*/

#include <iostream>
#include <vector>
#include <queue>
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

void BFS(Graph graph, int start) {
    vector<int> bfs;         // to store elements in the order they are visited.
    queue<int> q;            // queue to keep track of explored but not visited elements.
    bool visited[graph.V];   // to keep track of visited elements.
    
    for(int i = 0; i < graph.V; i++)   // initially all vertices are non-visited
        visited[i] = false;

    visited[start] = true;             // make start vertex visited and push it to queue
    q.push(start);

    // till queue becomes empty do the following steps:
    // 1) pick the first element from queue and add it to result
    // 2) explore all the adjacent vertices of it and add them to queue if it's not yet visited
    while(!q.empty()) {
        int curElement = q.front();
        q.pop();
        bfs.push_back(curElement);

        for (auto i = graph.adj[curElement].begin(); i != graph.adj[curElement].end(); i++) {
            if (!visited[*i]) {
                visited[*i] = true;
                q.push(*i);
            }
        }
    }

    // print the result
    cout << "Breadth First Search (Traversal) on the given graph will be :\n";
    for(int element: bfs)
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

    BFS(graph, start_vertex);

    return 0;
}