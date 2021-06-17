#include <bits/stdc++.h>
using namespace std;

void addEdge(int u, int v, vector<int> adj[]){
    adj[u].push_back(v);
}

bool isCycle(vector<int> adj[], int V){
    vector<int> in_degree(V,0);

    for (int u = 0; u < V; u++)
        for (auto v : adj[u]) in_degree[v]++;
    
    queue<int> q;
    for (int i = 0; i < V; i++)
        if (in_degree[i] == 0) q.push(i);

    int cnt = 0;

    vector<int> topological_order;
    
    while (!q.empty()) {

        int u = q.front();
        q.pop();
        topological_order.push_back(u);

        for (auto e:adj[u]) 
            if (--in_degree[e] == 0) q.push(e);
        cnt++;
    }

    // cnt == V means no cycle present
    if (cnt != V) return false;
    else return true;
}

int main(){
    // No of vertices
    int V, numOfRelatedJobs;
    cin>>V>>numOfRelatedJobs;
    
    vector<int>adj[V];
    
    for(int i=0;i<numOfRelatedJobs;i++){
        int u,v;
        cin>>v>>u;
        addEdge(u,v,adj);
    }
    
    cout<<isCycle(adj,V)<<endl;
}
