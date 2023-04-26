// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  // Time complexity : O(K*N*N) 
    int maxProfit1(int K, int N, int A[]) {
        // code here
        int dp[K+1][N];
        
        for(int i=0;i<K+1;i++){
            // for calculation of the max profit
            // here we take in consideration from
            // day 1 as on day 0 we cannot sell share
            // only buy thus giving us -ve profit
            // max of -ve and 0 is 0 thus we consider
            // day 0 max profit as 0
            for(int j=0;j<N;j++){
                // if number of transactions allowed
                // are 0 then profit is 0 for j==0 see the
                // above explanation
                if(i==0 or j==0) dp[i][j] = 0;
                else{
                    // we find the max profit done by completing
                    // a transaction before kth day + buying the
                    // share again on the kth day and selling on the
                    // current day
                    int m = INT_MIN;
                    for(int k=0;k<j;k++)
                        m = max(dp[i-1][k]+(A[j]-A[k]),m);
                    // now we have two choices either we take the
                    // max profit done with last transaction and
                    // selling today that was brought on the day
                    // of completion of the last transaction
                    // or skip selling today and keeping the profit
                    // earned the previous day, we take the max
                    dp[i][j] = max(m,dp[i][j-1]);
                }
            }
        }
        return dp[K][N-1];
    }
    
    
    // Improvised approach
    // Time complexity : O(K*N)
    // Here the max profit upto last day is being calculated
    // only once for each day and cached in maxPrevDiff instead
    // of calculating it from the begining every day
    int maxProfit(int K, int N, int A[]) {
        // code here
        int dp[K+1][N];
        
        for(int i=0;i<K+1;i++){
            // this will hold the max profit that
            // was possible after last the transaction
            // before the previous day and again buying
            // it the last day
            int maxPrevDiff = INT_MIN;
            for(int j=0;j<N;j++){
                if(i==0 or j==0) dp[i][j] = 0;
                else{
                    maxPrevDiff = max(dp[i-1][j-1]-A[j-1],maxPrevDiff);
                    // now we check if with the last max profit made +
                    // selling it today is more beneficial or not selling
                    // today is more beneficial
                    dp[i][j] = max(maxPrevDiff+A[j],dp[i][j-1]);
                }
            }
        }
        return dp[K][N-1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends
