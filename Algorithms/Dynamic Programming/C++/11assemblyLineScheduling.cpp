#include<bits/stdc++.h>
using namespace std;

// Here using 2 vectors of n length to store the time taken in
// each stations for both lines. To further optimize the space
// complexity can use 2 variables instead to store the last
// station's time taken


int minTime(vector<int> a[], vector<int> t[], vector<int> e, vector<int> x){

	// length of assembly line
	int n = a[0].size();

	// taking 2 vectors to store the min time taken in each station of 
	// both lines
	vector<int> tm1(n), tm2(n);

	// fill all in tm1 and tm2
	for(int i=0;i<n;i++){
		// for entry and time taken in first node there 
		// is no option for both assembly lines
		if(i==0){
			tm1[i] = e[0]+a[0][i];
			tm2[i] = e[1]+a[1][i];
		}
		// for the rest we have choice either chasis comes from
		// line 1 or 2 we take the minimum time of the both
		else{
			// for each time taken in each or time taken in the
			// other plus time taken to transfer to current line
			// plus the time to be taken in the current station
			tm1[i] = min(tm1[i-1],tm2[i-1]+t[1][i])+a[0][i];
			tm2[i] = min(tm2[i-1],tm1[i-1]+t[0][i])+a[1][i];
		}
	}
	return min(tm1[n-1]+x[0],tm2[n-1]+x[1]);
}
	
int main(){
	vector<int> a[2];
	vector<int> t[2];
	a[0] = {4,5,3,2};
	a[1] = {2,10,1,4};
	t[0] = {0,7,4,5};
	t[1] = {0,9,2,8};

	vector<int> e = {10,12}, x = {18,7};

	int ans = minTime(a,t,e,x);
	cout<<ans<<endl;

	return 0;
}
