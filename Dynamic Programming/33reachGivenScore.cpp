// { Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

 // } Driver Code Ends
// Complete this function
ll count(ll n)
{
    ll availableScores[] = {3,5,10};
    ll asn = sizeof(availableScores)/sizeof(ll);
	ll dp[n+1][asn+1];
	for(ll i=0;i<n+1;i++){
	    for(ll j=0;j<asn+1;j++){
	        if(i==0) dp[i][j] = 1;
	        else if(j==0) dp[i][j] = 0;
	        else if(availableScores[j-1]>i) dp[i][j] = dp[i][j-1];
	        else dp[i][j] = dp[i-availableScores[j-1]][j]+dp[i][j-1];
	    }    
	}
	return dp[n][asn];
}

// { Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}  // } Driver Code Ends
