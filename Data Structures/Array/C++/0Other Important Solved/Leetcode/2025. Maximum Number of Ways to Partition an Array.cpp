class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<long long> prefixSum(n);
        prefixSum[0] = nums[0];
        for(int i=1;i<n;i++) prefixSum[i] = prefixSum[i-1]+nums[i];
        
        unordered_map<long long,long long> left, right;
        
        // storing the frequency of (1st half - 2nd half) differences in right
        // initially left will be empty
        for(int i=0;i<n-1;i++) right[2*prefixSum[i]-prefixSum[n-1]]++;
        
        long long ans = 0;
        // getting the pivots which diff by 0 without any changes to k
        if(right.count(0)) ans += right[0];
        
        // taking the diff of each nums[i] and counting the number of pivots
        // and getting the max for each nums[i] changed to k
        for(int i=0;i<n;i++){
            long long tans = 0, diff = k-nums[i];
            if(left.count(diff)) tans += left[diff];
            if(right.count(-diff)) tans += right[-diff];
            ans = max(ans,tans);
            // shifting the diff from right map to left map
            if(i<n-1){
                long long diff = 2*prefixSum[i]-prefixSum[n-1];
                left[diff]++, right[diff]--;
                if(right.count(diff)==0) right.erase(diff);
            }
        }
        return ans;
    }
};