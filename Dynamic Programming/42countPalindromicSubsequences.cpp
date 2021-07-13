 // { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    
    long long int mod = 1000000007;
    
    int memo[1001][1001];
    long long int memoization(string s, int start, int end){
        // base condition
        if(start>end) return memo[start][end] = 0;
        // when length is 1 its a palindrome
        if(start==end) return memo[start][end] = 1;
        
        if(memo[start][end]!=-1) return memo[start][end];
        
        // if start and end are same then we consider it as a
        // palindrome and recurse for (start+1,end) and (start,end+1)
        // and add all 3, we do not remove the overlapping parts as
        // in question it has been told that the palindromes may not
        // be distinct thus repetation is allowed
        if(s[start]==s[end]) 
            return memo[start][end] = 1+memoization(s,start+1,end)+
                                        memoization(s,start,end-1);
        
        // if not same then we recurse for (start+1,end) and (start,end+1)
        // and remove the overlapping substring
        return memo[start][end] = memoization(s,start+1,end)+
                                memoization(s,start,end-1)-
                                memoization(s,start+1,end-1);
    }
    
    long long int tabulation(string s){
        int n = s.length();
        long long int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=0;j<=n-i;j++){
                int k = j+i-1;
                if(i==1) dp[j][k] = 1;
                else{
                    if(s[j]==s[k]) dp[j][k] = (1+(dp[j+1][k]+dp[j][k-1])%mod)%mod;
                    else dp[j][k] = ((dp[j+1][k]+dp[j][k-1])%mod-dp[j+1][k-1])%mod;
                }
            }
        }
        
        // Uncomment to print the dp table
        // cout<<"   ";
        // for(int i=0;i<n;i++) cout<<s[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<s[i]<<" ";
        //     for(int j=0;j<n;j++) cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        return dp[0][n-1]%mod;
    }
    
    long long int  countPS(string str)
    {
       //Your code here
       memset(memo,-1,sizeof(memo));
    //   return memoization(str,0,str.length()-1);
    return tabulation(str);
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends
