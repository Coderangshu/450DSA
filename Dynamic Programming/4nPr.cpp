// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    // P(n, k) = P(n-1, k) + k* P(n-1, k-1)
    // P(n, 0) = 1

    int nPr(int n, int r){
        // code here
        long long int MOD = 1e9+7;
        vector<vector<long long int>> dp(n+1,vector<long long int>(r+1,0));

        for(int i=0;i<n+1;i++){
            for(int j=0;j<r+1;j++){
                if(j>i) continue;
                else if(j==0) dp[i][j] = 1;
                else dp[i][j] = ((j*dp[i-1][j-1])%MOD+dp[i-1][j]%MOD)%MOD;
            }
        }
        return dp[n][r];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;

        Solution ob;
        cout<<ob.nPr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends
