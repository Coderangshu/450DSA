// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    bool isPalindrome(string s){
        int n = s.length();
        for(int i=0;i<n/2;i++)
            if(s[i]!=s[n-1-i]) return false;
        return true;
    }
    
    int recursion(string str, int start, int end){
        if(start>=end or isPalindrome(str.substr(start,end-start+1)))
            return 0;
        int totCount = INT_MAX;
        for(int i=start;i<end;i++){
            int cutCount = recursion(str,start,i)+1+recursion(str,i+1,end);
            totCount = min(totCount,cutCount);
        }
        return totCount;
    }

    // Time Complexity: O(n^3)
    int memo[501][501];
    int memoization(string str, int start, int end){
        if(start>=end or isPalindrome(str.substr(start,end-start+1)))
            return memo[start][end] = 0;
        if(memo[start][end]!=-1) return memo[start][end];
        int totCount = INT_MAX;
        for(int i=start;i<end;i++){
            int cutCount = memoization(str,start,i)+1+memoization(str,i+1,end);
            totCount = min(totCount,cutCount);
        }
        return memo[start][end] = totCount;
    }
    
    // Time Complexity: O(n^2)
    // herein the palindrome finding is memoized and min
    // cuts are found in the same loop
    int topDown(string s){
        int n = s.length();
        int minCuts[n];
        bool isPalindrome[n][n] = {false};
        for(int end=0;end<n;end++){
            // in begining assuming count of cuts to be
            // same as the number of letters-1(the max possible
            // cuts)
            int cut = end;
            for(int start=0;start<=end;start++){
                // if start & end chars of string are equal and ((if length is 0 or 1)
                // or string from start+1 to end-1 index is palindrome) then current
                // substring from start to end is also a palindrome
                if(s[start]==s[end] and (end-start<2 or isPalindrome[start+1][end-1])){
                    isPalindrome[start][end] = true;
                    // minimum cut is 0 when start is 0 as only 1 element
                    // from the next iteration the start increases progressively
                    // obtain min cuts upto the last (start-1)'s length of substring
                    // upto the (start-1)'s length from 0 is the substring that has
                    // already been checked and its min cut is stored in minCuts thus
                    // adding another cut to that as a new palindrome has been found
                    // which is to be stored for the current length
                    cut = min(cut,start==0?0:minCuts[start-1]+1);
                }
            }
            minCuts[end] = cut;
        }
        return minCuts[n-1];
    }
    
    int palindromicPartition(string str)
    {
        // code here
        // return recursion(str,0,str.length()-1);
        // memset(memo,-1,sizeof(memo));
        // return memoization(str,0,str.length()-1);
        return topDown(str);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
