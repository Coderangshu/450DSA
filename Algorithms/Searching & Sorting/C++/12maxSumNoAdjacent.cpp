// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    
    ll recursion(ll arr[],ll n){
        if(n<=0) return 0;
        return max(arr[n-1]+recursion(arr,n-2),recursion(arr,n-1));
    }
    
    ll memo[10001];
    ll memoization(ll arr[],ll n){
        if(n<=0) return memo[n] = 0;
        if(memo[n]!=-1) return memo[n];
        else return memo[n] = max(arr[n-1]+memoization(arr,n-2),memoization(arr,n-1));
    }
    
    ll FindMaxSum(ll arr[], ll n)
    {
        // Your code here
        // ll ans = recursion(arr,n);
        memset(memo,-1,sizeof(memo));
        ll ans = memoization(arr,n);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		ll n;
		cin>>n;
		ll a[n];
		
		//inserting money of each house in the array
		for(ll i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends
