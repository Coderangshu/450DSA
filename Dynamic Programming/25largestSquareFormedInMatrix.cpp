// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int Min(int a, int b, int c){return min(a,min(b,c));}

    int recursion(int i, int j, vector<vector<int>> mat, int &maxSize){
        // i, j: index of current cell
        
        // base condition
        // if i or j becomes negative means complete row or column of
        // mat has been explored thus no possible square now using these
        // index thus return 0
        if(i==0 or j==0) return 0;
        
        // for the rest:
        // if current cell has 0 this means there's no square possible
        // we set that cell to 0 and send recursive call for the 3 directions as
        // mentioned below
        // else we take the minimum of the 3 directions
        // (left, left-top diagonal, top) and add 1 to it to get the size possible
        // using this current cell containing 1
        // A max size is maintained to keep track of the maximum size found till now
        
        // the previous 3 directions are calculated first as these recursive calls are
        // needed to be made even if the current cell contains a 0 instead of 1
        int a = recursion(i-1,j,mat,maxSize);
        int b = recursion(i-1,j-1,mat,maxSize);
        int c = recursion(i,j-1,mat,maxSize);
        
        if(mat[i-1][j-1]==0) return 0;
        else{
            int temp = 1+Min(a,b,c);
            maxSize = max(maxSize,temp);
            return  temp;
        }
    }

    int memo[51][51];
    int memoization(int i, int j, vector<vector<int>> mat, int &maxSize){
        if(i==0 or j==0) return memo[i][j] = 0;
        
        if(memo[i][j]!=-1){
            maxSize = max(maxSize,memo[i][j]);
            return memo[i][j];
        }
        
        int a = memoization(i-1,j,mat,maxSize);
        int b = memoization(i-1,j-1,mat,maxSize);
        int c = memoization(i,j-1,mat,maxSize);
        
        if(mat[i-1][j-1]==0) return memo[i][j] = 0;
        
        else{
            int temp = 1+Min(a,b,c);
            maxSize = max(maxSize,temp);
            return  memo[i][j] = temp;
        }
    }

    int tabulation(vector<vector<int>> mat){
        int n = mat.size(), m = mat[0].size();
        int dp[n+1][m+1];
        int maxSize = 0;
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0 or j==0) dp[i][j] = 0;
                // here we do not require to calculate for the 3 directions
                // previously as this is a bottom up approach and the loop takes
                // through the complete matrix
                else if(mat[i-1][j-1]==0) dp[i][j] = 0;
                else{
                    dp[i][j] = 1+Min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
                    maxSize = max(maxSize,dp[i][j]);
                }
            }
        }
        return maxSize;
    }

    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        // max feasible size of square obtained till now
        int maxSize = 0;
        
        // recursion(n,m,mat,maxSize);
        
        // memset(memo,-1,sizeof(memo));
        // memoization(n,m,mat,maxSize);
        
        maxSize = tabulation(mat);
        
        return maxSize;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
