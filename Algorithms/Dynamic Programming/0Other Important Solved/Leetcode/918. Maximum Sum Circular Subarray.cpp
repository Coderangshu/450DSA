class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxNow = 0, maxSoFar = INT_MIN, minNow = 0, minSoFar = INT_MAX;
        for(auto e:nums){
            maxNow = max(maxNow+e,e);
            minNow = min(minNow+e,e);
            maxSoFar = max(maxNow,maxSoFar);
            minSoFar = min(minNow,minSoFar);
        }
        int totSum = accumulate(nums.begin(),nums.end(),0);
        int ans = max(maxSoFar,totSum-minSoFar);
        // when all -ve elements in nums, ans will be 0,
        // in that case return maxSoFar
        return (ans==0)?maxSoFar:ans;
    }
};