#include<bits/stdc++.h>
using namespace std;

// Max sum with no 3 consecutive is an extension of the below procedure


// this is the implementation where no consecutive are in the max sum
int maxSumNoConsecutiveElems(vector<int> &a){
    // incl contains (prev element excluded sum + current element)
	// excl contains max(prev excluded sum, prev included sum)
	
	// NOTICE: incl adds the current element to the prev max sum, excl,
	// just stores the max sum found previously without including the
	// current element in the sum
	int incl = 0, excl = 0;

	for(int i=0;i<a.size();i++){
		// storing the prev incl to be used in excl
		int tincl = incl;
		incl = excl+a[i];
		excl = max(tincl,excl);
	}
	return max(incl,excl);
}

int Max(int a, int b, int c){
    return max(a,max(b,c));
}

int maxSumNo3consecutiveElems(vector<int> &a){
    int n = a.size();
    
    // dp array to store the max at each index
    vector<int> dp(n);
    for(int i=0;i<n;i++){
        if(i==0) dp[i] = a[0];
        else if(i==1) dp[i] = dp[0]+a[1];
        // we take max of sum of 0&1 or 1&2 or 0&2
        else if(i==2) dp[i] = Max(dp[i],a[1]+a[2],a[0]+a[2]);
        // we got 3 options:
        // (I)   exclude a[i]
        // (II)  exclude a[i-1]
        // (III) exclude a[i-2]
        // We have to choose the maximum of the 3
        else dp[i] = Max(dp[i-1],dp[i-2]+a[i],dp[i-3]+a[i-1]+a[i]);
    }
    return dp[n-1];
}

int main(){
	vector<int> a = {5,5,10,40,50,35};

	cout<<maxSumNoConsecutiveElems(a)<<endl;
    cout<<maxSumNo3consecutiveElems(a)<<endl;
	return 0;
}
