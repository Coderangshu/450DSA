// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



#include <bits/stdc++.h>

//User function template for C++
class Solution{
public:
	void merge(int arr1[], int arr2[], int n, int m) {
	    // code here
	    int gap = ceil((m+n)/2.0);
	    do{
	        for(int i=0;i<m+n;i++){
	            int j = i+gap;
	            if(j>=m+n) break;
	            if(i<n && j<n) if(arr1[i]>arr1[j]) swap(arr1[i],arr1[j]);
	            if(i<n && j>=n) if(arr1[i]>arr2[j-n]) swap(arr1[i],arr2[j-n]);
	            if(i>=n &&j>=n) if(arr2[i-n]>arr2[j-n]) swap(arr2[i-n],arr2[j-n]);
	        }
	        gap = (gap/2==0)?0:int(ceil(gap/2.0));
	    }while(gap>0);
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
