class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i==0 or nums[i]!=nums[i-1]){
                int l = i+1, r = n-1;
                while(l<r){
                    int sum = nums[i]+nums[l]+nums[r];
                    if(sum>0) r--;
                    else if(sum<0) l++;
                    else{
                        vector<int> a = {nums[i],nums[l],nums[r]};
                        ans.push_back(a);
                        while(l<r and nums[l]==a[1]) l++;
                        while(l<r and nums[r]==a[2]) r--;
                    }
                }
            }
        }
        return ans;
    }
};

// look into 4sum for a recursive generalised solution for ksum