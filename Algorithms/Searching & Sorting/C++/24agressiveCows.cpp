#include <bits/stdc++.h>
#define ll long long int
using namespace std;



// we do binary search on possible min distances of cows the
// search space consist from 1 to the fathest located stall-1
// i.e. for stalls at locations 1 2 8 4 9, search space is from
// 1 to (9-1) = 8, thus we search taking each distance as the
// min distance from 1-8 and check if we can place all the cows 
// in the stalls if can place then search in the bigger half for
// a larger minimum distance, if not found then search in lower
// half of the possible minimum distance
// see for better explanation : https://www.youtube.com/watch?v=wSOfYesTBRk


// function to check if all cows have been placed with the given min distance
// between each of them
bool allCowsPlaced(vector<ll> &stalls, ll c, ll dist){
	// we place the first cow at the first stall
	// lastCowPlacedAt keeps track of the location where the last cow 
	// was placed in stalls
	ll lastCowPlacedAt = stalls[0], cowPlacedTillNow = 1;
	for(ll i=1;i<stalls.size();i++){
		// if the distance between this stall and the stall of last placed
		// cow is larger than the allowed min distance then we place it
		if(stalls[i]-lastCowPlacedAt>=dist){
			// update this cow's position to the lastCowPlacedAt
			lastCowPlacedAt = stalls[i];
			// incrementing the number of cows placed
			cowPlacedTillNow++;
		}
		// if all cows placed return true
		if(cowPlacedTillNow==c) return true;
	}
	// if reached here means all cows weren't placed
	return false;
}

// does binary search on the possible min distances between all
// the cows
// c is the number of cow that the farmer has
ll getLargestMinDistance(vector<ll> &stalls, ll c){
	sort(stalls.begin(),stalls.end());
		
	ll largestMinDist = -1;
	// lowest min distance can be 1 and the highest can be
	// farthest placed stall - 1
	ll low = 1, high = *(stalls.end()-1)-1;
	while(low<=high){
		ll mid = (low+high)>>1;
		// if all cows placed with the current min distance
		// update the largest min distance and then search 
		// for min distance in the larger half of possible 
		// min distances
		if(allCowsPlaced(stalls,c,mid)){
			largestMinDist = mid;
			low = mid+1;
		}
		// else if all cows not put with the current min distance
		// search in the lower half of possible min distances
		else high = mid-1;
	}
	return largestMinDist;
}

int main() {
	// your code goes here
	ll t;
	cin>>t;
	while(t--){
		ll n,c;
		cin>>n>>c;
		vector<ll> stalls;
		for(ll i=0;i<n;i++){
			ll e;
			cin>>e;
			stalls.push_back(e);
		}
		cout<<getLargestMinDistance(stalls,c)<<endl;
	}
	return 0;
}
