#include <bits/stdc++.h>
using namespace std;
#define d 256
#define ll long long int

// The concept is to use rolling hash, herein
// we calculate the hash value of the given pattern
// then we take the same window size in the search
// string and calculate its hash value if it matches
// then we check each of the characters the window
// and the given pattern, to calculate the hash value
// we use the formulae:
// let partern be A B C, each letter is its corresponding
// number, i.e. A=65, B=66, C=67,......,Z=90 (ASCII values)
// we take a large prime number too(here pn=5381)
// now hash value of ABC is : ((1*256^2)%pn+(2*256^1)%pn+(3*256^0))%pn

void search(string pat, string txt){
	int tl = txt.length(), pl = pat.length();
	// pn is large prime number
	// h = (256^(pl-1))%5381 (i.e. the highest power of
    // 256 that is the highest power that will be multiplied
    // to the starting char value), here for window of size 3
    // h = 256^(3-1) == 256^2
	ll phash = 0,thash = 0, pn = 5381, h = 1;
	bool found = false;
    
    // calculating the hash value of pattern and the first window
    // iterative way of calculating is (for ABC):
    //              only A == oa   = (256*0+66)%pn   = (256^0*66)%pn
    //             A and B == oab  = (256*oa+67)%pn  = ((256^1*66)%pn+(256^0*67)%pn)%pn
    //       A and B and c == oabc = (256*oab+68)%pn = ((256^2*66)%pn+(256^1*67)%pn+(256^0*68)%pn)%pn
	// after the pattern length ends, start removing the first char from the text hash and keep checking
	// if the hash value of the text is equal to the hash value of the pattern
	for(int i=0;i<tl;i++){
		// for evert iteration we add the current char of text to the thash value
        thash = (thash*d + txt[i])%pn;
		// when i < pl, we are calculating the hash value of the pattern and value of h
		if(i<pl){
			phash = (phash*d + pat[i])%pn;
			h = (h*d)%pn;
		}
		// else when i >= pl, we are removing the first char of the text hash
		// adding pn to thash to cover the case when thash goes negative after
		// substraction of the first char of the text which if the largest as
		// it has the highest power of 256 (here d) in the hash value
		else thash = (pn+thash-(txt[i-pl]*h)%pn)%pn;

		// if i>=pn-1 (meaning we consider from the first window of size pn)
		// and if thash == phash, then we have found the pattern
		if(i>=pl-1 and thash==phash){
			// collision check
			int j;
			for(j=0;j<pl;j++) if(txt[i-(pl-1)+j]!=pat[j]) break;
			if(j==pl){
				found = true;
				cout<<"Pattern found at index "<<i-(pl-1)<<endl;
			}
		}
	}
	
	// if pattern not found print not found
	if(!found) cout<<"No match found."<<endl;
}


int main(){
	int t;
	cin>>t;
	while(t--){
		string txt,pat;
		cin>>txt>>pat;
		search(pat, txt);
	}
	return 0;
}
