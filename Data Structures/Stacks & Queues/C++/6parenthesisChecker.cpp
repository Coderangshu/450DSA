// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> stk;
        for(auto &c:x){
            if(c=='(' or c=='{' or c=='[') stk.push(c);
            else{
                if(stk.empty()) return false;
                else if(c==')' and stk.top()=='(') stk.pop();
                else if(c=='}' and stk.top()=='{') stk.pop();
                else if(c==']' and stk.top()=='[') stk.pop();
                else return false;
            }
        }
        return stk.empty();
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends
