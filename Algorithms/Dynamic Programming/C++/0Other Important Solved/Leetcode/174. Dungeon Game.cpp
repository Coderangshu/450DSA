class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 and j==m-1) dp[i][j] = (dungeon[i][j]>0)?0:dungeon[i][j];
                else if(i==n-1) dp[i][j] = (dungeon[i][j]+dp[i][j+1]>0)?0:dungeon[i][j]+dp[i][j+1];
                else if(j==m-1) dp[i][j] = (dungeon[i][j]+dp[i+1][j]>0)?0:dungeon[i][j]+dp[i+1][j];
                else{
                    int t = max(dp[i+1][j],dp[i][j+1]);
                    dp[i][j] = (t+dungeon[i][j]>0)?0:t+dungeon[i][j];
                }
            }
        }
        // for(auto e:dp){
        //     for(auto f:e) cout<<f<<" ";
        //     cout<<endl;
        // }
        return abs(dp[0][0])+1;
    }
};