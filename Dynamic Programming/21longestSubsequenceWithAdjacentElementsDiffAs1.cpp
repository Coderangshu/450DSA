// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int longestSubsequence(int N, int A[])
    {
        // code here
        // using the concept of LIS only this time the
        // first criteria isn't only element at ith to be 
        // greater than jth but the abs diff of element 
        // in ith and jth to be 1
        
        vector<int> LIS(N,1);
        for(int i=1;i<N;i++){
            for(int j=0;j<i;j++){
                if(abs(A[i]-A[j])==1 and LIS[i]<LIS[j]+1)
                    LIS[i] = LIS[j]+1;
            }
        }
        return *max_element(LIS.begin(),LIS.end());
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends
