// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    
        // function to check if for a number's factorial
        // has more than n trailing 0s
        // to get the trailing 0s count # of 5s in prime factorial
        // of number!, as # of 2s in a prime factorial of a number is
        // always >= # of 5s, thus we only need to count the # of 5s
        // formula to get # of 5s in number!:
        // floor(number/5)+floor(number/25)+floor(number/125)+floor(number/625)+......
        // until divisor <= number
        bool isCountOfTrailing0GTn(int number, int n){
            int div = 5, count = 0;
            while(div<=number){
                count += number/div;
                div *= 5;
            }
            return (count>=n);
        }
    
        int findNum(int n){
            //complete the function here
            // if only 1 trailing factorial is asked for
            // then we know 5! is 120 thus 5 is the min
            // number with factorial having 1 trailing 0
            if(n==1) return 5;
            
            // NOTE: maximum value whose factorial contain n trailing zeroes is 5*n
            // this is obtained from the top explained statement
            
            // thus we binary search from 0 to 5n for the smallest # that gives n 
            // trailing 0s
            int low = 0, high = 5*n;
            int ans = -1;
            while(low<=high){
                int mid = (low+high)>>1;
                if(isCountOfTrailing0GTn(mid,n)){
                    ans = mid;
                    // search for the more smaller number
                    // (if present)
                    high = mid-1;
                }
                else low = mid+1;
            }
            return ans;
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends
