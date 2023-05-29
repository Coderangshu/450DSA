#include<bits/stdc++.h>
using namespace std;

void addEdge(int u, int v, vector<int> adj[]){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool isCyclicUtil(vector<int>adj[], int u, unordered_map<int,bool> &visited, int parent){
    if(visited[u]) return false;
    else{
        visited[u] = true;
        for(auto e:adj[u]){
            // If not visited but it is involved in a cycle then return true
            if(!visited[e]){
                if(isCyclicUtil(adj,e,visited,u)) return true;
            }
            // If this adjacent node is visited while coming to this node,
            // but this node is not parent of the current node then return true
            // Because when no cycle is present for a node its adjacent won't be
            // tagged as visited except for the parent node of the current node,
            // thus when a non parent node is visited this means that theres a 
            // cycle in this node network
            else if(e!=parent) return true;
        }
    }
    return false;
}

bool isCyclic(vector<int> adj[], int V){
    // To keep track of visited nodes while DFSing
    unordered_map<int,bool> visited;
    
    for(int u=0;u<V;u++){
        if(!visited[u] and isCyclicUtil(adj,u,visited,-1)) return true;
    }
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
