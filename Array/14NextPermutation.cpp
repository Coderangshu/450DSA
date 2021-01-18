class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(),nums.end());
        if(nums.size()<=1) return;
        int i = nums.size()-2;
        while(i>=0 && nums[i]>=nums[i+1]) i--;
        if(i>=0){
            int j = nums.size()-1;
            while(nums[j]<=nums[i]) j--;
            swap(nums[i],nums[j]);
        }
        reverse(nums.begin()+i+1,nums.end());
    }
};
