#include<bits/stdc++.h>
using namespace std;

void addEdge(int u, int v, vector<int> adj[]){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool isCyclicUtil(vector<int>adj[], int v, unordered_map<int,bool> &visited, int V){
    queue<int> q;
    // Initiating a parent vector with -1 for all nodes
    vector<int> parent(V,-1);
    
    // First node visited marked true and pushed into queue
    visited[v] = true;
    q.push(v);
    while(!q.empty()){
        // First element of queue poped
        int u = q.front();
        q.pop();
        // Checking all the adjacent nodes of the poped node
        for(auto v:adj[u]){
            // If node not visited then mark true push into
            // queue and mark its parent as the popped node
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
                parent[v] = u;
            }
            // If visited then check the node's parent if the
            // node isn't the popped node(i.e. the adjacent node
            // that has been visited previously but its parent isn't
            // the current node this means that this node is part of
            // a cycle) then return true
            else if(parent[u]!=v)
                return true;
        }
    }
    return false;
}

bool isCyclic(vector<int> adj[], int V){
    // To keep track of visited nodes while DFSing
    unordered_map<int,bool> visited;
    
    for(int u=0;u<V;u++)
        if(!visited[u] and isCyclicUtil(adj,u,visited,V)) return true;
    return false;
}

int main(){
    int V = 5;
    vector<int> adj[V];
    addEdge(0,2,adj);
    addEdge(0,3,adj);
    addEdge(1,0,adj);
    // Uncomment next line to make a cycle in graph
//     addEdge(2,1,adj);
    addEdge(3,4,adj);

    cout<<isCyclic(adj,V)<<endl;
}
