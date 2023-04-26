class Solution {
public:
    int minOperations(vector<int>& nums) {
        // keeping original # of elements
        int n = nums.size();
        // sorting and removing repeated elements
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        
        // using sliding window approach to get
        // the min operations to be performed
        int ans = INT_MAX;
        int j = 0;
        for(int i=0;i<nums.size();i++){
            // go upto the point where numbers are <= nums[i]+n-1
            while(j<nums.size() and nums[j]<=nums[i]+n-1) j++;
            // the rest are to be replace or removed to make 
            // array continuous, (j-i) is length of continous array
            // thus to remove or replace are n-(j-i)
            ans = min(ans,n-(j-i));
        }
        return ans;
    }
};