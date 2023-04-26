// Question
// Link : https://leetcode.com/problems/subarray-product-less-than-k/
// Given an array of positive numbers, the task is to find the number of possible
// contiguous subarrays having product less than a given number k. 

// Brute force : Try all possible subarrays and check if their product is less than k.
// Time complexity : O(n^2)

// Sliding Window
// Time complexity : O(n)
class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int ans = 0;
        long long prod = 1;
        for(int i=0,j=0;j<n;j++){
            prod *= a[j];
            while(i<j and prod>=k) prod /= a[i++];
            if(prod<k) ans += 1+(j-i);
        }
        return ans;
    }
};