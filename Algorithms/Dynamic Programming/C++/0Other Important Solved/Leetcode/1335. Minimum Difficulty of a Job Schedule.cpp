// Question : https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/

class Solution {
private:
    vector<int> v;
    
    int recursion(int start, int d){
        if(d==1) return *max_element(v.begin()+start,v.end());
        int ans = INT_MAX, maxDifficultyToday = INT_MIN, n = v.size();
        for(int i=start;i<=n-d;i++){
            maxDifficultyToday = max(maxDifficultyToday,v[i]);
            int rest = recursion(i+1,d-1);
            ans = min(ans,maxDifficultyToday+rest);
        }
        return ans;
    }
    
    int tabulation(int day){
        int n = v.size();
        vector<vector<int>> dp(n+1,vector<int>(day+1,-1));
        for(int i=n-1;i>=0;i--){
            for(int d=1;d<=day;d++){
                if(d==1) dp[i][d] = *max_element(v.begin()+i,v.end());
                else{
                    int ans = INT_MAX, maxDifficultyToday = INT_MIN, n = v.size();
                    for(int j=i;j<=n-d;j++){
                        maxDifficultyToday = max(maxDifficultyToday,v[j]);
                        int rest = dp[j+1][d-1];
                        ans = min(ans,maxDifficultyToday+rest);
                    }
                    dp[i][d] = ans;
                }
            }
        }
        return dp[0][day];
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        v = jobDifficulty;
        // int ans = recursion(0,d);
        int ans = tabulation(d);
        return (ans>300000)?-1:ans;
    }
};