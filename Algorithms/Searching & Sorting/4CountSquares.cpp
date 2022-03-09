// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution {
  public:
    int countSquares(int N) {
        // code here
        double n = sqrt(N);
        if(n-int(n)>0) return n;
        else return n-1;
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
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}  // } Driver Code Ends


// Question : Find square root of a given number
class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        long long int l = 1, r = x, ans = 1;
        while(l<=r){
            long long int mid = (l+r)>>1;
            if(mid==x/mid) return mid;
            else if(mid<x/mid){
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }
};