// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <iostream>
using namespace std;


int minSwap(int *arr, int n, int k);

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        cout << minSwap(arr, n, k) << "\n";
    }
	return 0;
}
// } Driver Code Ends


int minSwap(int *arr, int n, int k) {
    // Complet the function
    int len = 0;
    // We count the number of numbers <=k, this 
    // will be the size of our sliding window.
    for(int i=0;i<n;i++) if(arr[i]<=k) len++;
    // bad is used to store the number of bad 
    // (>k)elements present in the current window.
    int bad = 0;
    for(int i=0;i<len;i++) if(arr[i]>k) bad++;
    // Now the sliding window is slided one by one
    // element first the end is increased by one and
    // checked, if it satisfies ">k" then bad is increased 
    // in the window. Then the beginning of the window is 
    // increased before increasing we check if element is 
    // ">k" then a bad element decreases in the new window 
    // formed after the increment of i.
    int i=0,j = len-1;
    int ms = 9999;
    while(j<n){
        ms = min(ms,bad);
        j++;
        if(arr[j]>k) bad++;
        if(arr[i]>k) bad--;
        i++;
    }
    return ms;
}

