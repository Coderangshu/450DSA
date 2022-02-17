class Solution {
public:
    int uniqueLetterString(string s) {
        // focus on each character's contribution instead of substrings
        int ans = 0, uptoCur = 0, n = s.length();
        vector<int> lastPosition(26,0), contribution(26,0);
        for(int i=0;i<n;i++){
            int curChar = s[i]-'A';
            // removing the contribution of current character from the uptoCur
            uptoCur -= contribution[curChar];
            // Updating current character's contribution
            contribution[curChar] = i-lastPosition[curChar]+1;
            // adding it back to uptoCur
            uptoCur += contribution[curChar];
            lastPosition[curChar] = i+1;
            // now adding this whole to the ans
            ans += uptoCur;
        }
        return ans;
    }
};