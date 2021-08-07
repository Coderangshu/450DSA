// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        //code here
        
        
        // NOTE : we handle the subarray sum is 0 and 
        // subarray sum is non zero differently
        
        
        // to keep count of subarrays
        ll count = 0;
        
        // to store {sum,vector of indices}
        unordered_map<ll,vector<ll>> um;
        
        // to keep track of sum upto ith index
        ll sum = 0;
        
        // traversing through arr
        for(int i=0;i<n;i++){
            sum += arr[i];
            um[sum].push_back(i);
            
            // if sum is 0 then we count all the subarrays
            // (notice: when sum is 0 then a single element
            // can also make a sum 0 being 0 itself) thus we
            // count all the subarray sum as 0 indices as
            // a suitable starting point
            if(sum==0) count += um[sum].size();
            // when non 0 then we start counting the starting
            // indices from the 2nd one in the vector as a single
            // element giving a non 0 sum means that single element
            // subarray isn't a non 0 sum subarray, from the 2nd
            // position however the sum becomes same as it has been
            // previously (atleast once when size >2) thus meaning
            // that the in-between elements have cancelled out
            // each other (i.e. index in vector+1 to the current
            // index the subarray sum is 0)
            else if(um[sum].size()>1)
                count += um[sum].size()-1;
        }
        return count;
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}  // } Driver Code Ends
