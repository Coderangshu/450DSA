// Question : https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> um;
        for(auto &c:t) um[c]++;
        int count = um.size(), startIndex = 0, minLen = INT_MAX, ns = s.length();
        for(int i=0,j=0;i<ns and j<ns;j++){
            if(um.count(s[j]) and --um[s[j]]==0) count--;
            while(!count and i<=j){
                if(j-i+1<minLen){
                    minLen = j-i+1;
                    startIndex = i;
                }
                if(um.count(s[i])){
                    um[s[i]]++;
                    if(um[s[i]]>0) count++;
                }
                i++;
            }
        }
        if(minLen==INT_MAX) return "";
        return s.substr(startIndex,minLen);
    }
};