class Solution
	public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	// we traverse through the time space of the day
    	// and assign a platform to arriving and take away
    	// a platform from a departing train
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	// we use 2 pointers to keep track of all the trains
    	// 1 for arriving ones other for departing ones
    	
    	// initially the first train arrived is already in
    	// a platform, thus for arrival we start from the second
    	// train
    	// initially the first train is in platform and not departed
    	// thus point to the first departing time
    	// as 1 train is in the platform thus 1 platfrom is occupied
    	int platOccupied = 1, maxPlatsReq = 1;
    	int arrTimePntr = 1, depTimePntr = 0;
    	
    	// traversing through the time space of the day
    	while(arrTimePntr<n and depTimePntr<n){
    	    // if arrival of next train is prior or equal to departure
    	    // time of the prev train then another platform required
    	    if(arr[arrTimePntr]<=dep[depTimePntr]){
    	        platOccupied++;
    	        // point to next train arrival time
    	        arrTimePntr++;
    	    }
    	    // else if next train arrival time is later to last
    	    // train departure then the occupied platform is released
    	    // for the next train
    	    // NOTE: here we donot put up the next train at this platform
    	    // in this iteration first we take up the next train departure
    	    // time and check if that with the above and below conditions
    	    // and then do the necessary
    	    else if(arr[arrTimePntr]>dep[depTimePntr]){
    	        platOccupied--;
    	        depTimePntr++;
    	    }
    	    // update the max occupied platforms till now
    	    maxPlatsReq = max(maxPlatsReq,platOccupied);
    	}
    	return maxPlatsReq;
    }
};
