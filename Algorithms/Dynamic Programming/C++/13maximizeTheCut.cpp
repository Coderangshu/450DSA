// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the maximum number of cuts.
    
    int recursion(int n, int x, int y, int z){
        if(n<=0) return 0;
        int pc1 = (x>n)?INT_MIN:recursion(n-x,x,y,z);
        int pc2 = (y>n)?INT_MIN:recursion(n-y,x,y,z);
        int pc3 = (z>n)?INT_MIN:recursion(n-z,x,y,z);
        return 1+max(pc1,max(pc2,pc3));
    }
    
    int memo[10001];
    int memoization(int n, int x, int y, int z){
        if(n<=0) return memo[n] = 0;
        if(memo[n]!=-1) return memo[n];
        int pc1 = (x>n)?INT_MIN:memoization(n-x,x,y,z);
        int pc2 = (y>n)?INT_MIN:memoization(n-y,x,y,z);
        int pc3 = (z>n)?INT_MIN:memoization(n-z,x,y,z);
        return memo[n] = 1+max(pc1,max(pc2,pc3));
    }
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        // int ans = recursion(n,x,y,z);
        
        memset(memo,-1,sizeof(memo));
        int ans = memoization(n,x,y,z);
        
        if(ans<=0) return 0;
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends
