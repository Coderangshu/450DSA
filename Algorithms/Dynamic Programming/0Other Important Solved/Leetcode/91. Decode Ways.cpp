class Solution {
public:
    
    unordered_map<int,int> um;
    
    // returns 0 to last index # of decoding ways
    int recursion(string s, int index){
        int n = s.length();
        if(um.find(index)!=um.end()) return um[index];
        
        // ways of decoding from string ending is always 1
        if(index==n) return um[index] = 1;
        if(s[index]=='0') return um[index] = 0;
        
        // for single strings - "1" to "9"
        int res = recursion(s,index+1);
       
        // for strings "10" to "26"
        if(index<n-1 and (s[index]=='1' or (s[index]=='2' and s[index+1]<='6')))
            res += recursion(s,index+2);
        return um[index] = res;
    }
    
    int numDecodings(string s) {
        return recursion(s,0);
    }
};
