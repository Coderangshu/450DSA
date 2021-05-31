// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	

    void heapify(int arr[], int i, int n){
        if(i>n) return;
        int largest = i;
        int l = 2*i+1;
        int r = 2*i+2;
        if(l<n and arr[l]>arr[largest]) largest = l;
        if(r<n and arr[r]>arr[largest]) largest = r;
        if(largest!=i){
            swap(arr[largest],arr[i]);
            heapify(arr,largest,n);
        }
    }
    
    void buildHeap(int arr[], int size){
        // Last non leaf node
        int lnln = size/2-1;
        for(int i=lnln;i>=0;i--){
            heapify(arr,i,size);
        }
    }
    
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    vector<int> ans;
	    buildHeap(arr,n);
	    for (int i=n-1;i>0 and k>0;i--){
	        k--;
	        ans.push_back(arr[0]);
    		swap(arr[0], arr[i]);
    		heapify(arr,0,i);
    	}
	    return ans;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends
