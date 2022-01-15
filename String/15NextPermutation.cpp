// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        // next_permutation(nums.begin(),nums.end());
        if(N<=1) return arr;
        int i = N-2;
        // Traverse from back to get the break point.
        while(i>=0 && arr[i]>=arr[i+1]) i--;
        if(i>=0){
            int j = N-1;
            // Traverse from back again to get the 
            // number just greater than the number at
            // the breakpoint.
            while(arr[j]<=arr[i]) j--;
            // swapped to make the just bigger permute.
            swap(arr[i],arr[j]);
        }
        // As all the number next to ith are in descending
        // order, reverse it to get the most smallest 
        // permute possible just greater than the last.
        // This gives the next permutation. 
        reverse(arr.begin()+i+1,arr.end());
        return arr;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends
