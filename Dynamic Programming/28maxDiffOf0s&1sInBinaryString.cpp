	    

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    // Your code goes here
	    
	    // Using Kadane's algorithm
	    int maxSum = INT_MIN;
	    int sumUptillNow = 0;
	    // As asked here no. of 0s - no. of 1s
	    // thus we consider the presence of 1 as
	    // -1 from total and presence of 0 as +1
	    for(int i=0;i<S.length();i++){
	        if(S[i]=='1') sumUptillNow--;
	        else if(S[i]=='0') sumUptillNow++;
	        // if sum uptill now becomes -ev then
	        // reset to 0 as we need to find the max
	        // possible sum
	        if(sumUptillNow<0) sumUptillNow = 0;
	        maxSum = max(maxSum,sumUptillNow);
	    }
	    // if maxSum is 0 means all 1s thus return -1
	    return (maxSum==0)?-1:maxSum;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends
