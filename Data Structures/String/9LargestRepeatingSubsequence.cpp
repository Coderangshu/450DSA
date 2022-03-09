// DP is used to solve the problem refer https://www.youtube.com/watch?v=ZqG89Z-dKpI
// The concept is similar to Longest Common Subsequence.
// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n = str.length();
		    string dp[n+1][n+1];
		    for(int i=0;i<n+1;i++){
		        for(int j=0;j<n+1;j++){
		            if(i==0 or j==0) dp[i][j] = "";
		            else if(str[i-1]==str[j-1] and i!=j) dp[i][j] = dp[i-1][j-1]+str[i-1];
		            else dp[i][j] = (dp[i-1][j].length()>dp[i][j-1].length())?dp[i-1][j]:dp[i][j-1];
		        }
		    }
		    return dp[n][n].length();
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
