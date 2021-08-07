#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void findSubsetSums(ll arr[], ll start, ll end, vector<ll> &v){
 	ll n = end-start;
	// getting all the 2^n masks
	for(ll mask=0;mask<(1<<n);mask++){
		// getting the subset that each mask
		// represents, by taking the elements
		// whose bits are set in the mask
		// each mask is of n length as we know
		// that 2^n numbers can be represented
		// using n number of bits
		ll sumOfCurrentSubset = 0;
		for(ll j=0;j<n;j++){
			// if the jth bit is set
			// in the mask then include
			// the element in subset
			// here including means add its
			// sum to the sumOfCurrentSubset
			if(mask&(1<<j)) sumOfCurrentSubset += arr[start+j];
		}
		// put the sum of the current subset into v
		v.push_back(sumOfCurrentSubset);
	}
}

// searches for the lower/upper index
ll binarySearch(vector<ll> v, ll se, string ul){
	ll low = 0, high = v.size()-1;
	ll ans = -1;
	while(low<=high){
		ll mid = (low+high)>>1;
		if(ul=="lower"){
			if(v[mid]>=se){
				ans = mid;
                high = mid-1;
			}
			else low = mid+1;
		}
		else{
			if(v[mid]<=se){
				ans = mid;
                low = mid+1;
			}
			else high = mid-1;
		}
	}
	return ans;
}

int main(){
	ll n,a,b;
	cin>>n>>a>>b;
	ll arr[n];
	for(ll i=0;i<n;i++) cin>>arr[i];

	// we divide the input array into 2 parts and
	// find the subset sum of both seprately
	// then we consider all the possible combinations
	// of each and both combined that sum up in the range
	// given using binary search
	
	// the 2 vectors contain all the sums of the powersets
	// of each of the half of the given array
	vector<ll> v1,v2;
	findSubsetSums(arr,0,n/2,v1);
	findSubsetSums(arr,n/2,n,v2);

	// the total subsets of given array is the combination
	// of the two subsets that we divided into above, to
	// find the sum we need to take combinations from each
	// of them and also both combined to get all the sums
	// of the given array's subsets
	// thus we take the smaller subset(to decrease the time
	// complexity) sum vector and using
	// each of its element we search for a number that adds
	// upto a number in the given range
	
	// keeping v1 as smaller vector
	if(v1.size()>v2.size()){
		auto temp = v1;
		v1 = v2;
		v2 = temp;
	}

	// sorting v2 as we will apply binary search in it
	sort(v2.begin(),v2.end());

// 	for(auto e:v2) cout<<e<<" ";
// 	cout<<endl;
	// for each sum in i we create the new range and search for
	// that range in v2, this way we include all combinations with
	// both v1 and v2 as sum and also all the combinations of v2
	// (when v1's sum is 0)
	// count keeps number of subset satisfying condition
	ll count = 0;
	for(ll i=0;i<v1.size();i++){
		// binary search the lower limit
// 		ll low1 = binarySearch(v2,a-v1[i],"lower");
		ll low = lower_bound(v2.begin(),v2.end(),a-v1[i])-v2.begin();
		// binary search the upper limit
// 		ll high1 = binarySearch(v2,b-v1[i],"upper");
		ll high = upper_bound(v2.begin(),v2.end(),b-v1[i])-v2.begin();
// 		cout<<a-v1[i]<<" "<<low1<<" "<<low<<" "<<high1<<" "<<high<<endl;
		count += high-low;
	}
	cout<<count<<endl;

	return 0;
}
