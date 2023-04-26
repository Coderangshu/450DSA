#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void greedyColoring(vector<int> adj[], int V){
    // Initialize all node as uncolored
    vector<int> color_array(V,-1);
    
    // Assign the first color to first vertex
    color_array[0]  = 0;
    
    // A temporary array to store the available colors. True
    // value of available[cr] would mean that the color cr is
    // assigned to one of its adjacent vertices
    vector<bool> unavailable(V,false);
    
    
    
    
    // Method: take each node and mark their adjacent node's colors as
    // unavailable then search through the color array to see the lowest
    // possible color that is available assign that to the current node
    // and make all the adjacent node' s color available
    
    
    // Assign colors to remaining V-1 vertices
    for (int u = 1; u < V; u++){
        // mark all colors that have been assigned to adjacent vertices
        // as unavailable
        for (auto e:adj[u])
            if (color_array[e] != -1)
                unavailable[color_array[e]] = true;
 
        // Find the first available color
        int cr;
        for (cr = 0; cr < V; cr++)
            if (unavailable[cr] == false)
                break;
 
        // Assign the found color
        color_array[u] = cr;
 
        // Reset the colors back to false for the next iteration
        for (auto e:adj[u])
            if (color_array[e] != -1)
                unavailable[color_array[e]] = false;
    }
    
    // print the result
    for (int u = 0; u < V; u++)
        cout << "Vertex " << u << " --->  Color "<< color_array[u] << endl;
}

int main(){
    
    // Graph 1
    int V = 5;
    vector<int> adj1[V];
    addEdge(adj1, 0, 1);
    addEdge(adj1, 0, 2);
    addEdge(adj1, 1, 2);
    addEdge(adj1, 1, 3);
    addEdge(adj1, 2, 3);
    addEdge(adj1, 3, 4);
    cout << "Coloring of graph 1 \n";
    greedyColoring(adj1, V);
 
    
    // Graph 2
    vector<int> adj2[V];
    addEdge(adj2, 0, 1);
    addEdge(adj2, 0, 2);
    addEdge(adj2, 1, 2);
    addEdge(adj2, 1, 4);
    addEdge(adj2, 2, 4);
    addEdge(adj2, 4, 3);
    cout << "\nColoring of graph 2 \n";
    greedyColoring(adj2, V);
    
    return 0;
}
