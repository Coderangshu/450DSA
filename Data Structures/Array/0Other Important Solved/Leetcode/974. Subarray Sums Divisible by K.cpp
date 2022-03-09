// Question : https://leetcode.com/problems/subarray-sums-divisible-by-k/description/

class Solution {
public:
    // for example {4,5,0,-2,-3,1}, k = 5
    // taking prefix sum -> {4,9,9,7,4,5} --> arr1
    // taking %k -> {4,4,4,3,4,0} --> arr2
    // for any subarray {i to j} to be divisible by k
    // arr2[j]-arr2[i-1] = 0, thus any repeting elements
    // imply there exist a subarray in between this 2 which is
    // divisible by k
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0, sum = 0;
        vector<int> countOfEachPrefixSum(k,0);
        for(auto &e:nums) {
            // for -ve e e%k + k gives the actual mod value
            sum = (sum + e%k + k) % k;
            // when sum==0 means from starting to this element
            // the subarray is divisible by k
            if(sum==0) ans++;
            ans += countOfEachPrefixSum[sum]++;
        }
        return ans;
    }
};