#include<bits/stdc++.h>
using namespace std;

void addEdge(int u, int v, vector<int> adj[]){
    adj[u].push_back(v);
}


// Concept used is Kahn's algorithm of topological sorting
// Herein the nodes with 0 indegree(nuber of incoming edges)
// are at the top level, the next level consist of the next
// lowest indegree nodes and so on.
// Example:
// Let adjacency list be :
// 0:
// 1:
// 2: 3
// 3: 1
// 4: 0 1
// 5: 0 2
// Here 4 & 5 have 0 indegree, 2 & 3 have 1 indegree, 0 & 1 have 2
// indegrees.
// Thus the topological soting of this graph can be:
// 5 4 2 3 0 1 or 4 5 2 3 1 0 or many other possible combinations

// The method to do the same is indegree vector of size as number of
// vertices is made and for each of the node the number of indegree are
// calculated
// In a queue the nodes with 0 indegree are inserted and a while loop
// runned untill queue is empty, queue.top is poped and pushed into
// topological order answer vector a count parameter Initialized with 0
// is incremented as there's an entry to the answer vector, and then for
// each of its adjacent nodes the indegree is decremented and if it becomes
// 0 then pushed into the queue, this continues untill all indegree are 0
// and inserted into the queue and the queue isn't empty.
// Atlast the count parameter is checked with the number of nodes in graph
// if equal then topological order is present (also impying that no cycle
// if present in the graph), else if not equal means a cycle is present and
// thus no topological order present.


bool isCycle(vector<int> adj[], int V){
    // Create a vector to store indegrees of all
    // vertices. Initialize all indegrees as 0.
    vector<int> in_degree(V,0);
    
    // Traverse adjacency lists to fill indegrees of
    // vertices. This step takes O(V+E) time
    // Here from node u we go to all its adjacent nodes
    // and increament each of those's indegrees.
    for (int u = 0; u < V; u++)
        for (auto v : adj[u]) in_degree[v]++;
    
    // Create an queue and enqueue all vertices with
    // indegree 0, as in topological sorting of graph
    // the nodes with lowest indegree are on the top
    queue<int> q;
    for (int i = 0; i < V; i++)
        if (in_degree[i] == 0) q.push(i);
    
    // Initialize count of visited vertices
    int cnt = 0;
 
    // Create a vector to store result (A topological
    // ordering of the vertices)
    vector<int> topological_order;
    
    // One by one dequeue vertices from queue and enqueue
    // adjacents if indegree of adjacent becomes 0
    while (!q.empty()) {
 
        // Extract front of queue (or perform dequeue)
        // and add it to topological order
        int u = q.front();
        q.pop();
        topological_order.push_back(u);
 
        // Iterate through all its neighbouring nodes
        // of dequeued node u and decrease their in-degree
        // by 1
        for (auto e:adj[u]) 
            // If in-degree becomes zero, add it to queue
            if (--in_degree[e] == 0) q.push(e);
        cnt++;
    }
    // Check if there was a cycle
    // If cnt != number of nodes in graph implies no
    // topological sorting is possible and thus cycle
    // is present else no cycle
    if (cnt != V) return true;
    else return false;
}

int main(){
    // No of vertices
    int V = 6;
    vector<int>adj[V];
        
    addEdge(0,1,adj);
    addEdge(1,2,adj);
    addEdge(2,3,adj);
    addEdge(3,4,adj);
    addEdge(4,5,adj);
    // Above graph is acyclic
    // Uncomment below line to make cyclic
    // addEdge(5,3,adj);
        
    cout<<isCycle(adj,V)<<endl;
}
