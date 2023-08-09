class Solution:
    def strangePrinter(self, s: str) -> int:
        n = len(s)
        dp = [[-1]*(n+1) for _ in range(n+1)]
        for start in range(n-1,-1,-1):
            for end in range(n):
                ans = float("inf")
                if start==end: ans = 1
                elif end-start==1: ans = 2
                else:
                    for i in range(start+1,end+1):
                        ans = min(ans,dp[start][i-1]+dp[i][end])
                if start!=end and s[start]==s[end]: ans -= 1
                dp[start][end] = ans
        return dp[0][n-1]