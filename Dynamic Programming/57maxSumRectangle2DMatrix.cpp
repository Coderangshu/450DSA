// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    // find max sum subarray of a row
    int kadaneAlgo(vector<int> a){
        int maxSoFar = a[0], currentMax = a[0];
        for(int i=1;i<a.size();i++){
            currentMax = max(a[i],currentMax+a[i]);
            maxSoFar = max(maxSoFar,currentMax);
        }
        return maxSoFar;
    }
    
    // find sum of 2 vectors(i.e. rows)
    vector<int> sum2vecs(vector<int> v1, vector<int> v2){
        vector<int> ans;
        for(int i=0;i<v2.size();i++)
            ans.push_back(v1[i]+v2[i]);
        return ans;
    }
    
    
    // Method: 2d is converted to 1d and analysed
    // kadane applied on first row and stored in maxSum
    // 2nd row added to 1st row and kadaned again max of
    // maxSum and this is stored in maxSum and so on

    // Time Complexity : O(R*R*C)
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
        int maxSum = INT_MIN;
        vector<int> cache;
        
        for(int i=0;i<R;i++){
            cache.assign(C,0);
            for(int j=i;j<R;j++){
                cache = sum2vecs(cache,M[j]);
                maxSum = max(kadaneAlgo(cache),maxSum);
            }
        }
        return maxSum;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}  // } Driver Code Ends
