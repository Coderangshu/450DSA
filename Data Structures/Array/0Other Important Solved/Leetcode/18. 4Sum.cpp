class Solution {
public:
    
    vector<vector<int>> kSum(vector<int>& nums, int target, int k, int ind){
        vector<vector<int>> ans;
        int n = nums.size();
        if(ind>=n) return ans;
        if(k==2){
            int l = ind, r = n-1;
            while(l<r){
                int sum = nums[l]+nums[r];
                if(sum>target) r--;
                else if(sum<target) l++;
                else{
                    vector<int> a = {nums[l],nums[r]};
                    ans.push_back(a);
                    while(l<r and nums[l]==a[0]) l++;
                    while(l<r and nums[r]==a[1]) r--;
                }
            }
        }
        else{
            for(int i=ind;i<n-k+1;i++){
                if(i==0 or nums[i]!=nums[i-1]){
                    vector<vector<int>> tans = kSum(nums,target-nums[i],k-1,i+1);
                    for(auto e:tans){
                        e.push_back(nums[i]);
                        if(find(ans.begin(),ans.end(),e)==ans.end()) ans.push_back(e);
                    }
                }
            }
        }
        return ans;
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        return kSum(nums,target,4,0);
    }
};