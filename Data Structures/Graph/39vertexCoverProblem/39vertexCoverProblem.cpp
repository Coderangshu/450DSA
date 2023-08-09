// If interested see method of finding vertex cover number using DP(for tree)

// This has NP complete solution, i.e. no 
// polynomial time solution until P=NP
// There's a approximate algorithm to solve this
// https://youtu.be/WS7EQpYTAwI
// -> to understand the approxitmate algorithm
// the result provided by the approximate algorithm
// gives answer <= 2 times the no. of nodes actually
// required to be vertex cover of the graph

// we take any one edge arbitarily add both nodes to answer
// and remove all the neighbouring edges for those 2 node
// continue same step until all edges are 

// The above is a approximate algorithm

// Below implemented is exact algorithm using BINARY SEARCH & GOSPER'S HACK
// Below is implementation with 1 indexed nodes graph provided

#include<bits/stdc++.h>
using namespace std;

// bit enumerator
// Generate previous combination with same number bits high
// as number of high bits in the input combination
int gospersHack(int setbits) {
    int c = setbits & -setbits;
    int r = setbits + c;
    setbits = (((r^setbits)>>2)/c) | r;
    return setbits;
}

bool checkCover(int n, int k, int m, vector<vector<int>> &adjMat) {
    // Set has first 'k' bits high initially
    int setBits = (1<<k)-1, limit = (1<<n);

    // Try out all node subset of size 'k'
    while(setBits<limit) {
        vector<vector<bool>> visited(n+1,vector<bool>(false,n+1));
        int noOfEdgesCovered = 0;
        // nodeBit is binary representation of each node, if nodeBit node is part of
        // setBits subset of nodes, mark all edges emering out of nodeBit as visited
        int nodeBit = 1;
        while(nodeBit<limit) {
            if(setBits&nodeBit) {
                int node = log2(nodeBit&~(nodeBit-1));
                // Mark all edges emerging out of this node visited
                for(int i=0;i<n;i++) {
                    if (adjMat[node][i] and !visited[node][i]) {
                        visited[node][i] = true;
                        visited[i][node] = true;
                        noOfEdgesCovered++;
                    }
                }
            }
            nodeBit <<= 1;
        }
        // If the current subset covers all the edges
        if (noOfEdgesCovered==m) return true;
        setBits = gospersHack(setBits);
    }
    return false;
}

int binarySearch(vector<vector<int>> &adjMat, int n, int m) {
    int lo = 1, hi = n;
    while(lo<hi) {
        int mid = (lo+hi)>>1;
        if (checkCover(n,mid,m,adjMat))
            hi = mid;
        else
            lo = mid+1;
    }
    return lo;
}

int getMinVertexCover(vector<vector<int>> &edges, int n) {
    vector<vector<int>> adjMat(n,vector<int>(n));
    
    // Populate adjMatrix
    for(int i=0;i<edges.size();i++) {
        int a = edges[i][0], b = edges[i][1];
        adjMat[a][b] = 1;
        adjMat[b][a] = 1;
    }

    // the # of vertex cover nodes will be
    // in range 1 to n,thus we binary search 
    return binarySearch(adjMat,n,edges.size());
}

int main(){
    int V = 7;
    vector<vector<int>> edges;
    edges.push_back({0,1});
    edges.push_back({0,2});
    edges.push_back({1,3});
    edges.push_back({3,4});
    edges.push_back({4,5});
    edges.push_back({5,6});
    
    cout<<getMinVertexCover(edges,V)<<endl;
    return 0;
}
