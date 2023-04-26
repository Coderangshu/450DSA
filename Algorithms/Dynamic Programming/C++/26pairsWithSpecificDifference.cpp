// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        // Your code goes here   
        sort(arr,arr+N);
        
        int dp[N];
        for(int i=0;i<N;i++){
            // base condition
            // if only 1 element then max sum is
            // 0
            if(i==0) dp[i] = 0;
            // if only 2 elements only choice is to take pair(iff diff<K)
            else if(i==1) dp[i] = (arr[i]-arr[i-1]<K)?(arr[i]+arr[i-1]):0;
            // else we check if diff is less than K, if found we have two 
            // options either to take this pair or reject take upto last
            // index or take upto second last and this pair
            else dp[i] = ((arr[i]-arr[i-1])<K)?max(dp[i-1],dp[i-2]+arr[i]+arr[i-1]):dp[i-1];
        }
        return dp[N-1];
    }
};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N, K;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++) cin>>arr[i];
		cin>>K;

        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}
  // } Driver Code Ends
