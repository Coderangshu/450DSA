class Solution {
public:
    
    // Using LIS concept
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n = pairs.size();
        vector<int> LIS(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(pairs[i][0]>pairs[j][1] and LIS[i]<LIS[j]+1)
                    LIS[i] = LIS[j]+1;
            }
        }
        return *max_element(LIS.begin(),LIS.end());
    }
};
