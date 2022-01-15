class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // just concern with those numbers that are <=n
        // the rest won't be required as the answer would be n+1
        // for the # i<=n swap them to their location (i.e. i-1)
        // i.e. 5 will be stored in nums[4]
        for(int i=0;i<n;i++)
            while(nums[i]>0 and nums[i]<=n and nums[nums[i]-1]!=nums[i]) swap(nums[i],nums[nums[i]-1]);
        
        // with a traversal find the index i where i+1 is not stored that
        // i+1 will be the smallest possible #
        for(int i=0;i<n;i++) if(nums[i]!=i+1) return i+1;
        return n+1;
    }
};