class Solution {
public:
    string orderlyQueue(string s, int k) {
        // when window is of length 1 then only rotation can be done
        // without any rearrangement thus return the lexicographically 
        // smallest rotated string, if window length is 2 or more then
        // we can change the sequence of the characters and this empowers
        // us to arrange the chars in any order and thus the sorted string
        // if the output
        if(k>1){
            sort(s.begin(),s.end());
            return s;
        }
        string ans = s;
        for(int i=1;i<s.length();i++){
            ans = min(ans,s.substr(i)+s.substr(0,i));
        }
        return ans;
    }
};