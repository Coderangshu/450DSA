// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    int Min(int a, int b, int c){
        return min(a,min(b,c));
    }
    
    int editDistanceUtil(string s1, int n1, string s2, int n2){
        int dp[n1+1][n2+1];
        for(int i=0;i<n1+1;i++){
            for(int j=0;j<n2+1;j++){
                // if s1 empty then only option is to insert
                // all letters of s2
                if(i==0) dp[i][j] = j;
                // if s2 empty then only option is to remove
                // all letters of s1
                else if(j==0) dp[i][j] = i;
                // if same character then nothing to do
                // go to next character of both string
                else if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1];
                // else we got three option either insert,remove or
                // replace letter from s1 to make same as s2,
                // any of the 3 is done which provides the 
                // minimum operation
                //                      insert     remove      replace
                else dp[i][j] = 1+Min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]);
            }
        }
        
        // for(int i=0;i<n1+1;i++){
        //     for(int j=0;j<n2+1;j++) cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        return dp[n1][n2];
    }
  
    int editDistance(string s, string t) {
        // Code here
        int ans = editDistanceUtil(s,s.length(),t,t.length());
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
