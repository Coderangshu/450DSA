#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
    int t;
    cin>>t;
    while(t--){
    	string s;
    	cin>>s;
    	int maxFreq = INT_MIN;
    	unordered_map<char,int> mp;
    	// We store the frequencies of all the characters
    	// in the string, we also track the highest frequency
    	// as this needs to be rearranged. Else all the other
    	// characters with frequencies lesser than this will get
    	// rearranged i.e. the string will have the capacity to
    	// rearrange all of them successfully.
    	for(int i=0;i<s.length();i++){
    	    mp[s[i]]++;
    	    if(mp[s[i]]>maxFreq) maxFreq = mp[s[i]];
    	}
    	// When the maximum frequency is lesser than the string length
    	// with the character with highest frequency removed just keeping
    	// one of it in the string. This means that all the characters
    	// can rearrange with the repeating ones to not have any of the
    	// repeating characters together.
    	if(maxFreq<s.length()-maxFreq+1) cout<<1<<endl;
    	else cout<<0<<endl;
    }
	return 0;
}
