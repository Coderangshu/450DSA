#include<bits/stdc++.h>
using namespace std;

// property of directed graph: if we reverse all the connections, the number of strongly connected
// components remains the same and also each of the component's nodes remains the same

// Algorithm: Kosaraju's Algorithm uses the above property to find the SCCs in a graph.

//            Step 1: DFS traversing is done of the graph and the nodes are stored in a stack
//                    from leaf to root.
//            Step 2: The graph's directed edges are reversed 
//            Step 3: Using the stack and the new graph the SCCs are determined


// The fundamental is when we travel from one SCC to another it is a one way trip, when we reverse
// the edges than from that same SCC we cannot go to the next as the edge has been reversed, thus we
// have to jump manually to the next node using the help of the stack created previously, thus marking
// the beginning of a new SCC, thus the number of manual jumps determine the number of SCCs in the graph

// Time complexity: O(3*(V+E)) ~ O(V+E)
// 3 -> 2 DFS, 1 reversing


// Function to DFS and store node in stack leaf to root
void DFSToStk(int u, vector<int> adj[], vector<bool> &visited, stack<int> &stk){
    // Mark current node as visited
    visited[u] = true;
    for(auto v:adj[u]) if(!visited[v])
        DFSToStk(v,adj,visited,stk);
    // After traversing is over push current node to stack
    // as all the nodes after it are already added
    stk.push(u);
}

// Reverse the edges
void reverseGraphEdges(vector<int> adj[], int V, vector<int> revAdj[]){
    // For each node in adj we take each of its neighbours and push the node into
    // each of the neighbour's vector
    for(int v=0;v<V;v++)
        for(auto u:adj[v]) revAdj[u].push_back(v);
}

// Function to traverse and mark and print the nodes as visited in the reversed graph until 
// next node isn't reachable
void DFSRev(int u, vector<int> adj[], vector<bool> &visited){
    // Print the node as it is part of a particular SCC
    cout<<u<<" ";
    visited[u] = true;
    for(auto v:adj[u]) if(!visited[v]) DFSRev(v,adj,visited);
}
// For better understanding watch 
// https://www.youtube.com/watch?v=Rs6DXyWpWrI

// Function to find the SSCs
void findSCCs(vector<int> adj[], int V){
    // Initiating the stack and the visited vector
    stack<int> stk;
    vector<bool> visited(V,false);
    
    
    // Step 1:
    // DFSing the original graph and storing leaf to root in stack
    for(int i=0;i<V;i++) if(!visited[i]) DFSToStk(i,adj,visited,stk);
    
    
    // Step 2:
    // Reversing the original graph
    vector<int> revAdj[V];
    reverseGraphEdges(adj,V,revAdj);
    
    
    // Step 3:
    // reseting visited array to be used by the 2nd DFS
    for(int i=0;i<V;i++) visited[i] = false;
    
    cout<<"Strongly connected components are: "<<endl;
    
    // To count number of SCCS
    int count = 0;
    // Continuing till stack isn't empty
    while(!stk.empty()){
        // Taking top node of stack and poppping it
        // when a not visited node is encountered marking the
        // beginning of a new SCC the DFS is called again to print
        // and mark those nodes as visited under the next SCC.
        int currentNode = stk.top();
        stk.pop();
        //
        if(!visited[currentNode]){
            cout<<"SCC number "<<++count<<":"<<endl;
            DFSRev(currentNode,revAdj,visited);
            cout<<endl;
        }
    }
}

int main(){
    
    // Creating adjacency list of graph
    int V = 8;
    vector<int> adj[V];
    adj[0].push_back(1);
	adj[1].push_back(2);
	adj[2].push_back(0);
	adj[2].push_back(3);
	adj[3].push_back(4);
	adj[4].push_back(5);
	adj[4].push_back(7);
	adj[5].push_back(6);
	adj[6].push_back(4);
	adj[6].push_back(7);
    
    findSCCs(adj,V);
    return 0;
}
