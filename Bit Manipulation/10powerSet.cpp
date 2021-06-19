// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	
	    vector<string> printPowerSet(string set){
	        int set_size = set.length();
            /*set_size of power set of a set with set_size
            n is (2**n -1)*/
            unsigned int pow_set_size = pow(2, set_size);
            int counter, j;
            
            vector<string> ans(pow_set_size,"");
            
            /*Run from counter 000..0 to 111..1*/
            for(counter = 0; counter < pow_set_size; counter++){
                for(j = 0; j < set_size; j++){
                    // Check if jth bit in the counter is set
                    // If set then add jth element from set to
                    // the current string
                    if(counter & (1 << j))
                        ans[counter].push_back((char)set[j]);
                }
                // cout<<endl;
	        }
                
            return ans;
        }
	
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> ans = printPowerSet(s);
		    // To remove the empty set
		    ans.erase(ans.begin());
		    // To order lexicographically
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends
