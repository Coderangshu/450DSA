#include<bits/stdc++.h>
using namespace std;

// function return the largest subarray with
// sum as zero, if no such subarray found
// return 0
int lssz(vector<int> a){
	int ans = 0;

	// calculating all cumulative sums
	// in a
	int sum = 0;
	for(int i=0;i<a.size();i++){
		sum += a[i];
		a[i] = sum;
	}
	
	// map to store the sums that aren't
	// zero
	unordered_map<int,int> mp;
	
	// if a[i] contains 0 means the sum
	// is 0 from begining to i
	// if not 0 then stored in map
	// if non 0 sum already present in
	// map means that this sum has already
	// been achieved previously it comes
	// again means the sum from last time
	// obtained to this index is 0
	for(int i=0;i<a.size();i++){
		if(a[i]==0) ans = max(ans,i+1);
		else if(mp.find(a[i])==mp.end()) mp[a[i]] = i;
		else ans = max(ans,i-mp[a[i]]);
	}
	return ans;
}

// return the area of the largest submatrix
// with sum as 0
// for row 1 find the largest contiguous subarray
// length with sum 0, store in largestArea multiplied
// by height
// for row 1, we add this row to row 0 and find
// longest contiguous subarray length with sum 0,
// store the max in largestArea and so on
int lswsz(vector<vector<int>> a){
	int largestArea = 0;
	int r = a.size(), c = a[0].size();

	for(int i=0;i<r;i++){
		vector<int> cache(c,0);
		for(int j=i;j<r;j++){
			for(int k=0;k<c;k++)cache[k] += a[j][k];
			largestArea = max(largestArea,lssz(cache)*(j-i+1));
		}
	}
	return largestArea;
}

int main(){
	vector<vector<int>> a = {{9, 7,16, 5},
							 {1,-6,-7, 3},
							 {1, 8, 7, 9},
							 {7,-2, 0,10}};

	cout<<lswsz(a)<<endl;
	return 0;
}
