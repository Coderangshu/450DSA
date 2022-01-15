#include<bits/stdc++.h>
using namespace std;

// Method 1:
// Get all possible k partitions of the given set
// Check for each partition if sum of each subset is equal to targetSum
class Solution1 {
private:
    vector<vector<vector<int>>> ans;
    void recursion(vector<int>& nums, int ind, int k, int nos, int ksum, vector<vector<int>> &tans){
        if(ind>=nums.size()){
            if(k==nos){
                for(auto e:tans) if(accumulate(e.begin(),e.end(),0)!=ksum) return;
                ans.push_back(tans);
            }
            return;
        }
        for(int i=0;i<k;i++){
            if(tans[i].size()>0){
                tans[i].push_back(nums[ind]);
                recursion(nums,ind+1,k,nos,ksum,tans);
                tans[i].pop_back();
            }
            else{
                tans[i].push_back(nums[ind]);
                recursion(nums,ind+1,k,nos+1,ksum,tans);
                tans[i].pop_back();
                break;
            }
        }
    }
    
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(k==1) return true;
		if(k>nums.size()) return false;
        int totsum = accumulate(nums.begin(),nums.end(),0);
        if(totsum%k!=0) return false;
        int ksum = totsum/k;
        vector<vector<int>> tans(k,vector<int>());
        recursion(nums,0,k,0,ksum,tans);
        return (!ans.empty());
    }
};

// Method 2:
// take first partition fill with values until sum is not equal to ksum
// then take second partition fill with values until sum is not equal to ksum
// and so on....
class Solution2 {
private:
    bool canPartitionKSubsets(vector<int> &v, int subsetSum, vector<bool> &taken,
		                       int targetSum, int k, int curIdx, int idx){
        int n = v.size();
        if(subsetSum==targetSum){
			// we just need to check upto k-2 partition as the 
			// last partition will automatically contain the sum as ksum
            if(curIdx==k-2) return true;
			// else we need to check if the next partition is possible
			// we again start from the first element and put into the next
			// partition if that element hasn't been taken previously
            return canPartitionKSubsets(v,0,taken,targetSum,k,curIdx+1,0);
        }
        for(int i=idx;i<n;i++){
            if(!taken[i]){
                if(subsetSum+v[i]<=targetSum){
                    taken[i] = true;
                    subsetSum += v[i];
                    if(canPartitionKSubsets(v,subsetSum,taken,targetSum,k,curIdx,i+1)) return true;
                    taken[i] = false;
                    subsetSum -= v[i];
                }
            }
        }
        return false;
    }

public:
    bool canPartitionKSubsets(vector<int> &v, int k){
        if(k==1) return true;
        int n = v.size();
        if(k>n) return false;
        int totSum = accumulate(v.begin(),v.end(),0);
        if(totSum%k!=0) return false;
        int targetSum = totSum/k;
        vector<bool> taken(n,false);
        return canPartitionKSubsets(v,0,taken,targetSum,k,0,0);
    }
};

int main(){
	vector<int> v = {2,1,4,5,3,3};
	int k = 3;
	Solution2 s;
	(s.canPartitionKSubsets(v,k))? cout<<"Possible\n":cout<<"Not Possible\n";

	v = {2,1,5,5,6};
	k = 3;
	(s.canPartitionKSubsets(v,k))? cout<<"Possible\n":cout<<"Not Possible\n";

	return 0;
}
