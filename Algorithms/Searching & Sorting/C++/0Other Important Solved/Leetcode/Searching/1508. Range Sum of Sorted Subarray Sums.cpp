// Question
// Link: https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/
// You are given the array nums consisting of n positive integers.
// You computed the sum of all non-empty continuous subarrays from the array
// and then sorted them in non-decreasing order, creating a new array of n * (n + 1) / 2 numbers.

// Return the sum of the numbers from index left to index right (indexed from 1),
// inclusive, in the new array. Since the answer can be a huge number return it modulo 109 + 7.

class Solution {
private:
// the complete algorithm is to binary search the required sum of subarrays
// using binary search and sliding window concept

    // binary search on range from min(nums) sum(nums) (Subarray sums can vary from min of nums to sum of all elements)
    long long sumOf1stKSmallestSubarrays(vector<int> &num, int k) {
        long long l = *min_element(num.begin(),num.end());
        long long r = accumulate(num.begin(),num.end(),0);
        while(l<=r) {
            long long mid = (l+r)/2;
            if(countNSum(num,mid).first>=k) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        auto [count, sum] = countNSum(num,l);

        // we found count of and sum of all such subarrays that add upto the sum "left"
        // but we need only the sum of the 1st k smallest subarrays
        // thus removing the sum of the rest of the subarrays that have been added to the "sum"
        return sum - l*(count-k);
    }

    // sliding window implementation to find the count of subarrays and sum of all
    // the subarrays with the sum target
    pair<int, long long> countNSum(vector<int> num, long long target) {
        int n = num.size();
        // windowSum carries the sum of all the subarrays upto that index
        // each index contributes "count" times to the sum thus count*(nth number) is
        // added to the windowSum
        // sumOfSubarrayI2J is the current subarray containing the sum of elements from i to j
        // totalSum is the sum of all subarrays with sum target
        long long sumOfSubarrayI2J = 0, windowSum = 0, totalSum = 0;
        int count = 0;
        for(int i=0,j=0;j<n;j++) {
            sumOfSubarrayI2J += num[j];
            windowSum += (j-i+1) * num[j];
            while(sumOfSubarrayI2J>target) {
                // as sum of current subarray is more than target thus we need to remove it
                // first remove the subarray sum from the windowSum and then remove the ith
                // element from the current subarray
                windowSum -= sumOfSubarrayI2J;
                sumOfSubarrayI2J -= num[i++];
            }
            count += (j-i+1);
            totalSum += windowSum;
        }
        return {count,totalSum};
    }
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        long long mod = 1e9+7;
        // getting sum of subarrays in range l -> r, we get sum of first r subarrays
        // and sum of first l-1 subarrays, then subtract to get the answer
        long long ans = sumOf1stKSmallestSubarrays(nums,right) - sumOf1stKSmallestSubarrays(nums,left-1);
        return (ans+mod)%mod;
    }
};