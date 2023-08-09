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
    for (int i = 0; i < V; i++) if (in_degree[i]==0) q.push(i);

    queue<int> topological_order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topological_order.push(u);
        for (auto e:adj[u]) if(--in_degree[e.first]==0) q.push(e.first);
    }
    return topological_order;
}

// longest path finding method is similar to shortest path
// understand shortest first then see longest below
vector<int> shortestPath(vector<pair<int,int>> adj[], int V){
    // Getting topological order of DAG
    queue<int> topoOrder = topoSort(V,adj);
    
    // Initialize a distance vector to track distance between two nodes
    // with smallest possible value(herein INT_MAX) 
    vector<int> distance(V,INT_MAX);
    // mark distance of first topo node as 0
    distance[topoOrder.front()] = 0;
    
    // Process nodes topologically
    while(!topoOrder.empty()){
        int u = topoOrder.front();
        topoOrder.pop();
        
        // we reconstuct the distance of each adjacent node of current node
        // iff the distance of the current node isn't INT_MAX
        if(distance[u]!=INT_MAX){
            for(auto &[v,weight]:adj[u]){
                // if distance from src->v is smaller than 
                // distance from drc->u + weight of the edge
                // then update distance of v
                distance[v] = min(distance[v],distance[u]+weight);
            }
        }
    }
    return distance;
}


// longest path finding generally a NP hard problem, but for DAG we
// can use the above method which is of O(E+V) time.
// The concept is simple convert all edge weights to their negative
// then do the same as above and at last return the weight of all nodes
// after sign reversing
vector<int> longestPath(vector<pair<int,int>> adj[], int V){
    queue<int> topoOrder = topoSort(V,adj);

    vector<int> distance(V,INT_MAX);
    distance[topoOrder.front()] = 0;
    
    while(!topoOrder.empty()){
        int u = topoOrder.front();
        topoOrder.pop();
        if(distance[u]!=INT_MAX){
            for(auto &[v,weight]:adj[u]){
                distance[v] = min(distance[v],distance[u]-weight);
            }
        }
    }
    for(auto &e:distance) e *= -1;
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
    
    vector<int> sans = shortestPath(adj,V);
    vector<int> lans = longestPath(adj,V);
    
    for(auto e:sans) (e==INT_MAX)? cout<<"INF ": cout<<e<<"\t";
    cout<<endl;
    for(auto e:lans) (e==INT_MAX)? cout<<"INF ": cout<<e<<"\t";
    return 0;
}
