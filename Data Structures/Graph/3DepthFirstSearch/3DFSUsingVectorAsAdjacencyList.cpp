#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u, int v){
    adj[u].push_back(v);
}

void DFSUtil(vector<int> adj[], int u, unordered_map<int,bool> &visited, vector<int> &ans){
        // base condition
        if(visited[u]) return;
        else{
            // set visited true for the cuurent node
            visited[u] = true;
            // push node into ans vector
            ans.push_back(u);
            // traverse through each adjacent node of current node
            // if not visited then recurse through it to reach the
            // last adjacent node of that node and then bottom uply
            // save the nodes in the ans vector
            for(auto e:adj[u])
                if(!visited[e]) DFSUtil(adj,e,visited,ans);
        }
    }

vector<int> DFS(vector<int> adj[], int u){
     // To store the DFS
     vector<int> ans;
     // To keep track of visited nodes while DFSing
     unordered_map<int,bool> visited;
     DFSUtil(adj,u,visited,ans);
     return ans;
}

int main(){
    int V = 9;
    vector<int> adj[V];
    addEdge(adj,0,1);
    addEdge(adj,0,7);
    addEdge(adj,1,7);
    addEdge(adj,1,2);
    addEdge(adj,2,8);
    addEdge(adj,2,5);
    addEdge(adj,2,3);
    addEdge(adj,3,3);
    addEdge(adj,3,4);
    addEdge(adj,5,4);
    addEdge(adj,6,5);
    addEdge(adj,7,8);
    addEdge(adj,7,6);
    addEdge(adj,8,6);
    
    vector<int> ans = DFS(adj,2);
    // Print the DFS traversal from the given node
    for(auto e:ans) cout<<e<<" ";
    return 0;
}
