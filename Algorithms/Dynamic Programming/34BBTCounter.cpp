// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    
    long long int mod = 1000000007;
    
    long long int recursion(int h){
        // h = 1 + max(left subtree, right subtree)
        
        
        // for tree of length 1 or less possible tree is
        // only 1
        if(h<=1) return 1;
        // for BBT possible left and right subtrees are:
        // (h-1), (h-2)
        // (h-2), (h-1)
        // (h-1), (h-1)
        return (recursion(h-1)*(2*recursion(h-2))%mod+recursion(h-1)%mod)%mod;
    }
  
    long long int tabulation(int h){
        int dp[h+1];
        for(int i=0;i<h+1;i++){
            if(i==0 or i==1) dp[i] = 1;
            else
                dp[i] = (dp[i-1]*(2*dp[i-2]%mod+dp[i-1]%mod))%mod;
        }
        return dp[h];
    }
    long long int countBT(int h) { 
        // code here
        
        // return recursion(h);
        return tabulation(h);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}
  // } Driver Code Ends
