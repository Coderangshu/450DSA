// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long countWays(int n, int k){
        // code here
        long long int MOD = 1e9 + 7;
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

    // DP implementation
    long long countWays1(int n, int k){
        vector<int> same(n,0), diff(n,0), tot(n,0);
        // here 1 means 2 fences, 2 means 3 fences so on...
        same[1] = k;
        diff[1] = k*(k-1);
        tot[1] = same[1]+diff[1];

        for(int i=2;i<n;i++){
            // for same take the diff upto last fence and color
            // the new fence with the last fence's color
            same[i] = diff[i-1];
            // for diff take the total ways upto last fence and ways to color
            // the new fence is (k-1) thus multiply both
            diff[i] = tot[i-1]*(k-1);
            tot[i] = same[i]+diff[i];
        }
        return tot[n-1];
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
        cout<<ob.countWays1(n,k)<<endl;
	}
	return 0;
}  // } Driver Code End
