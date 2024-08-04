// Question
// Link: https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/
// You are given the array nums consisting of n positive integers.
// You computed the sum of all non-empty continuous subarrays from the array
// and then sorted them in non-decreasing order, creating a new array of n * (n + 1) / 2 numbers.

// Return the sum of the numbers from index left to index right (indexed from 1),
// inclusive, in the new array. Since the answer can be a huge number return it modulo 109 + 7.

class Solution {
public:
    // we maintain a heap to store the sum of first n smallest subarrays 
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++) pq.push({nums[i],i});
        int ans = 0, mod = 1e9+7;
        for (int i=1;i<=right;i++) {
            auto t = pq.top();
            pq.pop();
            if(i>=left) ans = (ans+t.first)%mod;
            if(t.second+1<n) {
                t.first += nums[++t.second];
                pq.push(t);
            }
        }
        return ans;
    }
};