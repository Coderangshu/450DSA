#include<bits/stdc++.h>
using namespace std;

// The target is to make the given graph as eulerian circuit 
// with the lowest cost of travelling across it
// The problem statement is that the path to be taken by the postman
// so as to traverse every edge atleast once and return to starting
// point(thus also known as Route Inspection Problem). 

// Algorithm:
// (I)   find all vertices with odd edges
// (II)  if no odd edges node then print eulerian circuit
// (III) else get all possible combinations of the odd vertices
//       and find the combination with the lowest cost
// (IV)  add these edges to the graph and print the whole graph

// The printed path is the eulerian circuit for the given graph
// (modified or not modified) 

void addEdge(vector<pair<int,int>> adj[],int u, int v, int weight){
    adj[u].push_back({v,weight});
    adj[v].push_back({u,weight});
}

bool doesEulerianPathExist(vector<pair<int,int>> adj[], int V, vector<int> &degree){
    
    for(int u=0;u<V;u++)
        for(auto v:adj[u])
                    degree[u]++;
    
    vector<int> oddEdgesVertices;
    for(int i=0;i<V;i++){
        if(degree[i]%2!=0) oddEdgesVertices.push_back(i);
    }
    
//     for(auto e:degree) cout<<e<<" ";
//     cout<<endl;
//     for(auto e:oddEdgesVertices) cout<<e<<" ";
//     cout<<endl;
    
    if(oddEdgesVertices.size()==0) return true;
    else return false;
}

vector<int> DFS(int u, int parent, vector<pair<int,int>> adj[], vector<int> &degree, int V){
    static vector<int> path;
    
    if(degree[u]==0) path.push_back(u);
    else{
        for(auto v:adj[u]) if(degree[v.first]>0 and v.first!=parent){
            degree[u]--;
            degree[v.first]--;
            DFS(v.first,u,adj,degree,V);
            if(degree[u]==0) path.push_back(u);
        }
    }
    return path;
}

void printEulerianPath(vector<pair<int,int>> adj[], int V){
    vector<int> degree(V,0);
    if(!doesEulerianPathExist(adj,V,degree)) cout<<"No Possible Eulerian Path";
    else{
        int start, parent = -1;
        for(int i=0;i<V;i++) if(degree[i]%2!=0){
            start = i;
            break;
        }
        vector<int> path = DFS(start,parent,adj,degree,V);
        for(auto e:path) cout<<e<<" -> ";
        cout<<"END"<<endl;
    }
}

int main(){
    int V = 6;
    vector<pair<int,int>> adj[V];
    addEdge(adj,0,1,3);
    addEdge(adj,0,2,1);
    addEdge(adj,0,4,5);
    addEdge(adj,1,3,1);
    addEdge(adj,1,5,6);
    addEdge(adj,2,4,2);
    addEdge(adj,3,5,1);
    addEdge(adj,4,5,4);
    
    printEulerianPath(adj,V);
    
    return 0;
}
