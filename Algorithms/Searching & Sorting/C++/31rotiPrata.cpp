#include<bits/stdc++.h>
using namespace std;

// function to check if all cook engaged in given time limit
bool allPratasMade(vector<int> cookRating, int p, int timeLimit){
	int time = 0, prata = 0;
	for(int i=0;i<cookRating.size();i++){
		time = cookRating[i];
		 // NOTE: here we do not increment prata # we make the increment
		 // when theres time available upto the making of the next
		 // prata, we can make only # of prata that is allowed in
		 // the given time limit, i.e. the lower bound
		 // For example: if we have 4 as time limit and rating of
		 // cook is 1 then we can make 2 pratas in 1*1+2*1 = 3 units
		 // of time, if we try making the next prata the time goes to
		 // 6 units, thus we need to make prata that is feasible in the
		 // lower bound of the time limit
		int j = 2;
		while(time<=timeLimit){
			// as we are sure we have the time upto the making of the next
			// prata now we increment the prata count made in the time upto
			// now
			prata++;
			time += j*cookRating[i];
			j++;
		}
		if(prata>=p) return true;
	}
	return false;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int p,l;
		cin>>p;
		vector<int> cookRating;
		cin>>l;
		for(int i=0;i<l;i++){
			int e;
			cin>>e;
			cookRating.push_back(e);
		}
		// binary search for min time to get
		// all prata done
		// a cook of rating r can cook n prata
		// in : (r*1)+(r*2)+(r*3)+.......+(r*n)
		// -> r*(1+2+3+...+n) => r*n*(n+1)/2

		// highest possible time will be if slowest cook
		// prepares all the pratas taking the most worst
		// case where p = 1000,
		// time taken = 8*(1000*1001)/2 = 4004000
		int low = 0, high = 4004000, ans = -1;
		while(low<=high){
			int mid = (low+high)>>1;
			// if all pratas are cooked in given time limit
			// then check for lower time limits
			if(allPratasMade(cookRating,p,mid)){
				ans = mid;
				high = mid-1;
			}
			else low = mid+1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
