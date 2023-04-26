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

class Solution_recursive{
    private:
    string recurse(string s, string sa, int ind){
        int n = s.length();
        if(ind>=n) return sa;
        if(sa.back()==s[ind]) return recurse(s,sa,ind+1);
        return recurse(s,sa+s[ind],ind+1);
    }
    
    public:
    string removeConsecutiveCharacter(string S)
    {
        // code here.
        string s = S.substr(0,1);
        string ans = recurse(S,s,1);
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
        Solution_recursive ob_rec;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
        cout<<ob_rec.removeConsecutiveCharacter(s)<<endl;
    }
} 



  // } Driver Code Ends
