class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<char,vector<int>> um;
        for(auto word:words){
            int mask = 0;
            for(auto c:word) mask |= (1<<(c-'a'));
            for(int i=0;i<26;i++)if(mask&(1<<i)) um[i+'a'].push_back(mask);
        }
        
        vector<int> ans;
        for(auto puzzle:puzzles){
            int pmask = 0;
            for(auto c:puzzle) pmask |= (1<<(c-'a'));
            int count = 0;
            for(auto wMask:um[puzzle[0]])
                if((wMask&pmask)==wMask) count++;
            ans.push_back(count);
        }
        return ans;
    }
};
