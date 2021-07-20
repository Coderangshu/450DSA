// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    
    int recursion(int e, int f){
        // if there are 0 or 1 floor then we need f
        // attempts with the best strategy to find the
        // minimum number of attempts
        if(f==0 or f==1) return f;
        // if only 1 egg then we need to drop it from all
        // floors staarting from the bottom most thus to obtain
        // the worst condition it has to be thrown from all the
        // f floors
        if(e==1) return f;
        // to store the best strategy
        int attempt = INT_MAX;
        for(int i=1;i<=f;i++){
            // to store the attempts in worst condition
            // +1 for the current attempt
            // there are 2 options either egg breaks or 
            // doesn't
            // to get the worst case max is taken
            //         egg : breaks             doesn't breaks
            // total floors 
            //  left to try: 0 to below ith     i+1 to f
            int temp = 1+max(recursion(e-1,i-1),recursion(e,f-i));
            // get the best strategy
            attempt = min(temp,attempt);
        }
        return attempt;
    }
    
    int memo[201][201];
    int memoization(int e, int f){
        if(f==0 or f==1) return memo[e][f] = f;
        if(e==1) return memo[e][f] = f;
        if(memo[e][f]!=-1) return memo[e][f];
        
        int attempt = INT_MAX;
        for(int i=1;i<=f;i++){
            int temp = 1+max(memoization(e-1,i-1),memoization(e,f-i));
            attempt = min(temp,attempt);
        }
        return memo[e][f] = attempt;
    }
    
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
        // return recursion(n,k);
        
        memset(memo,-1,sizeof(memo));
        return memoization(n,k);
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
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
