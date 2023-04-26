// Question - https://leetcode.com/problems/maximize-greatness-of-an-array/description/
/*

You are given a 0-indexed integer array nums. You are allowed to permute nums into a new array perm of your choosing.

We define the greatness of nums be the number of indices 0 <= i < nums.length for which perm[i] > nums[i].

Return the maximum possible greatness you can achieve after permuting nums.


Example 1:

Input: nums = [1,3,5,2,1,3,1]
Output: 4
Explanation: One of the optimal rearrangements is perm = [2,5,1,3,3,1,1].
At indices = 0, 1, 3, and 4, perm[i] > nums[i]. Hence, we return 4.
*/


#include<bits/stdc++.h>
using namespace std;


// just consider the next greater element for each element
// when placed in sorted order, this greater element can replace
// the original element in the answer array, once greater elements
// are exhausted means the rest the numbers cannot be replaced with
// greater elements thus won't increase the answer
class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = 0, j = 0, n = nums.size(), ans = 0;
        while(j<n) {
            // finding next greater element for ith element in sorted nums
            while(j<n and nums[i]>=nums[j]) j++;
            // if j not exhausted than have element to replace ith element
            if(j<n) ans++;
            // current i and j pair solved move to next of both
            j++;
            i++;
        }
        return ans;
    }
};