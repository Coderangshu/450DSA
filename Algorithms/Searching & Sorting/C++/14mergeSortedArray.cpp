// Easy
// Explanation: https://www.geeksforgeeks.org/merge-two-sorted-arrays-o1-extra-space/
// just swapping the largest of 1st array with smallest of 2nd array whenever we find
// that element at 1st array is larger than 2nd array element when iterated from beginning.

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

    
    
	void merge(int arr1[], int arr2[], int n, int m) {
	    // code here
	    int i=0,k = n-1,j=0,temp;
	    while(i<=k and j<m){
	        if(arr2[j]<arr1[i]) swap(arr1[k--],arr2[j++]);
	        else i++;
	    }
	    sort(arr1,arr1+n);
	    sort(arr2,arr2+m);
	}
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends
