// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

bool isSafe(int node, int color[], bool graph[101][101], int V, int col){
    // checks if the adjacent of the node isn't colored with the same color
    // with which the node is to be colored with
    for(int i=0;i<V;i++)
        if(i!=node and graph[node][i]==1 and color[i] == col) return false;
    return true;
}

bool mColorer(int u, int color[], int m, int V, bool adjMat[101][101]){
    // if u is the last node of graph then we have found an arrangement
    // wherein using atmost n colors we are able to color the complete
    // graph upto the last node and thus return true
    if(u==V) return true;
    
    // Try out all the m colors for each node until right combination
    // is found
    // i denotes each of the colors
    for(int i=1;i<=m;i++){
        if(isSafe(u,color,adjMat,V,i)){
            
            // if safe then color node with this color number
            color[u] = i;
            
            // go to the next node number and check if it satisfies the
            // current arrangement
            if(mColorer(u+1,color,m,V,adjMat)) return true;
        
            // if current arrangement not satisfying beacktrack
            // i.e. discolor the current node and try with the next color
            color[u] = 0;
        }
    }
    return false;
}


//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    int color[V] = {0};
    // We traverse the node in numerical order trying all colors in each node
    // if they are safe we move to check the next node number as so on until
    // desired arrangement is found, else return false
    if(mColorer(0,color,m,V,graph)) return true; 
    return false; 
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
