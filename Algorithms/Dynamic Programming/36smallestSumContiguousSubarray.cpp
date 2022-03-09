#include<bits/stdc++.h>
using namespace std;

int smallestSum(int a[], int n){
	int sumNow = a[0], sumSoFar = a[0];
	for(int i=1;i<n;i++){
		sumNow = min(a[i],sumNow+a[i]);
		sumSoFar = min(sumSoFar,sumNow);
	}
	return sumSoFar;
}

int main(){
	int a[] = {3,-4,2,-3,-1,7,5};
	int na = sizeof(a)/sizeof(int);
	int b[] = {2,6,8,1,4};
	int nb = sizeof(b)/sizeof(int);
	cout<<smallestSum(a,na)<<" "<<smallestSum(b,nb)<<endl;
	return 0;
}
