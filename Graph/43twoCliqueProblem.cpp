#include<bits/stdc++.h>
using namespace std;




// Method: The question is to able to divide graph into 2 parts
// such that each part is connected to all the nodes of each and
// the other part is also connected to all its part's nodes

// To find this we first get the complement graph of the original
// graph then we check if the complement graph is a bipartite or not
// if bipartite then the original graph is a clique

// The intuition is that when we find the complement graph the nodes that
// are connected to each other gets disconnected and the ones that are
// disconnected gets connected then when we find a bipartite in this
// then we know that the complement can be broken into 2 graph which 
// have connecting nodes on both disjoint sets indepentdent of other
// pairs (bipartite property), thus we are sure that the complement of
// the complement will have all the nodes of a disjoint connected to each
// other and also same for the other disjoint set.




void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}


// DFS method to check if bipartite 
bool isBipartiteUtil(int u, vector<int> adj[], int V, vector<int> &color, int colorOfu){
    if(color[u]!=-1 and color[u]!=colorOfu) return false;
    
    color[u] = colorOfu;
    
    bool ans = true;
    
    for(auto v:adj[u]){
        if(color[v]==-1)
            ans &= isBipartiteUtil(v,adj,V,color,1-colorOfu);
        else if(color[v]==color[u]) return false;
    }
    return true;
}

// to check whether graph is bipartite or not
bool isBipartite(int V, vector<int> adj[]){
    vector<int> color(V,-1);
    
    for(int i=0;i<V;i++){
        if(color[i]==-1)
            if(!isBipartiteUtil(i,adj,V,color,1))
                return false;
    }
    return true;
}

// Returns true if G can be divided into
// two Cliques, else false.
bool canBeDividedinTwoCliques(vector<int> adj[], int V)
{
    // Find complement of the original graph
    // i.e. connect the nodes to each node which aren't 
    // connected in the original graph and disconnect
    // the nodes that are connected to each other
    // Example:
    // Let adj list be as follows:
    // 0 -> 1,2,3
    // 1 -> 0,2
    // 2 -> 0,1
    // 3 -> 0,4
    // 4 -> 3
    // Its complement graph would be:
    // 0 -> 4
    // 1 -> 3,4
    // 2 -> 3,4
    // 3 -> 1,2
    // 4 -> 0,1,2
    
    // Getting the complement graph
    vector<int> compAdj[V];
    for (int i=0; i<V; i++)
        for(int j=0;j<V;j++)
            if(j!=i)
                if(find(adj[i].begin(),adj[i].end(),j)==adj[i].end())
                    compAdj[i].push_back(j);
  
    // Return true if complement is Bipartite
    // else false.
    return  isBipartite(V,compAdj);
}

int main(){
    int V = 5;
    vector<int> adj[V];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,0,3);
    addEdge(adj,3,4);
    // Uncomment below line to get non clique graph
    // addEdge(adj,4,0);
    
    (canBeDividedinTwoCliques(adj,V))?cout<<"Contains Cliques":cout<<"Doesn't contain Cliques";
    return 0;
}
