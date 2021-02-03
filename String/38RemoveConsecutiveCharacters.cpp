// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends







class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        // code here.
        string ans = "";
        ans += S[0];
        int count = 0;
        // cout<<ans.length()<<endl;
        for(int i=1;i<S.length();i++){
            if(S[i]!=ans[count]){
                ans += S[i];
                count++;
            }
        }
        return ans;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 



  // } Driver Code Ends
