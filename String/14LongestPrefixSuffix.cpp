// KMP(Knuth-Morris-Pratt) Algorithm is used here.
// reference video: https://www.youtube.com/watch?v=ziteu2FpYsA

// { Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function template for C++
class Solution{
public:		

		
	int lps(string s)
	{
	    // Your code goes here
	    int n = s.length();
	    int a[n];
	    a[0] = 0;
	    int i=0,j=1;
	    // j keeps on increasing throughout the traversal,
	    // but i keeps jumping according to the conditions.
	    while(j<n){
		// If ith and jth term are equal then both pointer
		// incremented. The value of ith pointer+1 is stored
		// at the jth index of the array.
	        if(s[i]==s[j]) a[j++] = ++i;
		// If i is not equal to 0 then i is updated to the
		// value stored in j's previous index, this means
		// that as the current ith and jth terms did not
		// match so i is sent back to the index where the 
		// last of j's index has seen the longest suffix array.
		// If i reaches 0 this means that the current character
		// at jth index is not a part of the longest suffix found
		// yet, so it stores 0 at the jth index.
	        else{
	            if(i!=0) i = a[i-1];
	            else a[j++] = 0;
	        }
	    }
	    for(int i=0;i<n;i++) cout<<a[i]<<" ";
	    cout<<endl;
	   return a[n-1];
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
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}  // } Driver Code Ends
