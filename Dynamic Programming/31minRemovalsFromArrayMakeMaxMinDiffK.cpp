#include<bits/stdc++.h>
using namespace std;




// Using Binary search
// O(nlogn)

int binary_search(int a[], int index, int end, int k){
	int key = a[index];
	int start = index+1;
	int reqInd = -1;
	while(start<end){
		int mid = start+(end-start)/2;
		if(a[mid]-a[index]<=k){
			reqInd = mid;
			start = mid+1;
		}
		else end = mid;
	}
	return reqInd;
}

int minRemovalBinarySearch(int a[], int n, int k){
	sort(a,a+n);

	int minRemoval = INT_MAX;
	for(int i=0;i<n-1;i++){
		// find right most index from current index i
		// such that the given condition is fulfilled
		int ind = binary_search(a,i,n-1,k);
		// update the min reomvals required
		if(ind!=-1) minRemoval = min(minRemoval,n-(ind-i+1));
	}
	return minRemoval;
}







// Using DP
// O(n^2)

int memo[101][101];
int memoization(int a[], int start, int end, int k){
	if(start>=end) return 0;
	if(a[end]-a[start]<=k) return 0;
	if(memo[start][end]!=-1) return memo[start][end];
	return memo[start][end] = 1+min(memoization(a,start+1,end,k),
									memoization(a,start,end-1,k));
}

int minRemovalMemoization(int a[], int n, int k){
	sort(a,a+n);

	memset(memo,-1,sizeof(memo));
	return memoization(a,0,n-1,k);
}

int main(){
	int a[] = {9,3,1,4,17,11,12,20,10};
	int n = sizeof(a)/sizeof(int);
	int k = 4;
	cout<<minRemovalMemoization(a,n,k)<<endl;
	cout<<minRemovalBinarySearch(a,n,k)<<endl;
	return 0;
}
