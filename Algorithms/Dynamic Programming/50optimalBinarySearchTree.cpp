#include<bits/stdc++.h>
using namespace std;

// Concept used is Matrix Chain Multiplication
// we try each element as the root, and the left
// is sent as left subtree and right of root
// is sent as the right subtree
int recursion(int freq[], int start, int end){
	if(start>end) return 0;
	if(start==end) return freq[start];
	
	// as all the elements from start to end are
	// being considered in this call thus all of
	// them from start to end will contribute 
	// once to the search time
	int sum_freq = 0;
	for(int i=start;i<=end;i++) sum_freq += freq[i];

	// find the min search time for all the combinations
	// of left and right subtree with all the nodes being
	// the root once
	int minOfLRChild = INT_MAX;

	// considering each of the elements as root from start
	// to end
	for(int root=start;root<=end;root++)
		minOfLRChild = min(minOfLRChild,
				recursion(freq,start,root-1)+recursion(freq,root+1,end));

	// return that combination of root-left subtree-right subtree
	// such that the search time is the min
	return sum_freq+minOfLRChild;
}

int main(){
	int keys[] = {10,12,20};
	int freq[] = {34,8,50};

	int n = sizeof(keys)/sizeof(int);

	cout<<recursion(freq,0,n-1);

	return 0;
}
