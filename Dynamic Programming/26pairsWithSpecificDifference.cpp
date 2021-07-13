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
            else{
                // for current index the max sum would be same as
                // the last index's until the difference between this
                // and the prev element is less than K
                // thus assigning the prev max sum to current
                dp[i] = dp[i-1];
                // now we check if diff is less than K
                if((arr[i]-arr[i-1])<K){
                    // now we have two options either to take
                    // this pair or reject
                    
                    // if i < 2 meaninig only 2 elements in array
                    if(i<2) dp[i] = max(dp[i-1],arr[i]+arr[i-1]);
                    else dp[i] = max(dp[i-1],dp[i-2]+arr[i]+arr[i-1]);
                }
            }
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
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}
  // } Driver Code Ends
