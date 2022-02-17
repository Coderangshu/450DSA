// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  private:
    vector<vector<int>> memo;
    int recursion(string &word1, string &word2, int i, int j, int n, int m){
        if(i==n) return m-j;
        if(j==m) return n-i;
        if(memo[i][j]!=-1) return memo[i][j];
        if(word1[i]==word2[j]) return memo[i][j] = recursion(word1,word2,i+1,j+1,n,m);
        int ins = recursion(word1,word2,i,j+1,n,m);
        int del = recursion(word1,word2,i+1,j,n,m);
        int rep = recursion(word1,word2,i+1,j+1,n,m);
        return memo[i][j] = 1+min(ins,min(del,rep));
    }


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
        
        return dp[n1][n2];
    }
  public:
  
    int editDistance(string s, string t) {
        // Code here
        // Uncomment any of the below either recursion or iterative
        
        // recursion
        // int n = word1.length(), m = word2.length();
        // memo.assign(n+1,vector<int>(m+1,-1));
        // return recursion(word1,word2,0,0,n,m);

        // iterative
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
