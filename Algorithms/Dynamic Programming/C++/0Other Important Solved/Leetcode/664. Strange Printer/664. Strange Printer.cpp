class Solution {
private:
    string s;
    vector<vector<int>> memo;
    int recursion(int start, int end) {
        if(start==end) return 1;
        else if(end-start==1) {
            if (s[start]==s[end]) return 1;
            else return 2;
        }
        if(memo[start][end]!=-1) return memo[start][end];
        int ans = INT_MAX;
        for(int i=start+1;i<=end;i++) {
            ans = min(ans,recursion(start,i-1)+recursion(i,end));
        }
        if(s[start]==s[end]) return memo[start][end] = ans-1;
        else return memo[start][end] = ans;
    }

public:
    int strangePrinter(string s) {
        int n = s.length();
        // Using Bottom Up Recursion
        // memo.assign(n+1,vector<int>(n+1,-1));
        // this->s = s;
        // recursion(0,n-1);

        // Using Top Down Tabulation
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        for(int start=n-1;start>=0;start--) {
            for(int end=0;end<n;end++) {
                int ans = INT_MAX;
                if(start==end) ans = 1;
                else if(end-start==1) ans = 2;
                else for(int i=start+1;i<=end;i++)
                    ans = min(ans,dp[start][i-1]+dp[i][end]);
                // if start and end of a substring is same then we need one less
                // switching as from start to end that character can be printed at
                // the beginning and then the rest can overwrite in between indices
                if(start!=end and s[start]==s[end]) ans--;
                dp[start][end] = ans;
            }
        }
        return dp[0][n-1];
    }
};