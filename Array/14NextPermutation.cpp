class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(),nums.end());
        if(nums.size()<=1) return;
        int i = nums.size()-2;
	// Traverse from back to get the break point.
        while(i>=0 && nums[i]>=nums[i+1]) i--;
        if(i>=0){
            int j = nums.size()-1;
	    // Traverse from back again to get the 
	    // number just greater than the number at
	    // the breakpoint.
            while(nums[j]<=nums[i]) j--;
	    // swapped to make the just bigger permute.
            swap(nums[i],nums[j]);
        }
	// As all the number next to ith are in descending
	// order, reverse it to get the most smallest 
	// permute possible just greater than the last.
	// This gives the next permutation. 
        reverse(nums.begin()+i+1,nums.end());
    }
};
