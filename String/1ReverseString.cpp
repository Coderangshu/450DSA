class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for(int i=0;i<n/2;i++) swap(s[i],s[s.size()-i-1]);
    }
};
