// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    // C(n, r) = C(n-1, r-1) + C(n-1, r)
    // C(n, 0) = C(n, n) = 1
    
    int nCr(int n, int r){
        // code here
        long long int MOD = 1000000007;
        vector<vector<long long int>> dp(n+1,vector<long long int>(r+1,0));
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<r+1;j++){
                if(j>i) continue;
                else if(i==j) dp[i][j] = 1;
                else if(j==0) dp[i][j] = 1;
                else dp[i][j] = (dp[i-1][j-1]%MOD+dp[i-1][j]%MOD)%MOD;
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
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends
