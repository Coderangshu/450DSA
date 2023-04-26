// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
   int memo[10002][102];            // The array size causes problem

     int recursion(int N, int arr[], int sum){
         if(sum==0) return 1;
         if(N==0) return 0;
         if(arr[N-1]>sum) return recursion(N-1,arr,sum);
         else return (recursion(N-1,arr,sum-arr[N-1]) || recursion(N-1,arr,sum));
     }

     int memoization(int N, int arr[], int sum){
         if(sum==0) return memo[sum][N] = 1;
         if(N==0) return memo[sum][N] = 0;
         if(memo[sum][N]!= -1) return memo[sum][N];
         if(arr[N-1]>sum) return memo[sum][N] = memoization(N-1,arr,sum);
         else return memo[sum][N] = (memoization(N-1,arr,sum-arr[N-1]) || memoization(N-1,arr,sum));
     }

    int topDown(int N, int arr[], int sum){
        int dp[sum+1][N+1];
        for(int i=0;i<sum+1;i++){
            for(int j=0;j<N+1;j++){
                if(i==0) dp[i][j] = 1;
                else if(j==0) dp[i][j] = 0;
                else if(arr[j-1]>i) dp[i][j] = dp[i][j-1];
                else dp[i][j] = dp[i-arr[j-1]][j-1] + dp[i][j-1];
            }
        }
        return dp[sum][N];
    }
    
     int equalPartition(int N, int arr[])
{
          // code here
          int sum = accumulate(arr,arr+N,0);
          if(sum%2==1) return 0;
          // Recursion
//           else return recursion(N,arr,sum/2);
          // Memoization 
          //else{
          //    memset(memo,-1,sizeof(memo));
          //    return memoization(N,arr,sum/2);
         // }
          // bottomUp
           else return topDown(N,arr,sum/2);
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
