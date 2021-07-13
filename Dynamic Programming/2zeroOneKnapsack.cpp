// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(W+1,vector<int>(n+1));
       for(int i=0;i<W+1;i++){
           for(int j=0;j<n+1;j++){
               if(i==0 or j==0) dp[i][j] = 0;
               else if(wt[j-1]>i) dp[i][j] = dp[i][j-1];
               else dp[i][j] = max(dp[i-wt[j-1]][j-1]+val[j-1],dp[i][j-1]);
           }
       }
    //   for(auto e:dp){
    //       for(auto f:e) cout<<f<<" ";
    //       cout<<endl;
    //   }
       return dp[W][n];
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
