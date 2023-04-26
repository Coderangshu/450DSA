// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	// Method: Recursion tree for "ABC" is shown here :
	// https://media.geeksforgeeks.org/wp-content/cdn-uploads/NewPermutation.gif
    private:
        void recursion(string s, int ind, vector<string> &ans){
            int n = s.length();
            if(ind>=n-1){
                ans.push_back(s);
                return;
            }
            for(int i=ind;i<n;i++){
                swap(s[i],s[ind]);
                recursion(s,ind+1,ans);
                swap(s[i],s[ind]);
            }
            return;
        }
	public:
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> ans;
		    recursion(S,0,ans);
		    sort(ans.begin(),ans.end());
		    return ans;
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
