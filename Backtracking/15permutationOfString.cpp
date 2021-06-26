// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    
	    // Method: Recursion tree for "ABC" is shown here :
	    // https://media.geeksforgeeks.org/wp-content/cdn-uploads/NewPermutation.gif
	    
	    void fpUtil(string s, int index, set<string> &ans){
	        
	        if(index==s.length()) return;
	        
	        ans.insert(s);
	        for(int i=index;i<s.length();i++){
	            swap(s[index],s[i]);
	            fpUtil(s,index+1,ans);
	            swap(s[index],s[i]);
	        }
	    }
	
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    sort(S.begin(),S.end());
		    set<string> ans;
		    fpUtil(S,0,ans);
		    return vector<string>(ans.begin(),ans.end());
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends
