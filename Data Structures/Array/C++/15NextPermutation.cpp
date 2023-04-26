class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Using STL:
        // next_permutation(nums.begin(),nums.end());
        
        // to understand below dictionary algo:
        // 1 3 5 4 2
        // (1) for above we see the peak is at 5
        //      5
        //    3   4
        //  1       2

        // (2) for getting the next permute we need to change
        // 3 to the next largest number
        // thus sequence becomes: 1 4 5 3 2

        // (3) we need the immediate next greater permutation
        // thus 5 3 2 is rotated to make them sorted which
        // is the lexicographically the smallest sequence
        // thus sequence becomes: 1 4 2 3 5 ---> ANS
        
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
