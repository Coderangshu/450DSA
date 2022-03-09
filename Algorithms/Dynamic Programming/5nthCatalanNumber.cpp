// { Driver Code Starts
//Initial template for C++

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;  // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    
    // Catalan series:  1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …  
    // Formulae to get the series: C0 = 0, C(N+1) = sum0ToN(Ci*C(N-i))
    
    
    //Function to find the nth catalan number.
    
    cpp_int nthCatalan(int n){
       vector<cpp_int> dp(n+1,0);
       
       for(int i=0;i<n+1;i++){
           if(i==0 or i==1) dp[i] = 1;
           else{
               for(int j=0;j<i;j++)
                   dp[i] += dp[j]*dp[i-j-1];
           }   
       }   
       return dp[n];
    }   

    
    cpp_int findCatalan(int n) 
    {
        //code here
        cpp_int ans = nthCatalan(n);
        return ans;
    }
};

// { Driver Code Starts.

int main() 
{
    //taking count of testcases
	int t;
	cin>>t;
	while(t--) {
	    
	    //taking nth number
	    int n;
	    cin>>n;
	    Solution obj;
	    //calling function findCatalan function
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}  // } Driver Code Ends
