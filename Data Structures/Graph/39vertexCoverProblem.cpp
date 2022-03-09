// If interested see 2 methods of finding vertex cover number using DP(for tree)
// or binary search(Using Gosper's Hack) 


#include<bits/stdc++.h>
using namespace std;

// Goal is to find the least number of nodes using which 
// we can cover all the edges of the graph
// For this we go through all the nodes in a adjacency list
// And mark them and the edge's other node as visited and add
// them to the ans, we mark them as visited as we do not add them
// in the ans again when related with some other edge


// This is a approximate method this provides us with the answer
// that is less than twice the actual answer.



void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printVertexCover(vector<int> adj[], int V){
    // visited vector
    vector<bool> visited(V,false);
    
    // nodes which will have covered all the edges
    vector<int> ans;
    
    // Consider all edges one by one
    for (int u=0; u<V; u++){
        // An edge is only picked when both visited[u] and visited[v]
        // are false
        if(visited[u]==false){
            // Go through all adjacents of u and pick the first not
            // yet visited vertex (We are basically picking an edge
            // (u, v) from remaining edges.
            for (auto v:adj[u]){
                if (visited[v]==false){
                    // Add the vertices (u, v) to the result set.
                    // We make the vertex u and v visited so that
                    // all edges from/to them would be ignored
                    ans.push_back(u);
                    ans.push_back(v);
                    visited[v] = true;
                    visited[u]  = true;
                    break;
                }
            }
        }
    }
    for(auto e:ans) cout<<e<<" ";
    cout<<endl;
}

int main(){
    int V = 7;
    vector<int> adj[V];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,3);
    addEdge(adj,3,4);
    addEdge(adj,4,5);
    addEdge(adj,5,6);
    
    printVertexCover(adj,V);
    return 0;
}
