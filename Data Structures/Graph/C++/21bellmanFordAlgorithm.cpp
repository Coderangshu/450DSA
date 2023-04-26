#include<bits/stdc++.h>
using namespace std;



// Bellman Ford algorithm is similar to dijkstra's algorithm
// both gives the single shortest path from source to destination
// iff no negative edge weight is present in the graph
// Dijkstra's algorithm takes O(V log V)
// Bellman Ford algorithm takes O(VE)
// thus dijkstra is faster
// but Bellman Ford has an advantage that it can detect a
// negative edge cycle in a graph if present which dijkstra
// can't, thus we can use Bellman Ford to detect negative
// cycle in graph



// Bellman Ford algorithm: Initialize all distance from src as inf
// except for the source which has 0 distance from itself.
// traverse through every node V-1 times and set their distance
// as low as possible according to their previous node's cost and
// the edge weight
// Note: a time optimization can be applied here wherein if while
// traversing for V-1 times in any two consecutive loops we get
// the same cost for each node we can conclude the loop as we have
// found the shortest path from each of the node

// Now if theres a negative cycle in the graph the cost keeps decreasing
// every time the loop is run, that makes it easier for its detection
// as when even after V-1 loops we start finding the cost of each node
// again in a new loop we see that the cost keeps decreasing indicating
// a negative cycle, as we know that after V-1 loops the shortest path
// for each of the nodes would have been found in normal situation



// a structure to represent a
// weighted edge in graph
struct Edge{
    int src,dest,weight;
};

// a class to represent a connected,
// undirected and weighted graph
class Graph {
public:
	
	// V-> Number of vertices, E-> Number of edges
	int V, E;

	// graph is represented as an array of edges.
	// Since the graph is undirected, the edge
	// from src to dest is also edge from dest
	// to src. Both are counted as 1 edge here.
	Edge* edgeArr;
    
    Graph(int v, int e){
        this->V = v;
        this->E = e;
        this->edgeArr = new Edge[e];
    }
    
    
    // Bellman-Ford algorithm is consistent in giving result for connected graph
    // may or may not give accurate results for disconnected graph
    bool isNegativeCycleBellmanFord(int src){
    
        // Step 1: Initialize distances from src to all other vertices as INFINITE
        vector<int> distFromSource(this->V,INT_MAX);
        // Setting distFromSource for src as 0
        distFromSource[src] = 0;
        
        
        // Step 2: Peak into all edges |V| - 1 times.
        // A single shortest path from src to any other vertex can have at-most
        // |V| - 1 edges thus traversing through each node |V|-1 times
        for(int i=0;i<this->V-1;i++){
            for(int j=0;j<this->E;j++){
                int u = this->edgeArr[j].src;
                int v = this->edgeArr[j].dest;
                int weight = this->edgeArr[j].weight;
                // If u node has already been peaked atleast once and the cost
                // at node v is > cost at node u + weight of edge
                if (distFromSource[u]!=INT_MAX and distFromSource[u]+weight<distFromSource[v])
                    distFromSource[v] = distFromSource[u] + weight;
            }
        }
        
        // For a graph with no negative edge the above 2 steps will give us the
        // shortest distance of each node from the source.
        // The next step is done to run a check on the nodes for another time
        // while doing so if the cost decreases for any node we break the check
        // and say that there's a negative cycle in the graph
        
        
        // Step 3: check for negative-weight cycles.
        // The above step guarantees shortest distances if graph doesn't contain
        // negative weight cycle.
        // If we get a shorter path in the next iteration, then there is a negative cycle.
        for (int i=0;i<this->E;i++) {
            int u = this->edgeArr[i].src;
            int v = this->edgeArr[i].dest;
            int weight = this->edgeArr[i].weight;
            // If u's const isn't INT_MAX(which won't happen in connected graph) and
            // if u's cost+weight of edge<v's cost
            // This implies that u->v edge is a part of a negative cycle
            if (distFromSource[u]!=INT_MAX and distFromSource[u]+weight<distFromSource[v])
                return true;
        }
        return false;
    }
    
    bool isNegativeCycleBellmanFord(int src, vector<int> &distFromSource){
    
        // Step 1: Initialize distances from src to all other vertices as INFINITE
        for(int i=0;i<this->V;i++){
            distFromSource[i] = INT_MAX;
        }
        // Setting distFromSource for src as 0
        distFromSource[src] = 0;
        
        
        // Step 2: Peak into all edges |V| - 1 times.
        // A simple shortest path from src to any other vertex can have at-most
        // |V| - 1 edges thus traversing through each node |V|-1 times
        for(int i=0;i<this->V-1;i++){
            for(int j=0;j<this->E;j++){
                int u = this->edgeArr[j].src;
                int v = this->edgeArr[j].dest;
                int weight = this->edgeArr[j].weight;
                // If u node has already bee peaked atleast once and the cost
                // at node v is > cost at node u + weight of edge
                if (distFromSource[u]!=INT_MAX and distFromSource[u]+weight<distFromSource[v])
                    distFromSource[v] = distFromSource[u] + weight;
            }
        }
        
        // Step 3: check for negative-weight cycles.
        // The above step guarantees shortest distances if graph doesn't contain
        // negative weight cycle.
        // If we get a shorter path, then there is a cycle.
        for (int i=0;i<this->E;i++) {
            int u = this->edgeArr[i].src;
            int v = this->edgeArr[i].dest;
            int weight = this->edgeArr[i].weight;
            // If u's const isn't INT_MAX(which won't happen in connected graph) and
            // if u's cost+weight of edge<v's cost
            // This implies that u->v edge is a part of a negative cycle
            if (distFromSource[u]!=INT_MAX and distFromSource[u]+weight<distFromSource[v])
                return true;
        }
        return false;
    }
    
