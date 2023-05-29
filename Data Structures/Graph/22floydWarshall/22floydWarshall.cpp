// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int V = matrix.size();
	    // Converting the cost of edges which aren't present
	    // from -1(given in input adjacency matrix) to INT_MAX
	    for(int i=0;i<V;i++){
	        for(int j=0;j<V;j++){
	            if(matrix[i][j]==-1) matrix[i][j] = INT_MAX;
	        }
	    }
	    
	    // We consider each node as source and destination and
	    // also consider each as an intermediate node for a path
	    
	    
        // Below i = intermediate node, j = source, k = destination
	    for(int i=0;i<V;i++){
	        for(int j=0;j<V;j++){
	            for(int k=0;k<V;k++){
	                // If intermediate node is present then we update
	                // cost src->dest as 
	                // minimum cost (src->intermediate + intermediate->dest and src->dest)
	                if(matrix[j][i]!=INT_MAX and matrix[i][k]!=INT_MAX)
	                   matrix[j][k] = min(matrix[j][i]+matrix[i][k],matrix[j][k]);
	            }
	        }
	    }
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends
