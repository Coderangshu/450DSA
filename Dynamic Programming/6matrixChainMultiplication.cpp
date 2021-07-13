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
            int temp = recursion(arr,b,i)+recursion(arr,i+1,e)+
                        arr[b]*arr[i+1]*arr[e+1];
            ans = min(temp,ans);
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
                int temp = memoization(arr,b,i)+memoization(arr,i+1,e)+
                            arr[b]*arr[i+1]*arr[e+1];
                ans = min(temp,ans);
            }
            return memo[b][e] = ans;
        }
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        // int ans = recursion(arr,0,N-2);
        
        memset(memo,-1,sizeof(memo));
        int ans = memoization(arr,0,N-2);
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
