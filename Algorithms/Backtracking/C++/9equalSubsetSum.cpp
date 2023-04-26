// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    // recursive(backtracking)
    bool findPart(int arr[], int N, int index, int sum){
        if(index==N){
            if (sum==0) return true;
            else return false;
        }
        // else if(arr[index]==sum) return true;
        else if(arr[index]<=sum)
            return findPart(arr,N,index+1,sum) or findPart(arr,N,index+1,sum-arr[index]);
        else return findPart(arr,N,index+1,sum);
    }

    // top down
    bool findPart(int arr[], int n, int sum){
        int dp[n+1][sum+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(j==0) dp[i][j] = 1;
                else if(i==0) dp[i][j] = 0;
                else if(arr[i-1]>j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j-arr[i-1]] or dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
    
    
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i=0;i<N;i++) sum += arr[i];
        if(sum%2==1) return 0;
        else{
            return findPart(arr,N,sum/2);
        }
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
