// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    long long int count( int S[], int m, int n )
    {
        //code here.
        vector<vector<long long int>> dp(n+1,vector<long long int>(m+1));
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(j==0) dp[i][j] = 0;
                else if(i==0) dp[i][j] = 1;
                else if(S[j-1]>i) dp[i][j] = dp[i][j-1];
                else dp[i][j] = dp[i-S[j-1]][j]+dp[i][j-1];
            }
        }
        
        // for(auto e:dp){
        //     for(auto v:e) cout<<v<<" ";
        //     cout<<endl;
        // }
        return dp[n][m];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++)
		    cin>>arr[i];
	    Solution ob;
		cout<<ob.count(arr,m,n)<<endl;
	}
    
    
    return 0;
}  // } Driver Code Ends
