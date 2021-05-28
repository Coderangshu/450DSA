// A C++ Program to check whether a graph is tree or not
#include<bits/stdc++.h>
using namespace std;

// A graph is tree if:
// i.  There's no cycle
// ii. The graph is connected

// Class for an undirected graph
class Graph
{
    public:
        int V; // No. of vertices
        vector<int> *adj; // Pointer to an array for adjacency lists
	
        Graph(int V) // Constructor
        {
            this->V = V;
            adj = new vector<int>[V];
        }

        void addEdge(int v, int w) // to add an edge to graph
        {
            adj[v].push_back(w); // Add w to v’s list.
            adj[w].push_back(v); // Add v to w’s list.
        }
        
        // A recursive function that uses visited[] and parent to
        // detect cycle in subgraph reachable from vertex v.
        bool isCyclicUtil(int v, bool visited[], int parent)
        {
            // Mark the current node as visited
            visited[v] = true;

            // Recur for all the vertices adjacent to this vertex
            for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
            {
                // If an adjacent is not visited, then recur for
                // that adjacent
                if (!visited[*i])
                    if (isCyclicUtil(*i, visited, v)) return true;

                // If an adjacent is visited and not parent of current
                // vertex, then there is a cycle.
                else if (*i != parent)
                    return true;
            }
            return false;
        }
        
        // Returns true if the graph is a tree, else false.
        bool isTree() // returns true if graph is tree
        {
            // Mark all the vertices as not visited and not part of
            // recursion stack
            bool *visited = new bool[V];
            for (int i = 0; i < V; i++)
                visited[i] = false;

            // The call to isCyclicUtil serves multiple purposes.
            // It returns true if graph reachable from vertex 0
            // is cyclcic. It also marks all vertices reachable
            // from 0.
            if (isCyclicUtil(0, visited, -1))
                    return false;

            // If we find a vertex which is not reachable from 0
            // (not marked by isCyclicUtil(), then we return false
            for (int u = 0; u < V; u++)
                if (!visited[u]) return false;
            return true;
        }
};

// Driver program to test above functions
int main()
{
	Graph g1(5);
	g1.addEdge(1, 0);
	g1.addEdge(0, 2);
	g1.addEdge(0, 3);
	g1.addEdge(3, 4);
	g1.isTree()? cout << "Graph is Tree\n":
				cout << "Graph is not Tree\n";

	Graph g2(5);
	g2.addEdge(1, 0);
	g2.addEdge(0, 2);
	g2.addEdge(2, 1);
	g2.addEdge(0, 3);
	g2.addEdge(3, 4);
	g2.isTree()? cout << "Graph is Tree\n":
				cout << "Graph is not Tree\n";

	return 0;
}
