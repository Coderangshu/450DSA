// Question:
// Link : https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/
// You are given an integer array nums and two integers minK and maxK.
// A fixed-bound subarray of nums is a subarray that satisfies the following conditions:

//     The minimum value in the subarray is equal to minK.
//     The maximum value in the subarray is equal to maxK.

// Return the number of fixed-bound subarrays.

// A subarray is a contiguous part of an array.

// NOTE: fixed-bound subarrays and subarray count is the keyword for such algorithm to apply

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0, n = nums.size(), lastOutOfBound = -1, lastmn = -1, lastmx = -1, longZero = 0;
        // pointer i moves on forward just keeping track of last minK, maxK and outOfRange indices encountered
        // now imagine the 4 pointers are located in random indices (4th being pointer i)
        // we need count of subarrays containing elements in range minK to maxK
        // thus for current subarray from min(lastmn,lastmx) to max(lastmn,lastmx) must be present always inside the subarrays whose count is to be added into answer
        // consider i is currently on max(lastmn,lastmx) and lastOutOfBound is somewhere behind min(lastmn,lastmx)
        // we add to answer min(lastmn,lastmx) - lastOutOfBound, as these # of elements from lastOutOfBound to min(lastmn,lastmx) can be each considered in subarray or not(also these elements are in range minK to maxK), taking into answer all these possible subarrrays as they satisfy the condition
        // lets now move i to next index, but notice lastmn, lastmx and lastOutOfBound are in same position
        // now we take into answer all the subarrays as previous only now the ith index element is additional in each of the new subarrays, whose count is to be added to answer
        // thus same # of subarrays satifying the condition are added to the answer using the same eq : min(lastmn,lastmx) - lastOutOfBound
        for(int i=0;i<n;i++) {
            if(nums[i]==minK) lastmn = i;
            if(nums[i]==maxK) lastmx = i;
            if(nums[i]<minK or nums[i]>maxK) lastOutOfBound = i;
            // max of 0 and min(lastmn,lastmx) - lastOutOfBound is taken to consider cases where lastOutOfBound
            // is ahead of lastmn and lastmx, so their is no suitable subarray to be added to answer
            ans += max(longZero,min(lastmn,lastmx)-lastOutOfBound);
        }
        return ans;
    }
};