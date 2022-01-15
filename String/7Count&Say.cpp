class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        while(--n){
            string ns = "";
            int i = 0;
            while(i<s.size()){
                int count = 1;
                while(i<s.size()-1 and s[i]==s[i+1]){
                    i++;
                    count++;
                }
                ns += to_string(count)+s[i];
                i++;
            }
            s = ns;
        }
        return s;
    }
};


// Recursive
class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string ans = "";
        string pans = countAndSay(n-1);
        int count = 1, sz = pans.length();
        char pc = pans[0];
        for(int i=1;i<sz;i++){
            if(pans[i]==pc) count++;
            else{
                ans += to_string(count)+pc;
                pc = pans[i];
                count = 1;
            }
        }
        ans += to_string(count)+pc;
        return ans;
    }
};