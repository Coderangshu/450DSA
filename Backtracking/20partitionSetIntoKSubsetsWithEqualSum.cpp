#include<bits/stdc++.h>
using namespace std;

bool isKPartitionPossibleUtil(vector<int> v, vector<int> subsetSum, vector<bool> taken,
		                       int targetSum, int k, int curIdx, int idx){
	int n = v.size();
	// if sum of current subset is targetSum then
	if(subsetSum[curIdx]==targetSum){
		// if curIdx is k-2 i.e. the second last subset then return true
		// as for the last subset the leftover will be targetSum
		if(curIdx==k-2) return true;
		// else proceed to the next subset
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

	// using concept of dp for each element we got
	// choice of either putting in subset or not
	// starting from last element of given set
	subsetSum[0] = v[n-1];
	taken[n-1] = true;

	return isKPartitionPossibleUtil(v,subsetSum,taken,targetSum,k,0,n-1);
}

int main(){
	vector<int> v = {2,1,4,5,3,3};
	int k = 3;
	(isKPartitionPossible(v,k))? cout<<"Possible\n":cout<<"Not Possible\n";

	v = {2,1,5,5,6};
	k = 3;
	(isKPartitionPossible(v,k))? cout<<"Possible\n":cout<<"Not Possible\n";

	return 0;
}
