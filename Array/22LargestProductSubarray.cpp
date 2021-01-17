// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends


//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(int *arr, int n) {
	    // code here
	    long long maxPH = arr[0];			// max Product here
	    long long minPH = arr[0];			// min Product here
	    long long maxPSF = arr[0];			// max Product so far
	    long long c1,c2;
	    for(int i=1;i<n;i++){
		    long long ce = arr[i];
		    c1 = maxPH * ce;
		    c2 = minPH * ce;
		    maxPH = max(c1,max(c2,ce));
		    minPH = min(c1,min(c2,ce));
		    maxPSF = max(maxPSF,maxPH);
		    cout<<maxPH<<" "<<minPH<<" "<<maxPSF<<endl;
	    }

	    return maxPSF;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
