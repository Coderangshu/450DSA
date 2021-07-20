// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
  
    // O(N^2) approach
    int minJumps1(int arr[], int n){
        // Your code here
        vector<int> dp(n,INT_MAX);
        for(int i=0;i<n;i++){
            if(i==0) dp[i] = 0;
            else{
                int stepsAvailable = arr[i-1];
                // to keep check when steps available are 0
                // or if the previous cell isn't reachable
                // (contains INT_MAX) then this cell can't
                // be reached from the previous
                if(stepsAvailable==0 or dp[i-1]==INT_MAX) continue;
                else for(int j=0;j<stepsAvailable and i+j<n;j++)
                    dp[i+j] = min(dp[i+j],dp[i-1]+1);
            }
        }
        return ((dp[n-1]==INT_MAX)?-1:dp[n-1]);
    }
    
    
    // O(N) approach
    int minJumps(int arr[], int n){
        // initially when in 1st cell
        int maxReachable = arr[0];
        int stepsAvailable = arr[0];
        
        // if initially steps available is 0
        // can't travel anywhere
        if(stepsAvailable==0) return -1;
        
        // if only 1 cell than 0 jumps required
        if(n==1) return 0;
        
        // here min jumps stores the number of jumps
        // that are to be taken from the current cell
        // thus while in the 1st cell the jump to be 
        // taken is 1
        int minJumpsTaken = 1;
        
        // starting from 2nd cell
        for(int i=1;i<n-1;i++){
            // max reachable from current cell
            maxReachable = max(maxReachable,i+arr[i]);
            // one step advanced inside array thus 1 step
            // has been used up
            stepsAvailable--;
            
            // if steps available is 0, we have tried all
            // possible movements from the one which had given
            // the steps upto the current cell and all in between
            // the current and the steps provider cell
            if(stepsAvailable==0){
                // all movements from the step provider cell
                // are over and now if the max reachable isn't
                // atleast upto the next cell than end is unreachable
                if(maxReachable<=i) return -1;
                
                // All movements from the steps provider
                // cell has been checked now we have the max
                // reachable point updated that is reachable
                // (not reached) after the jumps taken uptill
                // now, now we need to take the next jump to
                // reach the reachable point
                minJumpsTaken++;
                
                // now steps available with us are :
                // max reachable steps - index of current cell
                // this is because we have checked upto the current
                // cell to get the max reachable with the last jump
                // taken
                stepsAvailable = maxReachable-i;
            }
        }
        return minJumpsTaken;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
