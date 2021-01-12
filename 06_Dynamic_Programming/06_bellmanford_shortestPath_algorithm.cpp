/*
BELLMAN-FORD SHORTEST PATH ALGORITHM:
	It is a Dynamic Programming approach to find the Shortest Path from the source vertex to any other 
	vertex for a given connected and directed (or undirected) graph which may contain negative edges.

	Dijkstra's algorithm (Greedy approach) can also be used for finding Shortest Path but it may fail 
	for graphs with negative edges.

	Steps:
	1) Create an array dist[] of size V and set all values as infinite. Then update dist[src] as 
	   dist[src] = 0, where src is the source vertex. 
	2) This step calculates shortest distances. Do following V-1 times:
		a) Do following for each edge u-v:
			If (dist[v] > dist[u] + weight of edge u-v), then update dist[v] as:
			dist[v] = dist[u] + weight of edge u-v
	3) This step reports if there is a negative weight cycle in graph. Do following for each edge u-v:
			If (dist[v] > dist[u] + weight of edge u-v), then Graph contains negative weight cycle.

	The idea of step 3 is, step 2 guarantees the shortest distances if the graph doesn’t contain a 
	negative weight cycle. If we iterate through all edges one more time and get a shorter path for any 
	vertex, then there is a negative weight cycle. Even though Bellman-Ford detects negative weight 
	cycle it fails to give a Shortest Path for such graphs.

	The algorithm calculates shortest paths in a bottom-up manner. It first calculates the shortest 
	distances which have at-most one edge in the path. Then, it calculates the shortest paths with 
	at-most 2 edges, and so on. After the i-th iteration of the outer loop, the shortest paths with at 
	most i edges are calculated. There can be maximum V–1 edges in any simple path, that is why the 
	outer loop runs V–1 times.

	Time Complexity          : O(V*E)       // practically, takes more time than dijkstra's algorithm.
                             : O(V*V*V)     // for complete graph. ie, E = O(V*V)
	Auxiliary Space          : O()
*/


#include <iostream>
#include <climits>
using namespace std;


// structure to represent a weighted edge in graph
class Edge {
	public:
		int src, dest, weight;
};

// structure to represent a connected, directed and weighted graph
struct Graph {
	public:
		int V, E;            // V-> number of vertices, E-> number of edges.
		Edge* edge;          // graph is represented as an array of edges.
};

// creates a graph with V vertices and E edges
Graph* createGraph(int V, int E) {
	Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[E];
	return graph;
}

void BellmanFord(Graph* graph, int src) {
	int V = graph->V;
	int E = graph->E;
	int dist[V];

	for(int i=0; i<V; i++)
		dist[i] = INT_MAX;        // initialize all distances as INFINITE.
	dist[src] = 0;                // distance of source vertex from itself is always 0.

	for(int i=1; i<=V-1; i++) {        // relax all edges V-1 times. As shortest path from src to 
		for(int j=0; j<E; j++) {       // any other vertex can have atmost V-1 edges
			int u = graph->edge[j].src;
			int v = graph->edge[j].dest;
			int weight = graph->edge[j].weight;
			if((dist[u] != INT_MAX) && (dist[u] + weight < dist[v]))
				dist[v] = dist[u] + weight;
		}
	}

	for (int i=0; i<E; i++) {          // relax all edges one more time to see if any negative weight 
		int u = graph->edge[i].src;    // cycle present or not.
		int v = graph->edge[i].dest;
		int weight = graph->edge[i].weight;
		if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
			printf("Graph contains negative weight cycle");
			return;                    // return if negative cycle is detected.
		}
	}

	printf("Vertex\t\tDistance from Source\n");
    for(int i=0; i<V; i++)
    	cout << i << "\t\t" << dist[i] << "\n";
}


int main() {
	int V = 5;       // number of vertices in graph
	int E = 8;       // number of edges in graph
	Graph* graph = createGraph(V, E);

	// add edge 0-1
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	graph->edge[0].weight = -1;

	// add edge 0-2
	graph->edge[1].src = 0;
	graph->edge[1].dest = 2;
	graph->edge[1].weight = 4;

	// add edge 1-2
	graph->edge[2].src = 1;
	graph->edge[2].dest = 2;
	graph->edge[2].weight = 3;

	// add edge 1-3
	graph->edge[3].src = 1;
	graph->edge[3].dest = 3;
	graph->edge[3].weight = 2;

	// add edge 1-4
	graph->edge[4].src = 1;
	graph->edge[4].dest = 4;
	graph->edge[4].weight = 2;

	// add edge 3-2
	graph->edge[5].src = 3;
	graph->edge[5].dest = 2;
	graph->edge[5].weight = 5;

	// add edge 3-1
	graph->edge[6].src = 3;
	graph->edge[6].dest = 1;
	graph->edge[6].weight = 1;

	// add edge 4-3
	graph->edge[7].src = 4;
	graph->edge[7].dest = 3;
	graph->edge[7].weight = -3;

	BellmanFord(graph, 0);

	return 0;
}