// See the DP-recursion repository for the topdown approach        

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int recursion(string s, int i, int j, int boolean){
        if(i>j) return 0;
        if(i==j){
            if(boolean) return (s[i]=='T')?1:0;
            else return (s[i]=='T')?0:1;
        }
        else{
            int ans = 0;
            // looping through the operators
            for(int k=i+1;k<j;k+=2){
                int lt = recursion(s,i,k-1,1);
                int lf = recursion(s,i,k-1,0);
                int rt = recursion(s,k+1,j,1);
                int rf = recursion(s,k+1,j,0);
                if(s[k]=='&'){
                    if(boolean) ans += lt*rt;
                    else ans += lt*rf+lf*rt+lf*rf;
                }
                else if(s[k]=='|'){
                    if(boolean) ans += lt*rf+lf*rt+lt*rt;
                    else ans += lf*rf;
                }
                else{
                    if(boolean) ans += lf*rt+lt*rf;
                    else ans += lf*rf+lt*rt;
                }
            }
            return ans%1003;
        }
    }
    
    unordered_map<string,int> memo;
    int memoization(string s, int i, int j, int boolean){
        string partialKey = to_string(i)+to_string(j);
        if(i>j)
            return memo[partialKey+to_string(0)] = memo[partialKey+to_string(1)] = 0;
        if(i==j){
            if(boolean) return memo[partialKey+to_string(1)] = (s[i]=='T')?1:0;
            else return memo[partialKey+to_string(0)] = (s[i]=='T')?0:1;
        }
        
        string key = partialKey+to_string(boolean);
        
        if(memo.find(key)!=memo.end()) return memo[key];
        
        int ans = 0;
        // looping through the operators
        for(int k=i+1;k<j;k+=2){
            int lt = memoization(s,i,k-1,1);
            int lf = memoization(s,i,k-1,0);
            int rt = memoization(s,k+1,j,1);
            int rf = memoization(s,k+1,j,0);
            if(s[k]=='&'){
                if(boolean) ans += lt*rt;
                else ans += lt*rf+lf*rt+lf*rf;
            }
            else if(s[k]=='|'){
                if(boolean) ans += lt*rf+lf*rt+lt*rt;
                else ans += lf*rf;
            }
            else{
                if(boolean) ans += lf*rt+lt*rf;
                else ans += lf*rf+lt*rt;
            }
        }
        return memo[key] = ans%1003;
    }
    
    int countWays(int N, string S){
        // code here
        // return recursion(S,0,N-1,1);
        memo.clear();
        return memoization(S,0,N-1,1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
