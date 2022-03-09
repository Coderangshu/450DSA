#include<bits/stdc++.h>
using namespace std;



// Algorithm: (I)   Arrange the edges ascendingly according to their weights
//            (II)  Take the edge with minimum weight, check both the source
//                  and destination node's parents if any of them have been 
//                  already included then do not add this edge to MST
//            (III) If none of the parents are present in the MST previously
//                  add the edge to MST and unify the source and destination's
//                  parents under one of them accordingly in union funtion



// a structure to represent a
// weighted edge in graph
struct Edge{
    int src,dest,weight;
};

// structure to compare inside priority_queue
// to generate a min heap of the edges w.r.t
// the weights
struct compareWeight{
    bool operator()(Edge e1, Edge e2){
        return e1.weight>e2.weight;
    }
};

// A structure to represent the status for union-find
struct nodeStatus{
    // Parent denotes the parent of node
    // rank denotes the number of levels present
    // in the component of which the node is a part of
	int parent, rank;
};

// A utility function to find parent of an element
// (uses path compression technique)
int findParent(unordered_map<int,nodeStatus> &status, int node){
    // find root and make root as parent of node
    // (path compression)
    if (status[node].parent != node)
        status[node].parent = findParent(status, status[node].parent);
    return status[node].parent;
}

// A function that does union of two sets of x and y
// (uses union by rank)
void Union(unordered_map<int,nodeStatus> &status, int x, int y){
    // Find parent of both nodes 
    int xParent = findParent(status,x);
    int yParent = findParent(status,y);
    
    // Attach smaller rank tree under root of high rank tree (Union by Rank)
    // this is done to keep the level numbers low, as on adding a low leveled
    // sub graph to a high level numbered sub graph then the level of high one
    // remains same but includes the whole low leveled sub graph in itself
    if(status[xParent].rank<status[yParent].rank) status[xParent].parent = yParent;
    else if(status[xParent].rank>status[yParent].rank) status[yParent].parent = xParent;
    // If rank of both are same make any of them parent and increament
    // rank of parent
    // When both rank are same means that both have same number of levels under them
    // thus we make any of the two node as parent thus incrementing the parent's rank
    else{
        status[yParent].parent = xParent;
        status[xParent].rank++;
    }
}

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
    
    // Constructor
    Graph(int v, int e){
        this->V = v;
        this->E = e;
        this->edgeArr = new Edge[e];
    }
    
    // Destructor
    ~Graph(){
        delete[] this->edgeArr;
    };
    
    vector<Edge> KruskalMST(){
        vector<Edge> ans;

        
        // Step 1: Sort all the edges in non-decreasing
        // order of their weight.
        
        // Pushing edges into minHeap to get the lowest
        // edge cost at top
        priority_queue<Edge,vector<Edge>,compareWeight> pq;
        for(int i=0;i<this->E;i++) pq.push(this->edgeArr[i]);
        
        // Initializing union-find
        
        // Map to keep track of parent and rank of each
        // node, initializing each node as a standalone
        // with parent as itself and rank as 0
        unordered_map<int,nodeStatus> status;
        for(int i=0;i<this->V;i++){
            status[i].parent = i;
            status[i].rank = 0;
        }
        
        // Until we get V-1 edges and while minHeap not empty
        int e = 0;
        while(e<V-1 and !pq.empty()){
            
            // Step 2: Pick the edge with smallest weight.
            Edge nextEdge = pq.top();
            pq.pop();
            
            int psrc = findParent(status,nextEdge.src);
            int pdest = findParent(status,nextEdge.dest);
            
            // If parent of both are same this means they have already
            // been united and are part of the MST
            
            // If parent of src & dest aren't same then unite
            // them under same parent and add node to ans
            if(psrc!=pdest){
                ans.push_back(nextEdge);
                Union(status,psrc,pdest);
            }
        }
        return ans;
    }
    
};

void printMST(vector<Edge> ans){
    cout << "Following are the edges in the constructed MST"<<endl;
    int minimumCost = 0;
    for (int i=0;i<ans.size();i++){
        cout<<ans[i].src<<" -- "<<ans[i].dest<<" == "<<ans[i].weight<<endl;
        minimumCost += ans[i].weight;
    }
    cout<<"Minimum Cost Spanning Tree: "<<minimumCost<<endl;
}

// Driver code
int main()
{
	// Let us create following weighted graph
    // 		  10
    // 		0-----1
    // 		| \   |
    //     6| 5\  |15
    // 		|   \ |
    // 		2-----3
    // 		  4
	int V = 4; // Number of vertices in graph
	int E = 5; // Number of edges in graph
	Graph graph(V, E);

	// add edge 0-1
	graph.edgeArr[0].src = 0;
	graph.edgeArr[0].dest = 1;
	graph.edgeArr[0].weight = 10;

	// add edge 0-2
	graph.edgeArr[1].src = 0;
	graph.edgeArr[1].dest = 2;
	graph.edgeArr[1].weight = 6;

	// add edge 0-3
	graph.edgeArr[2].src = 0;
	graph.edgeArr[2].dest = 3;
	graph.edgeArr[2].weight = 5;

	// add edge 1-3
	graph.edgeArr[3].src = 1;
	graph.edgeArr[3].dest = 3;
	graph.edgeArr[3].weight = 15;

	// add edge 2-3
	graph.edgeArr[4].src = 2;
	graph.edgeArr[4].dest = 3;
	graph.edgeArr[4].weight = 4;

//     for(int i=0;i<E;i++) cout<<graph.edgeArr[i].src<<endl;
	// Function call
	vector<Edge> ans = graph.KruskalMST();
    printMST(ans);

	return 0;
}
