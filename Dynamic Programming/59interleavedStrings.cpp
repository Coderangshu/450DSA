

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    
    // Time Complexity : O(2^(m+n)) where m is length of a
    // and n is length of b
    bool recursion(string a, string b, string c, int p1, int p2, int p3){
        int la = a.length(), lb = b.length(), lc = c.length();
        
        // base condition
        // if c traversed completely check if both a & b have been
        // traversed completely
        if(lc==p3) return (la==p1 and lb==p2);
        // if a completely traversed check if b's current char matches
        // c's current char then check for further chars of b & c else
        // return false
        if(la==p1) return (b[p2]==c[p3])?recursion(a,b,c,p1,p2+1,p3+1):false;
        // if b completely traversed check if a's current char matches
        // c's current char then check for further chars of a & c else
        // return false
        if(lb==p2) return (a[p1]==c[p3])?recursion(a,b,c,p1+1,p2,p3+1):false;
        
        // if both a & b have chars left then first we check
        // if current of a & c matches or b & c matches if either
        // occurs than return true else false
        // considering that for both condition it will be false
        bool ac = false, bc = false;
        if(a[p1]==c[p3]) ac = recursion(a,b,c,p1+1,p2,p3+1);
        if(b[p2]==c[p3]) bc = recursion(a,b,c,p1,p2+1,p3+1);
        return (ac or bc);
    }
    
    
    // Time Complexity : O(m*n) where m is length of a
    // and n is length of b
    unordered_map<string,bool> memo;
    bool memoization(string a, string b, string c, int p1, int p2, int p3){
        int la = a.length(), lb = b.length(), lc = c.length();
        
        // base condition
        // if c traversed completely check if both a & b have been
        // traversed completely
        if(lc==p3) return (la==p1 and lb==p2);
        
        string key = to_string(p1)+'*'+to_string(p2)+'*'+to_string(p3);
        // check if already processed
        if(memo.find(key)!=memo.end()) return memo[key];
        
        // if a completely traversed check if b's current char matches
        // c's current char then check for further chars of b & c else
        // return false
        if(la==p1) return memo[key] = (b[p2]==c[p3])?memoization(a,b,c,p1,p2+1,p3+1):false;
        // if b completely traversed check if a's current char matches
        // c's current char then check for further chars of a & c else
        // return false
        if(lb==p2) return memo[key] = (a[p1]==c[p3])?memoization(a,b,c,p1+1,p2,p3+1):false;
        
        // if both a & b have chars left then first we check
        // if current of a & c matches or b & c matches if either
        // occurs than return true else false
        // considering that for both condition it will be false
        bool ac = false, bc = false;
        if(a[p1]==c[p3]) ac = memoization(a,b,c,p1+1,p2,p3+1);
        if(b[p2]==c[p3]) bc = memoization(a,b,c,p1,p2+1,p3+1);
        return memo[key] = (ac or bc);
    }
    
    bool isInterleave(string A, string B, string C) 
    {
        //Your code here
        int la = A.length(), lb = B.length(), lc = C.length();
        if(la+lb!=lc) return false;
        // return recursion(A,B,C,0,0,0);
        memo.clear();
        return memoization(A,B,C,0,0,0);
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends
