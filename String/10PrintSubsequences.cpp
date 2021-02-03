#include<bits/stdc++.h>
using namespace std;

void prntSs(string op, int initial, int length, string s){
	if(initial==length) cout<<op<<endl;
	else{
		// For each element we have 2 options either
		// we include it or not include it.
		// Below line is without including
		prntSs(op,initial+1,length,s);
		op += s[initial];
		// Here above we included the current char in our
		// answer and then we go for recursion thus the
		// current char being included in the answers
		// generated below.
		prntSs(op,initial+1,length,s);
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int i=0,n=s.length();
		prntSs("",i,n,s);
	}
}
