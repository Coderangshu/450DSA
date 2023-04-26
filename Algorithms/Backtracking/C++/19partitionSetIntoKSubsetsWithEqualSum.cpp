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
    bool isKPartitionPossibleUtil(vector<int> v, vector<int> subsetSum, vector<bool> taken,
		                       int targetSum, int k, int curIdx, int idx){
        int n = v.size();
        // if sum of current subset is targetSum then
        if(subsetSum[curIdx]==targetSum){
            // if curIdx is k-2 i.e. the second last subset then return true
            // as for the last subset the leftover will be targetSum
            if(curIdx==k-2) return true;
            // else we need to check if the next partition is possible
            // we again start from the first element and put into the next
            // partition if that element hasn't been taken previously
            return isKPartitionPossibleUtil(v,subsetSum,taken,targetSum,k,curIdx+1,n-1);
        }

        // taking each element in v and trying out the two choices
        for(int i=idx;i>=0;i--){
            // if not taken
            if(!taken[i]){
                if(subsetSum[curIdx]+v[i]<=targetSum){
                    // mark this element as taken and add to subset
                    taken[i] = true;
                    subsetSum[curIdx] += v[i];
                    // try out using the next elements
                    bool nxt = isKPartitionPossibleUtil(v,subsetSum,taken,targetSum,k,
                                                        curIdx,i-1);

                    // backtrack
                    taken[i] = false;
                    subsetSum[curIdx] -= v[i];
                    if(nxt) return true;
                }
            }
        }
        // reached here means no arrangement found
        return false;
    }
public:
    bool isKPartitionPossible(vector<int> v, int k){
        // if k is 1 means only one subset is required
        if(k==1) return true;
        // if total number of partitions required are greater
        // than number of intergers available not possible
        int n = v.size();
        if(k>n) return false;

        int totSum = accumulate(v.begin(),v.end(),0);

        // if sum is not divisible into k parts then not possible
        if(totSum%k!=0) return false;

        // sum of each subset
        int targetSum = totSum/k;
        // vector to store the sum of each subset initialized
        // to 0
        vector<int> subsetSum(k,0);

        // vector to keep track of elements taken into
        // different subsets
        vector<bool> taken(n,false);

        return isKPartitionPossibleUtil(v,subsetSum,taken,targetSum,k,0,n-1);
    }
};

// Similar to above (short code + sorting input vector for better performance)
class Solution3 {
private:
    bool recursion(vector<int> &v, int ind, int subsetNo, int curSum, int targetSum, int k, vector<int> &vis){
        int n = v.size();
        
        if(curSum==targetSum){
            if(subsetNo==k-2) return true;
            return recursion(v,0,subsetNo+1,0,targetSum,vis);
        }
        
        for(int i=ind;i<n;i++){
            if(!vis[i] and curSum+v[i]<=targetSum){
                vis[i] = 1;
                if(recursion(v,i+1,subsetNo,curSum+v[i],targetSum,vis)) return true;
                vis[i] = 0;
            }
        }
        return false;
    }
    
public:
    bool isKPartitionPossible(vector<int>& v, int k) {
        int n = v.size();
        if(k>n) return false;
        int sum = accumulate(v.begin(),v.end(),0);
        if(sum%k!=0) return false;
        vector<int> vis(n,0);
        sort(v.begin(),v.end(),greater<int>());
        return recursion(matchsticks,0,0,0,sum/k,k,vis);
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
