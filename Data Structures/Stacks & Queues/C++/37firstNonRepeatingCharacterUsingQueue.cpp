// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	
	    // we maintain in the queue such that its front
		// is always the first non repeating character
		// for keeping track of frequency we use a array
		// of 26 letters to store the frequency of each
		// keep pushing the characters into the queue and
		// keep updating the frequency in the freq array
		// whenever the queue's front'a frequency becomes
	    // more than 1 then we pop it
	    
		string FirstNonRepeating(string A){
		    // Code here
		    vector<int> freq(26,0);
		    queue<char> q;
		    string ans = "";
		    for(int i=0;i<A.length();i++){
		        // push char and update frequency
		        q.push(A[i]);
		        freq[A[i]-'a'] += 1;
		        
		        // pop from queue until q is empty
		        // or q.front char's freq is 1
		        while(!q.empty() and freq[q.front()-'a']>1) q.pop();
		        
		        // if q empty then no non repeating character,
		        // else q.front() is the first non repeating
		        // character upto index i
		        ans += q.empty()?'#':q.front();
		    }
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
