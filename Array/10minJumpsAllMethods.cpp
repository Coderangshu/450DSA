// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends





// Function to return minimum number of jumps to end of array

// Top Down brute force recursion approach. Takes O(k^n),where
// k is the largest element in the array and n is the length.
// A tree of k branches with n nodes in each is formed.
int topDownApproach(int arr[],int lenArr,int initialIndex){
    if(initialIndex>=lenArr) return INT_MAX;
    if(initialIndex==lenArr-1) return 0;
    int steps_available = arr[initialIndex];
    int minJumps = INT_MAX;
    for(int i=1;i<=steps_available;i++)
        minJumps = min(minJumps,topDownApproach(arr,lenArr,initialIndex+i));
    // For each time we enter the function a single jump is always taken.
    return minJumps+1;
}

// Time complexity is lesser than Top Down as we store the repeating values 
// in the memo.
int memo[100];

int memoization(int arr[],int lenArr,int initialIndex){
    if(memo[initialIndex]>0) return memo[initialIndex];
    if(initialIndex>=lenArr) return INT_MAX;
    if(initialIndex==lenArr-1) return 0;
    int steps_available = arr[initialIndex];
    int minJumps = INT_MAX;
    for(int i=1;i<=steps_available;i++)
        minJumps = min(minJumps,memoization(arr,lenArr,initialIndex+i));
    memo[initialIndex] = minJumps+1;
    return memo[initialIndex];
}

int DP(int arr[],int lenArr){
    // The number of jumps needed to reach the starting index is 0 
    if (lenArr <= 1) return 0;
    // Return -1 if not possible to jump 
    if (arr[0] == 0) return -1;
    // initialization 
    int maxReach = arr[0];  // stores all time the maximal reachable index in the array. 
    int step = arr[0];      // stores the number of steps we can still take 
    int jump =1;//stores the number of jumps necessary to reach that maximal reachable position.
    // Start traversing array
    for (int i = 1; i < lenArr; i++){ 
        // Check if we have reached the end of the array 
        if (i == lenArr-1) return jump;
        // updating maxReach 
        maxReach = max(maxReach, i+arr[i]); 
        // we use a step to get to the current index 
        step--;
        // If no further steps left 
        if (step == 0){ 
            // we must have used a jump 
            jump++;
            // Check if the current index/position or lesser index 
            // is the maximum reach point from the previous indexes 
            if(i >= maxReach) return -1;
            // re-initialize the steps to the amount 
            // of steps to reach maxReach from position i. 
            step = maxReach - i; 
        } 
    }
    return -1; 
}

int minJumps(int arr[], int n){
    // Your code here
    return DP(arr,n);
}



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
            
        cout<<minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
