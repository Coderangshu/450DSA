// KMP is used to after concatinating with the same
// string reversed at the beginning with a special
// character in between to distinguish between the
// original and reversed.

#include<bits/stdc++.h>
using namespace std;

// Below is the KMP's lps array formation, for details
// see 19LongestPrefixSuffixKMP.cpp
vector<int> LPS(string s){
	int n = s.length();
	vector<int> lps(n);
	int len = 1,i = 0;
	lps[0] = 0;
	while(len<n){
		if(s[i]==s[len]) lps[len++] = ++i;
		else{
			if(i!=0) i = lps[i-1];
			else lps[len++] = 0;
		}
	}
	for(auto e:lps) cout<<e<<" ";
	cout<<endl;
	return lps;
}

int getMinCharNosToMakePalindrome(string s){
	string revstr = s;
	reverse(revstr.begin(),revstr.end());
	// Example: let string is ABCD, then
	// concat string will be ABCD$DCBA.
	string concat = s+'$'+revstr;
	vector<int> lps = LPS(concat);
	// The last cell of lps contains the
	// maximum length of prefix possible from
	// the given string, thus we substract that
	// number of elements from the length input
	// string to get the longset possible suffix
	// that can be concatinated to make the string
	// palindrome.
	return(s.length()-lps.back());
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		cout<<getMinCharNosToMakePalindrome(s)<<endl;
	}
}
