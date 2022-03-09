// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  
    // function returns bool is in the given time limit all
    // painters get assigned all boards
    bool allPaintersAssingedInTimeLimit(int arr[], int n, long long int timeLimit, int k){
        long long int sum = arr[0];
        int painters = 1;
        for(int i=1;i<n;i++){
            if(sum+arr[i]<=timeLimit) sum = (long long int)sum+arr[i];
            else{
                painters++;
                sum = arr[i];
            }
            if(painters>k) return false;
        }
        return true;
    }
  
    long long int minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        // similar to allocated pages to students problem
        
        // we consider min time limit that each painter has
        // for a painter the min time to complete a board is
        // max sized board, and the max time is to complete
        // all boards
        // thus the time limit for each painter can range from
        // the max(board size) to sum(board size)
        // thus we binary search in this space
        
        long long int low = *min_element(arr,arr+n), high = accumulate(arr,arr+n,0), ans = -1; 
        while(low<=high){
            long long int mid = (low+high)>>1;
            if(allPaintersAssingedInTimeLimit(arr,n,mid,k)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends
