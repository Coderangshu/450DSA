class Solution {
public:
    int memo[21][31];
    
    bool recursion(const string &s, const string &p, int ls, int lp){
        if(ls==0 and lp==0) return true;
        if(lp==0) return false;
        if(ls==0) return memo[ls][lp] = (p[lp-1]=='*')?recursion(s,p,ls,lp-2):false;
        
        if(memo[ls][lp]!=-1) return memo[ls][lp];
        
        if(s[ls-1]==p[lp-1] or p[lp-1]=='.') return memo[ls][lp] = recursion(s,p,ls-1,lp-1);
        if(s[ls-1]!=p[lp-1]){
            if(p[lp-1]!='*') return memo[ls][lp] = false;
            if(s[ls-1]!=p[lp-2] and p[lp-2]!='.') return memo[ls][lp] = recursion(s,p,ls,lp-2);
            return memo[ls][lp] = (recursion(s,p,ls,lp-1) or 
                                   recursion(s,p,ls,lp-2) or 
                                   recursion(s,p,ls-1,lp));
        }
        return false;
    }
    
    bool isMatch(string s, string p) {
        memset(memo,-1,sizeof(memo));
        return recursion(s,p,s.length(),p.length());
    }
};