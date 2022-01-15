// Question
// Link : https://leetcode.com/problems/minimum-size-subarray-sum/
// Given an array of positive integers nums and a positive integer target, 
// return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] 
// of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead. 

// Sliding Window
// Time complexity : O(n)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX, n = nums.size(), sum = 0;
        for(int i=0,j=0;j<n;j++){
            sum += nums[j];
            if(sum>=target) ans = min(ans,j-i+1);
            while(i<j and sum>=target){
                sum -= nums[i++];
                if(sum>=target) ans = min(ans,j-i+1);
            }
        }
        return (ans==INT_MAX)?0:ans;
    }
};