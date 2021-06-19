// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // Function to check if given number n is a power of two.
    
    
    // So, if a number n is a power of 2 then bitwise & of n 
    // and n-1 will be zero. We can say n is a power of 2 or 
    // not based on the value of n&(n-1). The expression n&(n-1) 
    // will not work when n is 0. To handle this case also, our 
    // expression will become n& (!n&(n-1)) 
    bool isPowerOfTwo (long long x)
    {
        /* First x in the below expression is for the case when x is 0 */
        return x and (!(x&(x-1)));
    }
    
    bool isPowerofTwo(long long n){
        
        // Your code here    
        return isPowerOfTwo(n);
    }
};

// { Driver Code Starts.

// Driver code
int main()
{

    int t;
    cin>>t;//testcases

    for(int i=0;i<t;i++)
    {
        long long n; //input a number n
        cin>>n;

        Solution ob;
         if(ob.isPowerofTwo(n))//Now, if log2 produces an integer not decimal then we are sure raising 2 to this value
             cout<<"YES"<<endl;
         else
            cout<<"NO"<<endl;

    }

    return 0;
}
  // } Driver Code Ends
