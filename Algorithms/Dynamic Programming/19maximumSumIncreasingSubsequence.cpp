// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	
	// here we use the concept of the LIS (longest increasing subsequence)
	// just that the parameter here is the sum instead of the length
	// and as this is to be done in O(n^2) time so we can use the concept
	// of longest common subsequence in this problem
	

	int lcs(int a[], int na,vector<int> b){
	    int nb = b.size();
	    
	    int dp[na+1][nb+1];
	    for(int i=0;i<na+1;i++){
	        for(int j=0;j<nb+1;j++){
	            if(i==0 or j==0) dp[i][j] = 0;
	            else if(a[i-1]==b[j-1]) dp[i][j] = dp[i-1][j-1]+a[i-1];
	            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
	        }
	    }
	    return dp[na][nb];
	}
	
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    // arranging the arr and only keeping the unique numbers
	    set<int>s;
	    for(int i=0;i<n;i++) s.insert(arr[i]);
	    vector<int>sortUniqVec = vector<int>(s.begin(),s.end());
	    
	    // finding longest common sum of sortUniqVec and arr
	    int ans = lcs(arr,n,sortUniqVec);
	    return ans; 
	}  
};

class Solution1{
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<int> lis;
	    for(int i=0;i<n;i++) lis.push_back(arr[i]);
	    int ans = INT_MIN;
	    for(int i=1;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(arr[j]<arr[i] and lis[j]+arr[i]>lis[i]){
	                lis[i] = lis[j]+arr[i];
	                ans = max(ans,lis[i]);
	            }
	        }
	    }
	    return ans;
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";

		Solution1 ob1;
	    cout << ob1.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends
