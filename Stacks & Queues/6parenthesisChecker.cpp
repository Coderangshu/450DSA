// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    
    // Function to check if top compliments with
    // current bracket
    bool isComp(stack<char> &stk, char a){
        // if stack is empty
        if(stk.empty()) return false;
        
        // if matches
        if(stk.top()==a){
            stk.pop();
            return true;
        }
        return false;
    }
    
    //Function to check if brackets are balanced or not.    
    bool ispar(string x)
    {
        // Your code here
        // insert opening bracks in stack
        // if closing brack then check top is
        // complimentary
        // At end of traversal of string is stack
        // not empty return false
        
        stack<char> stk;
        
        for(int i=0;i<x.length();i++){
            if(x[i]==')'){
                if(!isComp(stk,'('))
                    return false;
            }
            else if(x[i]=='}'){
                if(!isComp(stk,'{'))
                    return false;
            }
            else if(x[i]==']'){
                if(!isComp(stk,'['))
                    return false;
            }
            else if(x[i]=='(' or x[i]=='{' or x[i]=='[')
                stk.push(x[i]);
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
