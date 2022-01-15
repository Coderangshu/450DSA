class Solution {
public:
    
    int memo[10001];
    
    int recursion(int num, unordered_map<int,int> &um){
        if(num<=0) return 0;
        if(memo[num]!=-1) return memo[num];
        int taken = num*um[num]+recursion(num-2,um);
        int notTaken = recursion(num-1,um);
        return memo[num] = max(taken,notTaken);
    }
    
    int deleteAndEarn(vector<int>& nums) {
        memset(memo,-1,sizeof(memo));
        unordered_map<int,int> um;
        int maxNum = INT_MIN;
        for(auto e:nums){
            um[e]++;
            maxNum = max(maxNum,e);
        }
        return recursion(maxNum,um);
    }
};

// Similar to house robber problem just here the element is skipped instead
// of indices, for the ones taken into account all of their occurences are taken
// thus need to create a frequency hashmap for each element in the nums
// and start from the largest element in nums and recurse until not 0