    // Wrapper funtion to find negative cycle in disconnected graph
    bool isNegativeCycleDisconnected(){
        
        // To keep track of visited vertices to avoid recomputations.
        vector<bool> visited(this->V,false);
        
         // This array is filled by Bellman-Ford
        vector<int> distFromSource(this->V);
        
        // Call Bellman-Ford for all those vertices that are not visited
        // this will mark all those nodes in distFromSource less than INT_MAX
        // as visited, thus completing one segment of the disconnected graph
        // the next nodes which aren't visited yet are sent to the Bellman-Ford
        // algorithm to get marked
        for(int i=0;i<this->V;i++) {
            if(!visited[i]){
                // If cycle found
                if(isNegativeCycleBellmanFord(i,distFromSource)) return true;
    
                // Mark all vertices that are visited in above call.
                for(int i=0;i<this->V;i++)
                    if (distFromSource[i]!=INT_MAX)
                        visited[i] = true;
            }
        }
        return false;
    }
    
};

int main(){
    
    // Graph 1:
    // Let us create the following graph
    //              
    //               0
    //             /   \ 
    //          4 |     \ -1
    //            |      \ 
    //            <|   3  <|  2
    //              2<------1------>4
    //            <|        /|>     |
    //            |        /  \     |-3
    //            |      2/   /     |
    //          5 |      /   /      /
    //            |     /  1/      /
    //             \  |>   /      /
    //               3<-----------

    
    
    int V = 5; // Number of vertices in graph
    int E = 8; // Number of edges in graph
    Graph graph(V,E);
 
    // add edge 0-1 (or A-B in above figure)
    graph.edgeArr[0].src = 0;
    graph.edgeArr[0].dest = 1;
    graph.edgeArr[0].weight = -1;
 
    // add edge 0-2 (or A-C in above figure)
    graph.edgeArr[1].src = 0;
    graph.edgeArr[1].dest = 2;
    graph.edgeArr[1].weight = 4;
 
    // add edge 1-2 (or B-C in above figure)
    graph.edgeArr[2].src = 1;
    graph.edgeArr[2].dest = 2;
    graph.edgeArr[2].weight = 3;
 
    // add edge 1-3 (or B-D in above figure)
    graph.edgeArr[3].src = 1;
    graph.edgeArr[3].dest = 3;
    graph.edgeArr[3].weight = 2;
 
    // add edge 1-4 (or A-E in above figure)
    graph.edgeArr[4].src = 1;
    graph.edgeArr[4].dest = 4;
    graph.edgeArr[4].weight = 2;
 
    // add edge 3-2 (or D-C in above figure)
    graph.edgeArr[5].src = 3;
    graph.edgeArr[5].dest = 2;
    graph.edgeArr[5].weight = 5;
 
    // add edge 3-1 (or D-B in above figure)
    graph.edgeArr[6].src = 3;
    graph.edgeArr[6].dest = 1;
    graph.edgeArr[6].weight = 1;
 
    // add edge 4-3 (or E-D in above figure)
    graph.edgeArr[7].src = 4;
    graph.edgeArr[7].dest = 3;
    graph.edgeArr[7].weight = -3;
    
    if(graph.isNegativeCycleBellmanFord(0)) cout<<"Negative Cycle is Present"<<endl;
    else cout<<"No Negative Cycle is Present"<<endl;
    
    if(graph.isNegativeCycleDisconnected()) cout<<"Negative Cycle is Present"<<endl;
    else cout<<"No Negative Cycle is Present"<<endl;
    
    // Graph 2:
    
    // Let us create the following graph
    // 
    //                1
    //          0---------->1
    //        <|             |
    //        |              | -1
    //     -1 |              |
    //        |             |>
    //         3<----------2
    //              -1
    // 
    // 
    V = 4, E = 4;
    Graph graph1(V,E);
    
    graph1.edgeArr[0].src = 0;
    graph1.edgeArr[0].dest = 1;
    graph1.edgeArr[0].weight = 1;
    
    graph1.edgeArr[1].src = 1;
    graph1.edgeArr[1].dest = 2;
    graph1.edgeArr[1].weight = -1;
    
    graph1.edgeArr[2].src = 2;
    graph1.edgeArr[2].dest = 3;
    graph1.edgeArr[2].weight = -1;
    
    graph1.edgeArr[3].src = 3;
    graph1.edgeArr[3].dest = 0;
    graph1.edgeArr[3].weight = -1;
    
    
    if(graph1.isNegativeCycleBellmanFord(0)) cout<<"Negative Cycle is Present"<<endl;
    else cout<<"No Negative Cycle is Present"<<endl;
    
    if(graph1.isNegativeCycleDisconnected()) cout<<"Negative Cycle is Present"<<endl;
    else cout<<"No Negative Cycle is Present"<<endl;
}
