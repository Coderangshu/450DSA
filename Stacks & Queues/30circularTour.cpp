#include<bits/stdc++.h>
using namespace std;

int getStart(vector<int> dist, vector<int> petrol){
	int n = dist.size();
	// check whether a possible path exists
	// if diff becomes <0 at any point then 
	// the total petrol required to travel the
	// total distance is less thus return -1
	int diff = 0;
	for(int i=0;i<n;i++)
		diff += petrol[i]-dist[i];
	if(diff<0) return -1;

	// find the first city from which travelling
	// to the next is possible
	int i = 0;
	for(;i<n;i++)
		if(petrol[i]>=dist[i]) break;

	// thus feasible starting point is i
	// NOTE: start will store the ans
	int start = i;
	// to store current excess petrol
	int current_petrol = 0;
	for(int i=start;i<n;i++){
		current_petrol += petrol[i]-dist[i];
		
		// if excess petrol at i becomes <0 then
		// we need to check with next city which
		// may be a viable start
		if(current_petrol<0){
			i++;
			for(;i<n;i++)
				if(petrol[i]>=dist[i]){
					start = i;
					// reset current_petrol
					current_petrol = petrol[i]-dist[i];
					break;
				}
		}
		// else we continue to next city as
		// we still have excess current_petrol
		else continue;
	}

	// now we have reached the nth city,
	// current_petrol<0 then cannot reach
	// the next city(1st city)
	if(current_petrol<0) return -1;

	// now we are sure that starting from city start
	// we can reach city n-1, and also have extra
	// petrol and at begining we have checked that
	// is there enough petrol for complete journey.
	// Thus this extra petrol will help to travel
	// from 1st city to start city without running
	// out of fuel, this extra fuel will compensate
	// for the the routes where the fuel would have
	// run out
	
	// thus return start
	return start;
}

int main(){
	vector<int> dist = {4,6,3};
	vector<int> petrol = {6,3,7};

	int start = getStart(dist,petrol);

	(start==-1)?cout<<"No solution":cout<<"Start = "<<start;

	return 0;
}
