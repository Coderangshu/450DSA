// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	
	    int Max(int a, int b, int c){
	        return max(a,max(b,c));
	    }
	    
	    
	    // Time complexity = O(n^2)
	    // Space complexity = O(2n)
	    int usingLISConcept(vector<int> &a){
	        int n = a.size();
	        
	        // dp[0][i] = Length of the longest
            // alternating subsequence ending at
            // index i and last element is greater
            // than its previous element
            // dp[1][i] = Length of the longest
            // alternating subsequence ending
            // at index i and last element is
            // smaller than its previous element
            // Initially LAS is of length 1 for all 
            // number in a
            vector<vector<int>> dp(2,vector<int>(n,1));

            int ans = 1;
            
            // using concept of LIS
            for(int i=1;i<n;i++){
                for(int j=0;j<i;j++){
                    if(a[j]<a[i]) dp[0][i] = max(dp[0][i],dp[1][j]+1);
                    else if(a[j]>a[i]) dp[1][i] = max(dp[1][i],dp[0][j]+1);
                    ans = Max(ans,dp[0][i],dp[1][i]);
                }
            }
            return ans;
	    }
	
	
	    // Time complexity = O(n)
	    // Space complexity = O(1)
	    int LAS(vector<int> &a){
	        int n = a.size();
	        
	        // we maintain 2 variables inc, dec
	        // inc = Length of longest alternative 
	        // subsequence so far with current value
	        // being greater than it’s previous value.
            // dec = Length of longest alternative
            // subsequence so far with current value
            // being smaller than it’s previous value.
            
            // initially both inc and dec are 1
            int inc = 1, dec = 1;
            
            // “inc” should be increased, iff the last
            // element in the alternative sequence was
            // smaller than it’s previous element.
            // “dec” should be increased, iff the last
            // element in the alternative sequence was
            // greater than it’s previous element.
            for(int i=1;i<n;i++){
                if(a[i]>a[i-1]) inc = dec+1;
                else if(a[i]<a[i-1]) dec = inc+1;
            }
            return max(inc,dec);
	    }
	
		int AlternatingaMaxLength(vector<int>&nums){
		    // Code here
		    // return usingLISConcept(nums);
		    return LAS(nums);
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.AlternatingaMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
