// { Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string s)
    {
        // Your code here
        int ans = 0;
        // stack stores the operands
        stack<int> stk;
        for(int i=0;i<s.length();i++){
            char c = s[i];
            if(c>='0' and c<='9') stk.push(c-'0');
            else{
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                if(c=='^') stk.push(pow(b,a));
                else if(c=='/') stk.push(b/a);
                else if(c=='*') stk.push(b*a);
                else if(c=='+') stk.push(b+a);
                else if(c=='-') stk.push(b-a);
            }
        }
        return stk.top();
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
