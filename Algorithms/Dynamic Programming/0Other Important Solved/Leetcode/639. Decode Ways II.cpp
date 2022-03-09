class Solution {
public:
    int mod = 1e9+7;
    
    
    
    
    // Method 1 : Memoization
    unordered_map<int,int> um;
    
    int recursion(string s, int ind){
        int n = s.length();
        if(um.find(ind)!=um.end()) return um[ind];
        if(ind==n) return um[ind] = 1;
        if(s[ind]=='0') return um[ind] = 0;
        
        // if s[ind] is '*'
        if(s[ind]=='*'){
            // single character
            long long int ans = ((long long int)9*recursion(s,ind+1));
            
            // double character
            if(ind<n-1){
                // if second digit
                if(s[ind+1]>='0' and s[ind+1]<='6') ans += (long long int)2*recursion(s,ind+2);
                else if(s[ind+1]>='7' and s[ind+1]<='9') ans += recursion(s,ind+2);
                // if second "*"
                else if(s[ind+1]=='*') ans += (long long int)15*recursion(s,ind+2);
            }
            return um[ind] = ans%mod;
        }
        
        // if s[ind] is digit
        // single character
        long long int ans = recursion(s,ind+1);
        
        // double characters
        if(ind<n-1){
            // if both digit
            if(s[ind]=='1' and (s[ind+1]>='0' and s[ind+1]<='9')) ans += recursion(s,ind+2);
            else if(s[ind]=='2' and (s[ind+1]>='0' and s[ind+1]<='6')) ans += recursion(s,ind+2);
            // if second "*"
            else{
                if(s[ind]=='1' and s[ind+1]=='*') ans += (long long int)9*recursion(s,ind+2);
                if(s[ind]=='2' and s[ind+1]=='*') ans += (long long int)6*recursion(s,ind+2);
            }
        }
        return um[ind] = ans%mod;
    }
    
    
    
    
    
    
    // Method 2 : Top Down
    // 1 char
    long long int ways(char s){
        if(s=='*') return 9;
        if(s=='0') return 0;
        else return 1;
    }
    
    // 2 chars
    long long int ways(char s1, char s2){
        string concat = "";
        concat += s1;
        concat += s2;
        
        // if both digits
        if(s1!='*' and s2!='*'){
            int i = stoi(concat);
            if(i>=10 and i<=26) return 1;
        }
        
        // if both '*' then 11-19 and 21-26 are the possibilities
        else if(s1=='*' and s2=='*') return 15;
        
        // if s1 is '*'
        else if(s1=='*'){
            // if s2 is 0-6 then s1 can be 1 or 2
            if(s2>='0' and s2<='6') return 2;
            // else s1 can only be 1
            else return 1;
        }
        
        // if s2 is '*'
        else{
            // for the couple s1 and s2 to be acceptable
            // s1 has to be 1 or 2
            if(s1=='1') return 9;
            else if(s1=='2') return 6;
        }
        // if none above satisfied
        return 0;
    }
    
    int numDecodings(string s) {
        // memoization
        // int ans = recursion(s,0);
        
        // top down
        // we proceed from index 0 to last in string
        // array to store the current and prev decoding ways #
        long long int dp[2];
        
        dp[0] = ways(s[0]);
        if(s.length()<2) return (int)dp[0];
        dp[1] = (dp[0]*ways(s[1]))+ways(s[0],s[1]);
        
        for(int i=2;i<s.length();i++){
            long long int temp = dp[1];
            dp[1] = (dp[1]*ways(s[i])+(dp[0]*ways(s[i-1],s[i])))%mod;
            dp[0] = temp;
        }
        
        return (int)dp[1];
    }
};
