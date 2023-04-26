// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        
        // stack stores the starting index of all
        // possible valid substring upto the current
        // index, the bottom most index indicates the
        // starting index of the first valid substring
        // in the string.
        // NOTE: All the ')' might not be able to balance 
        // substring to reach upto the bottom most index
        stack<int> stk;
        // as s not traversed yet thus assigning the first
        // valid substring's starting index as -1
        stk.push(-1);
        
        int maxLen = INT_MIN;
        for(int i=0;i<s.length();i++){
            // if '(' indicates the beginning of another
            // valid substring starting from this index
            if(s[i]=='(') stk.push(i);
            // when ')' then we pop
            
            // I : if the top was '(' then we balance it by removing
            // and getting the diff of i and stk.top() which gives
            // us the length of a valid substring
            
            // II : if top was ')' means stk.top() was assumed as the
            // begining of VS(valid substring), but now as we got
            // another ')' this makes the new ')' index as the begining
            // of VS this marks the begining of a new VS there will
            // be no previous starting index of any VS
            
            // III : if top is -1 means 0 is the starting of VS
            
            // IV : if stack is empty then the current index will signify
            // the begining of a new VS
            
            // Case I will be the most occuring case
            else{
                stk.pop();
                if(!stk.empty()) maxLen = max(maxLen,i-stk.top());
                else stk.push(i);
            }
        }
        return (maxLen==INT_MIN)?0:maxLen;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}
  // } Driver Code Ends
