// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

long long recursion(int arr[], int start, int end){
    if(start>=end) return 0;
    return max(arr[start]+min(recursion(arr,start+2,end),recursion(arr,start+1,end-1)),
               arr[end]+min(recursion(arr,start+1,end-1),recursion(arr,start,end-2)));
}

int memo[1001][1001];
long long memoization(int arr[], int start, int end){
    if(start>=end) return memo[start][end] = 0;
    if(memo[start][end]!=-1) return memo[start][end];
    
    // For Player A we have 2 options either take the first or the last
    // When first coin taken:
    //      the other player plays optimally so he picks the max coin
    //      thus A gets to choose the next coin from the minimum of the
    //      2 situations created by B(i.e. B picks first or B picks last)
    // When last coin taken:
    //      the same choices are there for the next round of selection
    //      by A
    
    // From both the above case we need to return the max of both

    return memo[start][end] = max(arr[start]+min(memoization(arr,start+2,end),memoization(arr,start+1,end-1)),
               arr[end]+min(memoization(arr,start+1,end-1),memoization(arr,start,end-2)));
}

//Function to find the maximum possible amount of money we can win.
long long maximumAmount(int arr[], int n) 
{
    // Your code here
    // return recursion(arr,0,n-1);
    memset(memo,-1,sizeof(memo));
    return memoization(arr,0,n-1);
}

// { Driver Code Starts.

int main() {
    
    //taking total testcases
	int T;
	cin>>T;
	while(T--)
	{
	    //taking number of elements
	    int N;
	    cin>>N;
	    
	    int A[N];
	    
	    //inserting the elements
	    for(int i=0;i<N;i++)
	    cin>>A[i];
	    
	    //calling function maximumAmount()
	    cout<<maximumAmount(A,N)<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends
