class Solution {
private:
    void recursion(vector<int>& candidates, int target, int ind, 
                   vector<int> &tans, vector<vector<int>> &ans){
        int n = candidates.size();
        if(target==0){
            ans.push_back(tans);
            return;
        }
        for(int i=ind;i<n;i++){
            // if i==ind then we take into tans as this will be the
            // first in that subset, else we avoid taking the same
            // elements again to maintain the uniqueness
            if(i>ind and candidates[i]==candidates[i-1]) continue;
            // if candidates[i] increases then target then its useless
            // to keep checking the rest as they would be greater than
            // target too
            if(candidates[i]>target) break;
            tans.push_back(candidates[i]);
            recursion(candidates,target-candidates[i],i+1,tans,ans);
            tans.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> tans;
        recursion(candidates,target,0,tans,ans);
        return ans;
    }
};