#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u, int v){
    adj[u].push_back(v);
}

void printAdj(vector<int> adj[], int V){
    cout<<"Node 1    Node 2"<<endl;
    for(int i=0;i<V;i++){
        cout<<"  "<<i<<endl;
        for(auto e:adj[i]){
            cout<<"            "<<e<<endl;
        }
        cout<<endl;
    }
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
    
    printAdj(adj,V);
    return 0;
}
