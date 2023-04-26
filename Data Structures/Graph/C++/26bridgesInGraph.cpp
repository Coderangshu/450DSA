// For complete understanding
// https://www.youtube.com/watch?v=2rjZH0-2lhk


#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bridgeUtil(int u, int parent, vector<int> adj[], vector<bool> &visited, 
                vector<int> &timeOf1stVisit, vector<int> &lowestPossibleTime, int timer){
    
    // mark node visited
    visited[u] = true;
    
    // set timeOf1stVisit and lowestPossibleTime as current value of timer
    timeOf1stVisit[u] = lowestPossibleTime[u] = timer++;
    
    // standard DFS procedure go through all adjacent nodes
    for(auto v:adj[u]){
        // if parent we do not modify its lowest time as from parent the children
        // will have arrived thus modifying that would disturb the whole subtree
        // below it
        if(v==parent) continue;
        // we send the unvisited node to DFS and find the bridges in its subtree
        else if(!visited[v]){
            bridgeUtil(v,u,adj,visited,timeOf1stVisit,lowestPossibleTime,timer);
            // the above line makes sure that v has visited and marked all nodes below it
            // v has its lowest possible time for itself
            
            // as for the edge u-v if v is visited earlier than u, then u can also
            // be visited in the same time as both are connected by this edge
            // thus u will be reached in minimum of its or v's lowest possible time
            lowestPossibleTime[u] = min(lowestPossibleTime[u],lowestPossibleTime[v]);
            
            // now if after all changes made(or not made) if v's lowest possible visiting
            // time is more than the time that is taken reaching u for the first time
            // this means that v can only be reached via this edge as if other edges would
            // have been present than the lowest time for it would have been lesser than that
            // of reaching u for the first time, thus this edge is a bridge
            if(lowestPossibleTime[v]>timeOf1stVisit[u]) cout<<u<<" ---- "<<v<<endl;
        }
        // else if v already visited means that v is reached via some other node's
        // edge thus its time of 1st visit might be lower than the lowest possible time of visit
        // of u thus we check and update it if necessary
        else
        lowestPossibleTime[u] = min(timeOf1stVisit[v],lowestPossibleTime[u]);
    }
}

void bridge(vector<int> adj[], int V){
    // mark all nodes as unvisited
    vector<bool> visited(V,false);
    // store the time when first encountered with particular node
    vector<int> timeOf1stVisit(V,-1);
    // store the lowest possible time to reach a node
    vector<int> lowestPossibleTime(V,-1);
    
    // Making call to utility funtion to find bridge using DFS
    for(int i=0;i<V;i++){
        // timer starts from 0 for each node
        if(!visited[i]) bridgeUtil(i,-1,adj,visited,timeOf1stVisit,lowestPossibleTime,0);
    }
}

int main(){
    
    // Graph 1
    cout << "\nBridges in first graph \n";
    int V = 5;
    vector<int> adj1[V];
    addEdge(adj1, 1, 0);
    addEdge(adj1, 0, 2);
    addEdge(adj1, 2, 1);
    addEdge(adj1, 0, 3);
    addEdge(adj1, 3, 4);
    bridge(adj1,V);
  
    cout << "\nBridges in second graph \n";
    V = 4;
    vector<int> adj2[V];
    addEdge(adj2, 0, 1);
    addEdge(adj2, 1, 2);
    addEdge(adj2, 2, 3);
    bridge(adj2,V);
  
    cout << "\nBridges in third graph \n";
    V = 7;
    vector<int> adj3[V];
    addEdge(adj3, 0, 1);
    addEdge(adj3, 1, 2);
    addEdge(adj3, 2, 0);
    addEdge(adj3, 1, 3);
    addEdge(adj3, 1, 4);
    addEdge(adj3, 1, 6);
    addEdge(adj3, 3, 5);
    addEdge(adj3, 4, 5);
    bridge(adj3,V);

    return 0;
}
