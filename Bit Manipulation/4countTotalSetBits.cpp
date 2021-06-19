// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    
    
    // see last method of :
    // https://www.geeksforgeeks.org/count-total-set-bits-in-all-numbers-from-1-to-n/
    // to understand the method
    
    
    // function to find the largest power of 2
    // less than the given number
    int findLargestPower(int n)
    {
        int x = 0;
        // here (1<<x) means (2^x)*1
        while ((1 << x) <= n)
            x++;
        return x - 1;
    }
     
    int countSetBits(int n)
    {
        if (n <= 1)
            return n;
        int x = findLargestPower(n);
        return ((x<<(x-1))) + (n - (1<<(x)) + 1) + countSetBits(n - (1<<(x)));
    }

};


// { Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}
  // } Driver Code Ends
