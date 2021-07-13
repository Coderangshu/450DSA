// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    // To calculate max path in matrix
    int findMaxPath(vector<vector<int>> mat){
        int N = mat.size();
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < N; j++) {
                // When all paths are possible
                if (j > 0 && j < N - 1)
                    mat[i][j] += max(mat[i - 1][j],
                                 max(mat[i - 1][j - 1],
                                 mat[i - 1][j + 1]));
     
                // When diagonal right is not possible
                else if (j > 0)
                    mat[i][j] += max(mat[i - 1][j],
                                mat[i - 1][j - 1]);
     
                // When diagonal left is not possible
                else if (j < N - 1)
                    mat[i][j] += max(mat[i - 1][j],
                                mat[i - 1][j + 1]);
     
                // Store max path sum
            }
        }
        int res = 0;
        for (int j = 0; j < N; j++)
            res = max(mat[N-1][j], res);
        return res;
    }

    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        return findMaxPath(Matrix);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
