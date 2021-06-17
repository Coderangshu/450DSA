#include<bits/stdc++.h>
using namespace std;


// Algorithm (Kirchhoff's Theorem): find the adjacency and diagonal
// (the diagonal contains the degree of that node, i.e. (1,1) contains
// (the degree of node 1) matrix of the given graph and get
// laplacian matrix = adj - diag
// Calculate any element's cofactor in laplacian matrix that is the 
// number of possible MSTs of the given graph


void addEdge(vector<int> adj[],int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

vector<vector<int>> makeAdjMatrix(vector<int> adj[], int v){
    vector<vector<int>> graph(v,vector<int>(v,0));
    for(int i=0;i<v;i++){
        for(auto e:adj[i]){
            graph[i][e] = 1;
        }
    }
    return graph;
}

vector<vector<int>> makeDiagonalMatrix(vector<int> adj[], int v){
    vector<vector<int>> graph(v,vector<int>(v,0));
    for(int i=0;i<v;i++){
        graph[i][i] = adj[i].size();
    }
    return graph;
}

vector<vector<int>> makeLaplacianMatrix(vector<int> adj[], int v){
    vector<vector<int>> graph(v,vector<int>(v,0));
    vector<vector<int>> adjMat = makeAdjMatrix(adj,v);
    vector<vector<int>> diagMat = makeDiagonalMatrix(adj,v);
    
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++) graph[i][j] = diagMat[i][j]-adjMat[i][j];
    }
    return graph;
}

void getCofactorMatrix(vector<vector<int>> mat, vector<vector<int>> &cofMat, int p, int q, int n){
    int i=0,j=0;
    // Looping for each element of the matrix
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            // Copying into temporary matrix only those element which are
            // not in given row and column
            if(row!=p and col!=q){
                cofMat[i][j++] = mat[row][col];
                // Row is filled, so increase row index and reset col index
                if(j==n-1){
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int determinantCalculator(vector<vector<int>> mat, int n){
    // base condition
    // when only one element in matrix return that
    if(n==1) return mat[0][0];
    
    int ans = 0;
    
    // To store sign multiplier
    int sign = 1;
    
    vector<vector<int>> cofMat(n-1,vector<int>(n-1,0));
    
    // Iterate for each element of first row
    for(int i=0;i<n;i++){
        // getting cofactor matrix of mat[0][i]
        getCofactorMatrix(mat,cofMat,0,i,n);
        ans += sign * mat[0][i] * determinantCalculator(cofMat,n-1);
        
        // terms are to be added
        // with alternate sign
        sign = -sign;
    }
    return ans;
}

int main(){
    int V = 4;
    vector<int> adj[V];
    addEdge(adj,0,2);
    addEdge(adj,0,3);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,2,3);
    
    vector<vector<int>> laplacianMat = makeLaplacianMatrix(adj,V);
    
    vector<vector<int>> cofMat(V-1,vector<int>(V-1,0));
    getCofactorMatrix(laplacianMat,cofMat,0,0,V);
    
    int cofactor = determinantCalculator(cofMat,V-1);
    cout<<cofactor<<endl;
    
    return 0;
}
