#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool iscutTreeSumGTEm(vector<ll> th, ll m, ll height){
	ll sum = 0;
	for(auto e:th){
		if(e>height) sum += e-height;
        // if sum of cut parts becomes>=required m
        // return true
        if(sum>=m) return true;
	}
	// no condition satified thus return false
	return false;
}

int main(){
	ll n,m;
	cin>>n>>m;
	vector<ll> treeHeight;
	for(ll i=0;i<n;i++){
		ll e;
		cin>>e;
		treeHeight.push_back(e);
	}

	// we do binary search for the max height (same concept as
	// agressive cow or allocation of pages)
	// getting the search space for the max height
	// which should be set to the max tree height
	ll high = *max_element(treeHeight.begin(),treeHeight.end());

    // low will be 0 as nothing can be cut
	ll low = 0;
	ll ans = -1;
	while(low<=high){
		ll mid = (low+high)>>1;
        // if cut parts add upto m or more than we search
        // with a cut at higher location
		if(iscutTreeSumGTEm(treeHeight,m,mid)){
			ans = mid;
			low = mid+1;
		}
		// if condition not satified then we need to cut
		// somewhere lower
		else high = mid-1;
	}
	cout<<ans<<endl;
	return 0;
}
