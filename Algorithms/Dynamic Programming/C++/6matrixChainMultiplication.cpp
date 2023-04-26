// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int recursion(int arr[], int b, int e){
        if(b>=e) return 0;
        int ans = INT_MAX;
        for(int i=b;i<e;i++){
            ans = min(ans,recursion(arr,b,i)+recursion(arr,i+1,e)+arr[b-1]*arr[i]*arr[e]);
        }
        return ans;
    }

    int memo[101][101];
    int memoization(int arr[], int b, int e){
        if(b>=e) return memo[b][e] = 0;
        else if(memo[b][e]!=-1) return memo[b][e];
        else{
            int ans = INT_MAX;
            for(int i=b;i<e;i++){
                ans = min(ans,memoization(arr,b,i)+memoization(arr,i+1,e)+arr[b-1]*arr[i]*arr[e]);
            }
            return memo[b][e] = ans;
        }
    }
    
    int tabulation(int n, int arr[]){
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        for(int i=n-1;i>0;i--){
            for(int j=0;j<n;j++){
                if(i>=j) dp[i][j] = 0;
                else{
                    for(int k=i;k<j;k++){
                        dp[i][j] = min(dp[i][j],arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j]);
                    }
                }
            }
        }
        return dp[1][n-1];
    }

    int matrixMultiplication(int N, int arr[])
    {
        // code here
        // int ans = recursion(arr,1,N-1);
        
        // memset(memo,-1,sizeof(memo));
        // int ans = memoization(arr,1,N-1);

        int ans = tabulation(N,arr);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends
