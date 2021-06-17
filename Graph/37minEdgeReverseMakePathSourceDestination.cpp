#include<bits/stdc++.h>
using namespace std;


// Method: For given graph it is an unweighted graph, thus we set the
// graph with reverse edges for all the edges present with a cost of 1
// thus original edges have cost 0 and reversed edges have cost 1.
// Using dijkstra's algorithm we find the shortest possible path from
// source to destinationm, herein the algorithm uses the reversed edges
// wherever necessary to find the shortest distance to destination
// and the cost of the total path gives us the number of reversed edges.



class Graph{
    int V,E;
    vector<pair<int,int>> *adj;
    
public:
    // Constructor
    Graph(int V, int E){
        this->V = V;
        this->E = E;
        this->adj = new vector<pair<int,int>> [V];
    }
    
//     Destructor
//     ~Graph(){
//         delete this->adj;
//     };
    
    void addEdge(int u, int v, int w){
        adj[u].push_back({v,w});
    }
    
    //    method adds reverse edge of each original edge
    //    in the graph. It gives reverse edge a weight = 1
    //    and all original edges a weight of 0. Now, the
    //    length of the shortest path will give us the answer.
    //    If shortest path is p: it means we used p reverse
    //    edges in the shortest path.
    void modelGraphWithEdgeWeight(int edge[][2]){
        for (int i=0;i<this->E;i++){
            // original edge : weight 0
            this->addEdge(edge[i][0], edge[i][1], 0);
    
            // reverse edge : weight 1
            this->addEdge(edge[i][1], edge[i][0], 1);
        }
    //     return g;
    }
    
    // Get shortest paths from src to all other vertices
    // using dijkstra's algorithm
    vector<int> shortestPath(int src){
        vector<bool> visited(this->V,false);
        
        vector<int> distance(this->V,INT_MAX);
        distance[src] = 0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        minHeap.push({0,src});
        
        while(!minHeap.empty()){
            auto [cost,u] = minHeap.top();
            minHeap.pop();
            visited[u] = true;
            for(auto node:this->adj[u]){
                auto [v,w] = node;
                if(!visited[v]){
                    distance[v] = min(distance[v],cost+w);
                    minHeap.push({distance[v],v});
                }
            }
        }
        return distance;
    }
};

// Method returns minimum number of edges to be
// reversed to reach from src to dest
int getMinEdgeReversal(int edge[][2], int E, int V, int src, int dest){
    //  get modified graph with edge weight of original as 0
    //  and the modified with 1
    Graph g(V,E);
    g.modelGraphWithEdgeWeight(edge);
 
    // get shortest path vector
    vector<int> dist = g.shortestPath(src);
 
    // If distance of destination is still INT_MAX,
    // not possible
    if (dist[dest] == INT_MAX)
        return -1;
    else
        return dist[dest];
}

int main(){
    int V = 7;
    int edge[][2] = {{0, 1}, {2, 1}, {2, 3}, {5, 1},{4, 5}, {6, 4}, {6, 3}};
    int E = sizeof(edge) / sizeof(edge[0]);
    
    int minEdgeToReverse = getMinEdgeReversal(edge, E, V, 0, 6);
    if (minEdgeToReverse != -1)
        cout << "Number of edges to be reversed are: "<<minEdgeToReverse << endl;
    else
        cout << "Not possible" << endl;
    return 0;
}
