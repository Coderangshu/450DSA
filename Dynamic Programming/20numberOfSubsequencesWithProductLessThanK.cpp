#include<bits/stdc++.h>
using namespace std;

int prodSubseqCount(vector<int> a, int k){
	int n = a.size();
	int dp[n+1][k+1];

	for(int i=0;i<n+1;i++){
		for(int j=0;j<k+1;j++){
			// if k is 0 than no possible cases
			// if n is 0 than no possible cases
			if(i==0 or j==0) dp[i][j] = 0;
			else{
				// current index will have the previous all the
				// subsequences found in it
				dp[i][j] = dp[i-1][j];
			
				// it will have extra one more subsequence along with all the previous one
				// if current index value is a is less than j
				if(a[i-1]<=j) dp[i][j] += 1+dp[i-1][j/a[i-1]];
			}
		}
	}
	return dp[n][k];
}

int main(){
	vector<int> a = {1,2,3,4};
	int k = 10;
	cout<<prodSubseqCount(a,k);

	return 0;
}
