#include<bits/stdc++.h>
using namespace std;


// Method: One important thing to note is, simply doing BFS or DFS
// and picking the longest edge at every step would not work. 
// The reason is, a shorter edge can produce longer path due to higher 
// weight edges connected through it.

// The idea is to use Backtracking. We start from given source, explore 
// all paths from current vertex. We keep track of current distance 
// from source. If distance becomes more than k, we return true.
// If a path doesn’t produces more than k distance, we backtrack.

// How do we make sure that the path is simple and we don’t loop in a cycle?
// The idea is to keep track of visited vertices.



void addEdge(vector<pair<int,int>> adj[], int u, int v, int w){
	adj[u].push_back({v,w});
	adj[v].push_back({u,w});
}

bool pathMoreThanK(int u, int k, vector<pair<int,int>> adj[], vector<bool> &visited){
	if(k<=0) return true;

	// traverse through all neighbours
	for(auto neighbour:adj[u]){
		auto [v,w] = neighbour;
		
		// if v already visited means this path is going
		// to create a cycle thus avoid
		if(visited[v]) continue;

		if(w>=k) return true;

		visited[v] = true;
		if(pathMoreThanK(v,k-w,adj,visited)) return true;

		// backtrack
		visited[v] = false;
	}
	return false;
}

int main(){
	int V = 9;
	vector<pair<int,int>> adj[V];

	addEdge(adj, 0, 1, 4);
	addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);

	int src = 0, k = 62;
	vector<bool> visited(V,false);

	// mark src as visited
	visited[src] = true;

	(pathMoreThanK(src,k,adj,visited))? cout<<"Present\n"  : cout<<"Absent\n";

	k = 60;
	visited.assign(V,false);
	visited[src] = true;
	(pathMoreThanK(src,k,adj,visited))? cout<<"Present\n"  : cout<<"Absent\n";
	return 0;
}
