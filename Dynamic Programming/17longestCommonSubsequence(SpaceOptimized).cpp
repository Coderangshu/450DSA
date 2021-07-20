// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        // Binary index, used to index current row and previous row.
        bool bi;
        int dp[2][y+1] = {0};
        for(int i=0;i<x+1;i++){
            // this will alternate between true and false
            // i.e. 0 and 1
            bi = i&1;
            for(int j=0;j<y+1;j++){
                if(i==0 or j==0) dp[bi][j] = 0;
                else if(s1[i-1]==s2[j-1]) dp[bi][j] = 1+dp[1-bi][j-1];
                else dp[bi][j] = max(dp[1-bi][j],dp[bi][j-1]);
            }
        }

        return dp[bi][y];
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends
