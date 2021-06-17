#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u, int v){
    adj[u].push_back(v);
}

bool doesEulerianPathExist(vector<int> adj[], int V, vector<int> &outDegree, int &start){
    vector<int> inDegree(V,0);
    
    for(int u=0;u<V;u++)
        for(auto v:adj[u]){
                    outDegree[u]++;
                    inDegree[v]++;
        }
    int inGTOut = 0, outGTIn = 0;
    for(int i=0;i<V;i++){
        // If node has no in and out degree means
        // graph is disconnected thus no Eulerian 
        // path is possible
        if(inDegree[i]==0 and outDegree[i]==0) return false;
        else{
            // if outDegree is more than inDegree than
            // this is starting point of path
            if(outDegree[i]>inDegree[i]){
                start = i;
                outGTIn++;
            }
            else if(outDegree[i]<inDegree[i]) inGTOut++;
        }
    }
    if(outGTIn<=1 and inGTOut<=1) return true;
    else return false;
}




// Beautifully crafted modified DFS, go through the function
stack<int> DFS(int u, vector<int> adj[], vector<int> &outDegree){
    // stack used because the last node of the path will be obtained
    // first
    static stack<int> path;
    
    // outDegree serves 2 purposes
    // (I)  keeps count of number of outgoing edges still left for current node
    // (II) acts as an index in the adjacency list for the neighhbor of current node
    
    // notice here we traverse the last neighhbor of a particular node first
    while(outDegree[u]>0){
        // taking the last neighhbor of current node as the next node
        int v = adj[u][--outDegree[u]];
        DFS(v,adj,outDegree);
    }
    path.push(u);
    return path;
}




void printEulerianPath(vector<int> adj[], int V){
    // Check if Eulerian Path is possible and get number of outDegree
    // of each nodes
    vector<int> outDegree(V,0);
    // store the starting index
    int start;
    if(!doesEulerianPathExist(adj,V,outDegree,start)) cout<<"No Possible Eulerian Path";
    else{
        // Do DFS from the start node
        stack<int> path = DFS(start,adj,outDegree);
        while(!path.empty()){
            cout<<path.top()<<"->";
            path.pop();
        }
        cout<<"END"<<endl;
    }
}

int main(){
    // Graph 1:
    //      
    //      node 1 has a self edge
    //      
    //        --
    //       /  \ 
    //      /   <|
    //     1---->3------>5
    //     |>|>  |     / |>
    //      | \  |    /   |
    //      |  \ |   /    |
    //      |   \<| |>    |
    //      0<---->2----->4
    // 
    // 
    //
        
    int V = 6;
    vector<int> adj[V];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,1);
    addEdge(adj,1,3);
    addEdge(adj,1,3);
    addEdge(adj,2,0);
    addEdge(adj,2,1);
    addEdge(adj,2,4);
    addEdge(adj,3,2);
    addEdge(adj,3,5);
    addEdge(adj,4,5);
    addEdge(adj,5,2);
    
    printEulerianPath(adj,V);
        
    return 0;
}
