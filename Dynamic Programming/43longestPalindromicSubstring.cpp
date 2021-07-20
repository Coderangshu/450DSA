class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        bool dp[n][n];
        memset(dp,false,sizeof(dp));
        int startOfMaxPalin = 0, maxLength = 1;
        for(int L=1;L<=n;L++){
            for(int i=0;i<=n-L;i++){
                int j = i+L-1;
                if(L==1) dp[i][j] = true;
                else if(L==2){
                    if(s[i]==s[j]){
                        dp[i][j] = true;
                        if(L>maxLength){
                            startOfMaxPalin = i;
                            maxLength = L;
                        }
                    }
                } 
                else{
                    if(s[i]==s[j] and dp[i+1][j-1]){
                        dp[i][j] = true;
                        if(L>maxLength){
                            startOfMaxPalin = i;
                            maxLength = L;
                        }
                    }
                }
            }
        }
        return s.substr(startOfMaxPalin,maxLength);
    }
};
