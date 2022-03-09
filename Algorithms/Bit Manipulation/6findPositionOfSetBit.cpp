// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    unsigned int Log2n(unsigned int n){
        return (n > 1) ? 1 + Log2n(n / 2) : 0;
    }
     
    int isPowerOfTwo(unsigned n){
        return n && (!(n & (n - 1)));
    }
  
    int findPosition(int N) {
        // code here
        // only one bit will be set only if the number is
        // a power of 2 thus we check that first
        if (!isPowerOfTwo(N))
            return -1;
        // if number is power of 2 we find the log base 2 of the
        // number to get the position of the set bit
        return Log2n(N) + 1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}  // } Driver Code Ends
