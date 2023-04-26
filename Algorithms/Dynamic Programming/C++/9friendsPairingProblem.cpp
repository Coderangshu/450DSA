// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:

    // f(n) = ways n people can remain single or pair up.

    // For n-th person there are two choices:
    // 1) n-th person remains single, we recur for f(n - 1)
    // 2) n-th person pairs up with any of the remaining n - 1 persons.
    //    We get (n - 1) * f(n - 2)
    
    // Therefore we can recursively write f(n) as:
    // f(n) = f(n - 1) + (n - 1) * f(n - 2)

    int countFriendsPairingsUtil(int n){
        long long int dp[n+1];
        for(int i=0;i<n+1;i++){
            if(i<3) dp[i] = i;
            else dp[i] = (dp[i-1]+(i-1)*dp[i-2])%1000000007;
        }
        return dp[n];
    }
    
    // Space: O(n)
    // int countFriendsPairings(int n) 
    // { 
    //     int ans = countFriendsPairingsUtil(n);
    //     return ans;
    // }
    
    // Space: O(1)
    int countFriendsPairings(int n)
    {
        // f(1) = a = 1
        // f(2) = b = 2
        // using this two we progress using the above formulae
        // and storing f(3) in c and so on shifting a,b,c each time
        long long int a = 1, b = 2, c;
        if (n <= 2) {
            return n;
        }
        for (int i = 3; i <= n; i++) {
            c = (b + (i - 1) * a)%1000000007;
            a = b;
            b = c;
        }
        return c;
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
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends
