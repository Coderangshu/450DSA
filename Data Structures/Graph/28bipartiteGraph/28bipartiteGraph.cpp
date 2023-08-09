#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}




// Method: We use the concept of graph coloring using just 2 colors as
// we need to fina a bipartite graph, and in bipartite graph the nodes can
// be colored with 2 colors, we use either BFS or DFS to color the nodes
// we color a node with one color than colring its adjacents with the other
// color, and in doing so if any anomaly is found then it means a odd cycle
// is present meaning a non bipartite graph, else its a bipartite graph
// (contains even cycle) 

// BFS procedure of coloring nodes
bool isBipartiteUtil(int u, vector<int> adj[], int V, vector<int> &color){
    cout<<"Using BFS"<<endl;
    // standard BFS is followed to assign the colors
    queue<int> q;
    q.push(u);
    color[u] = 1;
    
    while(!q.empty()){
        int currentNode = q.front();
        q.pop();
        // Traversing thorugh all adjacents
        for(auto v:adj[currentNode]){
            // if node not colored yet assign the other
            // color and push to queue for further processing
            if(color[v]==-1){
                color[v] = 1-color[currentNode];
                q.push(v);
            }
            // if color assigned and is same as currentNode then
            // bipartite isn't possible 
            else if(color[v]==color[currentNode]) return false;
        }
    }
    return true;
}

// DFS procedure of coloring nodes
// here we have to carry the color from the previous node as recursive calls are made
// and we aren't sure of the color of the previus node
bool isBipartiteUtil(int u, vector<int> adj[], int V, vector<int> &color, int colorOfu){
    // if u is colored but not with colorOfu then not bipartite
    if(color[u]!=-1 and color[u]!=colorOfu) return false;
    
    // assign colorOfu to u
    color[u] = colorOfu;
    
    // We assume ans will be true for this particular node and its subgraph
    bool ans = true;
    
    // traverse adjacents
    for(auto v:adj[u]){
        // same methodology as above BFS 
        if(color[v]==-1){
            // ans &(operator) the bool of subgraph gives us the answer
            ans &= isBipartiteUtil(v,adj,V,color,1-colorOfu);
        }
        else if(color[v]==color[u]) return false;
    }
    return true;
}

bool isBipartite(int V, vector<int> adj[]){
    // We will use 2 colors only(0,1) as we need to detect a bipartite
    // behaviour, initially no color is assigned thus -1 is stored
    // vector to keep track of color of each node
    vector<int> color(V,-1);
    
    // This loop runs for all nodes so as when theres a disconnected graph
    // their is no node that is left out
    for(int i=0;i<V;i++){
        // if color isn't assigned means the node hasn't been traversed yet
        // if any of the node isn't bipartite we return false
        if(color[i]==-1)
            // to traverse via DFS instead of default BFS add a last attribute
            // as the color of the currentNode you want it may be 0 or 1
            if(!isBipartiteUtil(i,adj,V,color,1))
                return false;
    }
    // else return true
    return true;
}

int main(){
    
    // Graph 1 (Not Bipartite)
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    
    (isBipartite(V,adj))? cout<<"Bipartite"<<endl:cout<<"Not Bipartite"<<endl;
    
    // Graph 2 (Bipartite) 
    V = 4;
    vector<int> adj1[V];
    addEdge(adj1,0,1);
    addEdge(adj1,0,3);
    addEdge(adj1,1,2);
    addEdge(adj1,2,3);
    
    (isBipartite(V,adj1))? cout<<"Bipartite"<<endl:cout<<"Not Bipartite"<<endl;
    return 0;
}
