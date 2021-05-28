// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        // code here
        
        // We use a stack inside a map to store the elements of A
        // Then for elements of B we check the order in the map
        // as stack is used the order is reversed which is same
        // as mirror indexing, if any element not matched in
        // sequence implies not a mirror image
        unordered_map<int,stack<int>> mp;
        for(int i=0;i<2*e;i+=2){
            mp[A[i]].push(A[i+1]);
        }
        for(int i=0;i<2*e;i+=2){
            if(mp[B[i]].top()!=B[i+1]) return 0;
            mp[B[i]].pop();
        }
        return 1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        
        cin>>n>>e;
        int A[2*e], B[2*e];
        
        for(int i=0; i<2*e; i++)
            cin>>A[i];
            
        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    }
    return 0;
}  // } Driver Code Ends
