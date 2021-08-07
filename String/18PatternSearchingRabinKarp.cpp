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
// the approach is like (log base 256)

// recursive function to calculate power in (log n) time
// calculates power of d (i.e. 256)
ll powCal(int exp){
    if(exp==0) return 1;
    if(exp==1) return d;
    
    ll ans = 1;
    ll powNxt = powCal(exp/2);
    
    // if exp is odd
    if(exp&1) return powNxt*powNxt*d;
    // else if even
    else return powNxt*powNxt;
}



void search(string pat, string txt){
	int tl = txt.length(), pl = pat.length();
	int p=0,t=0, pn=5381;
    
    // h = (256^(pl-1))%5381 (i.e. the highest power of
    // 256 that is the highest power that will be multiplied
    // to the starting char value), here for window of size 3
    // h = 256^(3-1) == 256^2
    ll h = powCal(pl-1);
    
    // calculating the hash value of pattern and the first window
    // iterative way of calculating is (for ABC):
    //              only A == oa   = (256*0+66)%pn   = (256^0*66)%pn
    //             A and B == oab  = (256*oa+67)%pn  = ((256^1*66)%pn+(256^0*67)%pn)%pn
    //       A and B and c == oabc = (256*oab+68)%pn = ((256^2*66)%pn+(256^1*67)%pn+(256^0*68)%pn)%pn
	for(int i=0;i<pl;i++){
		p = (d*p + pat[i])%pn;
		t = (d*t + txt[i])%pn;
	}
	
	// iterating from 0 to the last window's 
	// starting index in the given text
	for(int i=0;i<(tl-pl)+1;i++){
        // if both hash values match
		if(p==t){
			int j;
            // checking each character if not same break
			for(j=0;j<pl;j++) if(txt[i+j]!=pat[j]) break;
            
            // if whole pattern traversed then return match found
			if(j==pl){
				cout<<"Match found at "<<i+1<<endl;
				return;
			}
		}
		
		// rolling the hash value(the previous char's value subtracted
		// from hash and next char's hash value added to the txt's, thus
		// rolling forward the window by 1 char) 
		// if i is less than the possible starting indices of the window
		if(i<(tl-pl)){
            // 256*(prevHash-(first of window)*h) + nextCharHash
			t = (d*(t-txt[i]*h)+txt[i+pl])%pn;
            // NOTE: notice that if after subtracting the big number and
            // adding the small one if the resultant is -ve than we balance
            // it by adding pn (5381) to it, the extra added gets nullified
            // when the hash value gets mod by pn next time
			if(t<0) t += pn;
		}
	}
	
	// if reached here then pattern not found
	cout<<"No match found."<<endl;
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
