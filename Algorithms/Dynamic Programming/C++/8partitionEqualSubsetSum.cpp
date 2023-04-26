// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int equalPartitionUtil(int arr[], int n, int tsum){
        int dp[n+1][tsum+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<tsum+1;j++){
                if(j==0) dp[i][j] = 1;
                else if(i==0) dp[i][j] = 0;
                else if(arr[i-1]>j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j]+dp[i-1][j-arr[i-1]];
            }
        }
        return dp[n][tsum];
    }

    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i=0;i<N;i++) sum += arr[i];
        if(sum%2!=0) return 0;
        int tsum = sum/2;
        return equalPartitionUtil(arr,N,tsum);
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
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends
