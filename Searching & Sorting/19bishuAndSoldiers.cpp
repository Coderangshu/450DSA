#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> a, int p){
	int n = a.size();
	int l = 0, h = n-1, ans = -1;
	while(l<=h){
		int mid = l+(h-l)/2;
		if(a[mid]>p) h = mid-1;
		else{
            ans = mid;
            l = mid+1;
        }
	}
	return ans;
}

int main(){
	int n;
	cin>>n;
	vector<int> solPow(n);
	for(int i=0;i<n;i++){
		int e;
		cin>>e;
		solPow[i] = e;
	}

	sort(solPow.begin(),solPow.end());
	vector<int> sum(n);
	sum[0] = solPow[0];
	for(int i=1;i<n;i++) sum[i] = sum[i-1]+solPow[i];

	// for(auto e:sum) cout<<e<<" ";
	// cout<<endl;

	int q;
	cin>>q;
	while(q--){
		int p;
		cin>>p;
		int index = binarySearch(solPow,p);
		cout<<index+1<<" "<<sum[index]<<endl;
	}
	return 0;
}
