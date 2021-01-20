// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function template for C++
class Solution{
public:
	// The binary searcher for the first 1 in a row.
	int onePresent(vector<int> arr,int low, int high){
		if(low <= high){
			int mid = low + (high-low)/2;
			if((mid==0 or arr[mid-1]==0) and arr[mid]==1) return mid;
			else if(arr[mid]==0) return this->onePresent(arr,mid+1,high);
			else return this->onePresent(arr,low,mid-1);
		}
		return -1;
	}
    
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
		// code here
		// We initiate the index of the row with maximum
		// number of 1s as -1 indicating that there is no
		// such row yet.
		int maxRowInd = -1;
		// The location of starting 1 from the first row is
		// found. 
		int max = this->onePresent(arr[0],0,m-1);
		// if there is no 1 in first row we make the index 
		// as the last position, and move on.
		if(max==-1) max = m-1;
		// We check for each row for the leftmost index which
		// has 1 in it.
		for(int i=0;i<n;i++){
			// Until the location of leftmost 1 is greater
			// than 0 we keep decreasing the location value
			// and updating the row index.
			// i.e. for each row we try finding the leftmost
			// 1, which will be returned as the answer, in time
			// complexity is logm + (n+m) which approximates to
			// O(n+m) where n, m are number of
			// row and columns respectively.
			while(max>=0 and arr[i][max]==1){
				max -= 1;
				maxRowInd = i;
			}
		}
		return maxRowInd;
	}
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
