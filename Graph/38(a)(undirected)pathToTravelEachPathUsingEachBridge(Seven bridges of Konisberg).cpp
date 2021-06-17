// Eulerian Path:    All edges travelled only once, and starting and ending nodes are different
// Eulerian Circuit: All edges travelled only once, and starting and ending nodes are same

// 4 flavours of Eulerian path/circuit:


//                   |             Eulerian Path            |             Eulerian Circuit
// ---------------------------------------------------------------------------------------------------
// Undirected Graph  | Every vertex has even degree         | Every vertex has even degree or exactly
//                   |                                      | 2 vertices with odd degree, this 2 will
//                   |                                      | be the starting and ending of the path
//----------------------------------------------------------------------------------------------------
// Directed Graph    | Every vertex has equal inDegree and  | Atmost 1 vertex has outDegree-inDegree=1
//                   | outDegree                            | and atmost 1 with inDegree-outDegree=1
//                   |                                      | rest all must have equal number of 
//                   |                                      | inDegree and outDegree

// To understand better : https://youtu.be/xR4sGgwtR2I (Eularian Path Theory)
//                        https://youtu.be/8MpoO2zA2l4 (Eularian Path finding using modified DFS)






#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool doesEulerianPathExist(vector<int> adj[], int V, vector<int> &degree){
    
    for(int u=0;u<V;u++)
        for(auto v:adj[u])
                    degree[u]++;
    
    int countOdd = 0;
    for(auto e:degree){
        // If node has no degree means graph is
        // disconnected thus no Eulerian path is
        // possible
        if(e==0) return false;
        if(e%2!=0) countOdd++;
    }
    if(countOdd==2 or countOdd==0) return true;
    else return false;
}

vector<int> DFS(int u, int parent, vector<int> adj[], vector<int> &degree, int V){
    // stores the Eulerian path
    static vector<int> path;
    
    // if degree is 0 means no other nodes to go
    // from here thus include in path and recurse back 
    if(degree[u]==0) path.push_back(u);
    else{
        // parent stores the parent of u
        // we check if not parent because from current
        // node we need to move forward not back to the
        // parent again
        for(auto v:adj[u]) if(degree[v]>0 and v!=parent){
            // we decrement degree of both u and v
            degree[u]--;
            degree[v]--;
            // send v to be traversed DFSely
            DFS(v,u,adj,degree,V);
            // if degree of u has become 0 add to path
            if(degree[u]==0) path.push_back(u);
        }
    }
    return path;
}

void printEulerianPath(vector<int> adj[], int V){
    // Check if Eulerian Path is possible and get number of degrees
    // of each nodes
    vector<int> degree(V,0);
    if(!doesEulerianPathExist(adj,V,degree)) cout<<"No Possible Eulerian Path";
    else{
        // Consider the node with the lowest number with odd degree as the
        // starting point
        int start, parent = -1;
        for(int i=0;i<V;i++) if(degree[i]%2!=0){
            start = i;
            break;
        }
        // Do DFS from the start node
        vector<int> path = DFS(start,parent,adj,degree,V);
        for(auto e:path) cout<<e<<" -> ";
        cout<<"END"<<endl;
    }
}

int main(){
    
    // Graph 1:
    // 
    //     0-----1
    //    /    / |
    //   /    /  |
    //  4    3---2
    // 
    // 
    // 
    int V = 5;
    vector<int> adj[5];
    addEdge(adj,0,1);
    addEdge(adj,0,4);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,2,3);
    printEulerianPath(adj,V);
    
    
    // Graph 2:
    // 
    //    0------1
    //   /  \   /|
    //  /    \ / |
    // 4      \  |
    //  \    / \ |
    //   \  /   \| 
    //    2------3
    // 
    // 
    // 
    
    V = 5;
    vector<int> adj1[5];
    addEdge(adj1,0,1);
    addEdge(adj1,0,3);
    addEdge(adj1,0,4);
    addEdge(adj1,1,2);
    addEdge(adj1,1,3);
    addEdge(adj1,2,3);
    addEdge(adj1,2,4);
    printEulerianPath(adj1,V);
 
    return 0;
}
