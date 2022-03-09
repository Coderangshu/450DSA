// Question : https://leetcode.com/problems/continuous-subarray-sum/

// Maintaining sum with modding with k
// Searching for current modded sum in map
// if previously encountered implies sum from 
// that to current index is 0 and as there are
// no -ve values thus it must be that a multiple
// of k has been encountered here which has been
// removed by the modding thus resulting in zero

// TC : O(n) SC : O(k)

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        int sum = 0;
        um[0] = -1;
        for(int i=0;i<nums.size();i++){
            sum = (sum+nums[i])%k;
            if(um.count(sum)){
                if(i-um[sum]>1) return true;
            }
            else um[sum] = i;
        }
        return false;
    }
};