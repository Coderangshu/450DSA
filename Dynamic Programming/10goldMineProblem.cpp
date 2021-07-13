// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        for(int col=1;col<m;col++){
            for(int row=0;row<n;row++){
                // if there's only one row in matrix
                if(n==1) M[row][col] += M[row][col-1];
                // if 1st row
                else if(row==0) M[row][col] += max(M[row][col-1],M[row+1][col-1]);
                // if last row
                else if(row==n-1) M[row][col] += max(M[row-1][col-1],M[row][col-1]);
                // other rows
                else M[row][col] += max(M[row][col-1],max(M[row-1][col-1],M[row+1][col-1]));
            }
        }

        int ans = INT_MIN;
        for(int i=0;i<n;i++) ans = max(ans,M[i][m-1]);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
