#include<bits/stdc++.h>
using namespace std;

// Requirements:
// name of array      |          typeof dataset 
//                    |_________________________________________________
//                    | if nodes are continuous | if nodes are distinct
// ___________________|_________________________|_______________________ 
// visited            |         array           |          map
// cost               |         array           |          map
// parent             |         array           |          map

// visited stores the nodes that have been visited, cost stores the cost
// of travelling from root to that node, parent stores the immediate parent
// of the node via which the shortest path (SPT) is formed

// Procedure:
// (I)   take the lowest weighted univisited node(here beginning with 0)
// (II)  mark node as visited 
// (III) update all adjacent nodes as follows:
//       If cost[u]+weight(uv) < cost(v) update cost(v) and parent[v] 

void addEdge(map<int,vector<pair<int,int>>> &adjList, int u, int v, int weight){
    adjList[u].push_back({v,weight});
    adjList[v].push_back({u,weight});
}

// The cost map is declared globally due to the comparator
// that uses it to compare the min heap in the priority queue
unordered_map<int,int> cost;

// struct to compare the cost of 2 nodes while forming min
// heap in priority queue
struct compare_cost{
    bool operator()(int u,int v){
        return cost[u]>cost[v];
    }
};

unordered_map<int,int> dijkstra(map<int,vector<pair<int,int>>> adjList, int start){
    // visited is marked true when physically we are sitting on that node, not as a
    // conventional BFS wherein we mark the neigbour nodes as marked as soon peaked
    unordered_map<int,bool> visited;
    // keeps track of immediate parent of node
    unordered_map<int,int> parent;
    
    // In beginning mark start visited, cost is 0 and parent is -1 (as it has no parent)
    visited[start] = true;
    cost[start] = 0;
    parent[start] = -1;
    
    // min heap to keep the lowest cost node at the top to process
    priority_queue<int,vector<int>,compare_cost> pq;
    pq.push(start);
    
    while(!pq.empty()){
        int currentNode = pq.top();
        pq.pop();
        // we are sitting on current node thus marking it as visited
        visited[currentNode] = true;
        
        // peaking into all its adjacent nodes
        for(auto nextNode:adjList[currentNode]){
            // Iff neigbour not visited previously
            if(!visited[nextNode.first]){
                // if peaked for the first time, its cost is inserted as
                // cost of current node + weight, and its parent is marked
                // as the current node, and pushed into the queue to be 
                // processed furthur
                if(cost.find(nextNode.first)==cost.end()){
                    cost[nextNode.first] = cost[currentNode]+nextNode.second;
                    parent[nextNode.first] = currentNode;
                    pq.push(nextNode.first);
                }
                // if peaked previously (already present in queue), and if
                // cost of current node + weight is less than this neigbour's
                // cost then update its cost to the lower one and its parent
                // as the current node
                else if(cost[currentNode]+nextNode.second<cost[nextNode.first]){
                    cost[nextNode.first] = cost[currentNode]+nextNode.second;
                    parent[nextNode.first] = currentNode;
                }
            }
        }
    }
    return parent;
}

// TC : O((V+E)logV) SC : O(V)

// A smaller code
class Solution{
    public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        minHeap.push({0,S});
        vector<int> ans(V,INT_MAX);
        vector<bool> visited(V,false);
        ans[S] = 0;
        visited[S] = true;
        while(!minHeap.empty()){
            auto [cost,node] = minHeap.top();
            minHeap.pop();
            visited[node] = true;
            for(auto &[neighbour,costNeighbour]:adj[node]){
                if(!visited[neighbour]){
                    ans[neighbour] = min(ans[neighbour],cost+costNeighbour);
                    minHeap.push({ans[neighbour],neighbour});
                }
            }
        }
        return ans;
    }
};

// Function to print the node and its parent and its distance
// from the source
void printVertices(unordered_map<int,int> parent){
    map<int,pair<int,int>> pc;
    for(auto e:parent){
        pc[e.first] = make_pair(e.second,cost[e.first]);
    }
    cout<<"Node"<<" Parent"<<" Cost from source"<<endl;
    for(auto e:pc) cout<<e.first<<"    "<<e.second.first<<"      "<<e.second.second<<endl;
}

int main(){
    map<int,vector<pair<int,int>>> adjList;
    
    // Graph 1:
    addEdge(adjList, 0, 1, 4);
    addEdge(adjList, 0, 7, 8);
    addEdge(adjList, 1, 2, 8);
    addEdge(adjList, 1, 7, 11);
    addEdge(adjList, 2, 3, 7);
    addEdge(adjList, 2, 8, 2);
    addEdge(adjList, 2, 5, 4);
    addEdge(adjList, 3, 4, 9);
    addEdge(adjList, 3, 5, 14);
    addEdge(adjList, 4, 5, 10);
    addEdge(adjList, 5, 6, 2);
    addEdge(adjList, 6, 7, 1);
    addEdge(adjList, 6, 8, 6);
    addEdge(adjList, 7, 8, 7);
    
    // Graph 2:
//     addEdge(adjList,0,1,1);
//     addEdge(adjList,0,2,4);
//     addEdge(adjList,1,2,4);
//     addEdge(adjList,1,3,2);
//     addEdge(adjList,1,4,7);
//     addEdge(adjList,2,4,5);
//     addEdge(adjList,2,3,3);
//     addEdge(adjList,3,4,4);
//     addEdge(adjList,3,5,6);
//     addEdge(adjList,4,5,7);
    
    cost.clear();
    unordered_map<int,int> parent = dijkstra(adjList,0);
    printVertices(parent);
}
