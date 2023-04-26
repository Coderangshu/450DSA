#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// linear search on ranges to get the number of the
// particular interval that is the kth smallest
// i stores the index to the last interval in ranges
// as the ones after ith index are not updated redundant
// intervals that were present before merging
ll search(vector<pair<ll,ll>> &ranges, ll i, ll k){
	ll ans = -1;
	for(ll j=0;j<=i;j++){
		// if kth smallest term is in the current
		// interval then return the value
		if(ranges[j].first+k-1<=ranges[j].second){
			ans = ranges[j].first+k-1;
			break;
		}
		// else update k as the interval is skipped all its elements
		// will belong to smaller than the kth element
		else k = k-(ranges[j].second-ranges[j].first+1);
	}
	return ans;
}

int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n,q;
		cin>>n>>q;
		vector<pair<ll,ll>> ranges;
		for(ll i=0;i<n;i++){
			ll a,b;
			cin>>a>>b;
			ranges.push_back({a,b});
		}
		
		// sort the intervals
		sort(ranges.begin(),ranges.end());
		
		// merging the intervals that intersect
		// i stores the current interval index
		ll i = 0;
		// j holds the intervals from next of i
		// (may get updated to further away from i)
		for(ll j=1;j<ranges.size();j++){
			// if current's second >= next's first (intersecting),
			// then current's second is updated to the max of both's second
			if(ranges[i].second>=ranges[j].first)
				ranges[i].second = max(ranges[i].second,ranges[j].second);
			// else not intersecting go to the next index of current
			// and put the j interval in this place
			else{
				i++;
				ranges[i] = ranges[j];
			}
		}
		// now upto ith index is all the merged intervals inside ranges
		// rest of it is the old remaining intervals that are redundant now

		// for(auto p:ranges) cout<<p.first<<" "<<p.second<<endl;

		while(q--){
			ll k;
			cin>>k;
			cout<<search(ranges,i,k)<<endl;
		}
	}
	return 0;
}

