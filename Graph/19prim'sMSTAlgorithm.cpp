#include<bits/stdc++.h>
using namespace std;



// Algorithm: Herein we store the parent of each node in the
// MST in a vector of pairs named parent containing the pair 
// of (parent,weight). Also two vectors are maintained to keep
// track of the nodes added to MST and the weight of edge that
// connects that node to the MST(we need to make this minimum)

// Start from source node(here 0) and set its parent as -1 & weight
// as 0, we maintain a priority queue to make a minHeap of the nodes
// w.r.t. their weight of edge connecting them to the MST .
// We push the source node into the queue and start a loop, to get
// atmost of (tot. no. of nodes - 1) edges as this is a criteria
// for a MST and also untill the minHeap isn't empty.

// For each of top of minHeap we mark it as alreadyAddedToMST
// and traverse their neighbours and if neighbour isn't added to
// MST and its weight's more than the current weight than we make
// current node as parent of this neighbour and update its weight
// of edge connecting to the MST as the new lower weight and also
// add the node to the minHeap to be furthur processed and discover
// the minimum path to other nodes


vector<pair<int,int>> primMST(vector<pair<int,int>> adj[], int V){
    // Array to store constructed MST 
    // initializing with -1 as all node's parents
    // and the weight as 0
    vector<pair<int,int>> parent(V,{-1,0});
    
    vector<bool> alreadyAddedToMST(V,false);
    
    vector<int> minCostOfEachNode(V,INT_MAX);
    
    // Marking node 0's minCostOfEachNode as 0
    minCostOfEachNode[0] = 0;
    
    // initializing minHeap of pair of (cost,node)
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
    minHeap.push({0,0});
    
    // Atmost we need to add V-1 edges to get a MST 
    for(int i=0;i<V-1,!minHeap.empty();i++){
        // Top of minHeap added to MST 
        int u = minHeap.top().second;
        minHeap.pop();
        alreadyAddedToMST[u] = true;
        
        // Traversing through neighbours of u
        for(auto vPair:adj[u]){
            int v = vPair.first;
            int weight = vPair.second;
            // If neighbor not visited and its weight is more than the now
            // weight than replace weight with this weight and change parent
            // to the current node, and push to minHeap for furthur processing
            if(!alreadyAddedToMST[v] and weight<minCostOfEachNode[v]){
                parent[v] = {u,weight};
                minCostOfEachNode[v] = weight;
                minHeap.push({weight,v});
            }
        }
    }
    return parent;
}

void printMST(vector<pair<int,int>> parent){
    cout << "Following are the edges in the constructed MST"<<endl;
    int minimumCost = 0;
    // Starting from 1 as node 0 is its own parent and not required to
    // print the -1
    for (int i=1;i<parent.size();i++){
        cout<<i<<" -- "<<parent[i].first<<" == "<<parent[i].second<<endl;
        minimumCost += parent[i].second;
    }
    cout<<"Minimum Cost Spanning Tree: "<<minimumCost<<endl;
}

int main(){
    // Let us create the following graph 
    //        2   3 
    //     0----1----2 
    //     |   / \   | 
    //    6| 8/   \5 |7 
    //     | /     \ | 
    //     3---------4 
    //          9
    
    int V = 5;
    
    int graph[V][V] = { { 0, 2, 0, 6, 0 }, 
                        { 2, 0, 3, 8, 5 }, 
                        { 0, 3, 0, 0, 7 }, 
                        { 6, 8, 0, 0, 9 }, 
                        { 0, 5, 7, 9, 0 } }; 
                        
    
    // Converting adjacent matrix to adjacent list
    vector<pair<int,int>> adj[V];
    for(int i=0;i<V;i++)
        for(int j=i+1;j<V;j++)
            if(graph[i][j]!=0){
                // Adj has pair (node,weight)
                adj[i].push_back({j,graph[i][j]});
                adj[j].push_back({i,graph[i][j]});
            }
    
    
    vector<pair<int,int>> parent = primMST(adj,V);
    printMST(parent);
}
