// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long countWays(int n, int k){
        // code here
        long long int MOD = 1000000007;
        // 2 adjacent same
        long long int p = pow((k-1),(n-2));
        p %= MOD;
        long long int same = (k*p*(n-1));
        same %= MOD;
        // all different
        p = pow((k-1),(n-1));
        p %= MOD;
        long long int diff = (k*p);
        diff %= MOD;
        long long int ans = (same+diff)%MOD;
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
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code End
