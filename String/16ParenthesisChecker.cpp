// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends





// Function to return if the paranthesis are balanced or not
bool ispar(string x)
{
    // Your code here
    stack<char> s;
    char c;
    for(int i=0;i<x.length();i++){
        if(x[i]=='(' || x[i]=='{' || x[i]=='[') s.push(x[i]);
        else{
            if(s.empty()) return false;
            switch(x[i]){
                case ')':
                    c = s.top();
                    s.pop();
                    if(c=='{' or c=='[') return false;
                    break;
                case '}':
                    c = s.top();
                    s.pop();
                    if(c=='(' or c=='[') return false;
                    break;
                case ']':
                    c = s.top();
                    s.pop();
                    if(c=='{' or c=='(') return false;
                    break;
            }
        }
    }
    // while(!s.empty()){
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }
    return s.empty();
}



// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       if(ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends
