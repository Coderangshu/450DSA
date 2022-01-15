// DFSing for each of the k to find if sum exists
class Solution {
public:
    vector<bool> visited;
    
    bool recursion(const vector<int> &nums, int sumI, int ind){
        if(sumI==0) return true;
        // start searching from the ind index of 
        // nums as the previous have already been checked
        for(int i=ind;i<nums.size();i++){
            if(!visited[i] and nums[i]<=sumI){
                visited[i] = true;
                if(recursion(nums,sumI-nums[i],ind+1)) return true;
                visited[i] = false;
            }
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==1) return true;
        if(n<k) return false;
        
        visited.assign(n,false);
        int sum = accumulate(nums.begin(),nums.end(),0);
        
        if(sum%k!=0) return false;
        int sumI = sum/k;
        
        // sorting to get the max # to subtract quicker for each iteration
        sort(nums.begin(),nums.end(),greater<int>());
        
        for(int i=0;i<k;i++) if(!recursion(nums,sumI,0)) return false;
        return true;
    }
};