// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// recursive approach
class Solution1{
    private:
    int recursion(const string &s1, const string &s2, int i, int j, int ans){
        if(i==0 or j==0) return ans;
        if(s1[i-1]==s2[j-1]) ans = recursion(s1,s2,i-1,j-1,1+ans);
        ans = max(ans,max(recursion(s1,s2,i-1,j,0),recursion(s1,s2,i,j-1,0)));
        return ans;
    }
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        return recursion(S1,S2,n,m,0);
    }
};

 // } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        int dp[n+1][m+1];
        int ans = INT_MIN;
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0 or j==0) dp[i][j] = 0;
                else if(S1[i-1]==S2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    ans = max(ans,dp[i][j]);
                }
                else dp[i][j] = 0;
            }
        }
        
        return (ans==INT_MIN)?0:ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m;
        string s1, s2;
        cin >> s1 >> s2;
        n = s1.length(), m = s2.length();
        Solution ob;
        Solution1 ob1;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
        cout << ob1.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends
