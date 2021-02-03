#include<bits/stdc++.h>
using namespace std;

void prntSeq(string s){
	
	// The numeric keypad sequence.
	string str[] = {"2","22","222",                 // ABC
                    "3","33","333",                     // DEF
                    "4","44","444",                     // GHI
                    "5","55","555",                     // JKL
                    "6","66","666",                     // MNO
                    "7","77","777","7777",              // PQRS
                    "8","88","888",                     // TUV
                    "9","99","999","9999"               // WXYZ
                   };
	string o = "";
	for(int i=0;i<s.length();i++){
		// If space is encountered
		if(s[i]==' ') o += '0';
		else o += str[s[i]-'A'];
	}
	cout<<o<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string i;
		cin>>i;
		prntSeq(i);
	}
}
