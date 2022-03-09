#include<bits/stdc++.h>
using namespace std;
 




// Method: Backtracking
// We traverse using DFS and decrement the k according to the edges
// if k becomes 0 or negative we return true, else we backtrack and
// continue other paths




bool DFSUptoK(int src, int k, vector<pair<int,int> > adj[], vector<bool> &visited){
    visited[src] = true;
    if(k<=0) return true;

    for(auto x:adj[src]){
        int u = x.first;
        int w = x.second;
        
        // If node is visited than this marks the begining of a
        // cycle, thus we continue without going into the cycle
        if(visited[u]==true) 
            continue;
        
        // if current edge's weight is greater or equal to k than we have
        // found the path of desired length we return true
        if(w>=k) 
            return true;
        
        // else we check taking this node into the path and if desired length
        // is found we return true, else we backtrack to this node make its visited
        // as false and return false
        if(DFSUptoK(u,k-w,adj,visited))
            return true;

    }
    // making this node visited as false as it would be used by other paths to calculate
    // there distances
    visited[src] = false;
    return false;
}

int main() {
   
    int v,e;
    cin>>v>>e;
    int k;
    cin>>k;
    vector<pair<int,int> > adj[v+1];
    for(int i=0;i<e;i++){
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
    vector<bool> visited(v+1,false);
    cout<<DFSUptoK(1,k,adj,visited);  

    
    return 0;
}


// Input
// 10 11
// 23
// 1 2 1
// 2 3 2
// 3 4 2
// 2 5 5
// 5 6 2
// 6 7 1
// 4 7 3
// 7 10 2
// 9 10 1
// 4 8 4
// 8 9 5

// Output
// 1



