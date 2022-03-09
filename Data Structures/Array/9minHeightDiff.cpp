// Question
/* Given an array arr[] denoting heights of N towers and a positive integer K.

For each tower, you must perform exactly one of the following operations exactly once.

    Increase the height of the tower by K
    Decrease the height of the tower by K

Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.

You can find a slight modification of the problem here.
Note: It is compulsory to increase or decrease the height by K for each tower. After the operation, the resultant array should not contain any negative integers.
*/


// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends





//User function template for C++

// Brute force : DFS (either +k or -k at every indices) --> TC : O(2^n) SC : O(n)
// 1st optimization : create partition at every point +k on left and -k on right part
//                    get max and min then get diff and store the min diff --> TC : O(n^2) SC : O(n)
// 2nd optimization : --> TC : O(nlogn) SC : O(n)
class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr,arr+n);
        // increase some of the first # in sorted array and decrease the
        // rest, at some division the diff between the max and min would
        // be minimized, thus create partition at every point to get the 
        // max and min and store the min diff and return
        // To get the max and min at each division:
        // For the left part +k is done, for right -k is done
        // so there will be 2 choices of min and max at each iteration
        // understand with example of array of size 12
        // [a b c d e f g h i j k l] --> considering this state is after sorting
        // taking partition at random position i=4 in the above
        // [a b c d | e f g h i j k l]
        // +k in left and -k in right to minimize the diff of max and min in array
        // [a+k b+k c+k d+k | e-k f-k g-k h-k i-k j-k k-k l-k]
        // now the min could be a+k or e-k --> we take min of both min(arr[0]+k,arr[i]-k)
        // max could be l-k or d+k --> taking max of both max(arr[n-1]-k,arr[i-1]+k)
        // getting the diff and storing the min diff
        int ans = (arr[n-1]-k)-(arr[0]+k);
        int mx = arr[n-1], mn = arr[0];
        for(int i=1;i<n;i++){
            mx = max(arr[n-1]-k,arr[i-1]+k);
            mn = min(arr[0]+k,arr[i]-k);
            ans = min(ans,mx-mn);
        }
        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
