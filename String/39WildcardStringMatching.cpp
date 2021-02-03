#include<bits/stdc++.h>
using namespace std;

int memo[10001][10001];

int memoisation(string p, string s,int pi, int si){
    // First we check through the base cases:
    // Case 1:
    // If both pattern and string indexes are -1,
    // means that we have reached the end of both
    // of them.
    if(pi==-1 and si==-1) return 1;
    // Case 2:
    // When only string has ended
    if(si==-1){
        // We traverse the pattern to the end
        // we encounter something other than 
        // * then the pattern is not a correct
        // match
        while(pi>-1) if(p[pi--]!='*') return 0;
        return 1;
    }
    // Case 3:
    // If pattern finishes before string then it isn't
    // a correct match
    if(pi==-1) return 0;
    // Now we do recursion and store the values in the memo
    // Checking if value is already present in the memo
    if(memo[pi][si]!=-1) return memo[pi][si];
    // When value isn't present in the memo
    // If both characters at both pi and si indexes of pattern and string are same
    // or pattern has a '?', then store the value in memo and go to previous index
    // for both of them
    if(p[pi]==s[si] or p[pi]=='?') return memo[pi][si] = memoisation(p,s,pi-1,si-1);
    // If pattern has '*' in its current index
    if(p[pi]=='*') {
        // We take both situations in one we go to the previous index of pattern
        // in other we go to the previous index of the string whichever gives true
        // that is stored in the current index of the memo
        int patternInclude = memoisation(p,s,pi-1,si);
        int stringInclude = memoisation(p,s,pi,si-1);
        return memo[pi][si] = patternInclude or stringInclude;
    }
    // When both characters don't match
    return memo[pi][si] = 0;
}

int main()
 {
	//code
    int t;
    cin>>t;
    while(t--){
    	string p,s;
    	cin>>p>>s;
    	memset(memo,-1,sizeof(memo));
    	int ans = memoisation(p,s,p.length()-1,s.length()-1);
    	if(ans==1)cout<<"Yes"<<endl;
    	else cout<<"No"<<endl;
    }
	return 0;
}
