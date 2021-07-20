#include<bits/stdc++.h>
using namespace std;


// Method : Same as previous consider the 0s as -1s
// while finding the sum



// function return the largest subarray with
// sum as zero, if no such subarray found
// return 0
int lssz(vector<int> a){
	int ans = 0;

	// calculating all sums in a
	int sum = 0;
	for(int i=0;i<a.size();i++){
		sum += a[i];
		a[i] = sum;
	}
	
	// map to store the sums that aren't
	// zero
	unordered_map<int,int> mp;
	for(int i=0;i<a.size();i++){
		if(a[i]==0) ans = max(ans,i+1);
		else if(mp.find(a[i])==mp.end()) mp[a[i]] = i;
		else ans = max(ans,i-mp[a[i]]);
	}
	return ans;
}

// return the area of the largest submatrix
// with sum as 0
int lswsz(vector<vector<int>> a){
	int largestArea = 0;
	int r = a.size(), c = a[0].size();

	for(int i=0;i<r;i++){
		vector<int> cache(c,0);
		for(int j=i;j<r;j++){
			for(int k=0;k<c;k++)cache[k] += (a[j][k]==0)?-1:1;
			largestArea = max(largestArea,lssz(cache)*(j-i+1));
		}
	}
	return largestArea;
}

int main(){
	vector<vector<int>> a = {{0,0,1,1},
                             {0,1,1,0},
                             {1,1,1,0},
							 {1,0,0,1}};
	cout<<lswsz(a)<<endl;
	return 0;
}
