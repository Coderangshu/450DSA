	        

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    sort(arr,arr+n);
	    int ans = 0;
	    for(int i=0;i<n-2;i++){
	        int j=i+1,k=n-1;
	        // i is fixed, j is also fixes being the next smallest
	        // element after i and now we have to fix the kth element
	        while(j<k){
	            if(arr[i]+arr[j]+arr[k]>=sum) k--;
	            else{
	                // we have k-j options for choosing k
	                ans += k-j;
	                j++;
	            }
	        }
	    }
	    return ans;
	}
		 

};

// { Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends
