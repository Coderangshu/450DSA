#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int,int>> adj[], int u, int v, int weight){
    adj[u].push_back({v,weight});
}

queue<int> topoSort(int V, vector<pair<int,int>> adj[]) {
    vector<int> in_degree(V,0);

    for (int u = 0; u < V; u++)
        for (auto v : adj[u]) in_degree[v.first]++;

    queue<int> q;
    for (int i = 0; i < V; i++)
        if (in_degree[i] == 0) q.push(i);

    queue<int> topological_order;
        
    while (!q.empty()) {
            
    int u = q.front();
    q.pop();
    topological_order.push(u);

    for (auto e:adj[u]) 
        if (--in_degree[e.first] == 0) q.push(e.first);
    }
    return topological_order;
}

vector<int> longestPath(int src, vector<pair<int,int>> adj[], int V){
    // Getting topological order of DAG
    queue<int> topoOrder = topoSort(V,adj);
    
    // Initialize a distance vector to track distance between two nodes
    // with smallest possible value(herein INT_MIN) 
    vector<int> distance(V,INT_MIN);
    // mark distance of src as 0
    distance[src] = 0;
    
    // Process nodes topologicallly
    while(!topoOrder.empty()){
        int u = topoOrder.front();
        topoOrder.pop();
        
        // we reconstuct the distance of each adjacent node of current node
        // iff the distance of the current node isn't INT_MIN
        if(distance[u]!=INT_MIN)
            for(auto pv:adj[u]){
                int v = pv.first, weight = pv.second;
                // if distance from src->v is smaller than 
                // distance from drc->u + weight of the edge
                // then update distance of v
                distance[v] = max(distance[v],distance[u]+weight);
                // Note: If we take the min we will get the shortest path.
            }
    }
    return distance;
}

int main(){
    
    int V = 6;
    vector<pair<int,int>> adj[V];
    
    
    addEdge(adj, 4, 5, -2);
    addEdge(adj, 0, 1, 5);
    addEdge(adj, 0, 2, 3);
    addEdge(adj, 1, 3, 6);
    addEdge(adj, 1, 2, 2);
    addEdge(adj, 3, 5, 1);
    addEdge(adj, 3, 4, -1);
    addEdge(adj, 2, 4, 4);
    addEdge(adj, 2, 5, 2);
    addEdge(adj, 2, 3, 7);
    
    vector<int> ans = longestPath(1,adj,V);
    
    for(auto e:ans) (e==INT_MIN)? cout<<"INF ": cout<<e<<" ";
    return 0;
}
