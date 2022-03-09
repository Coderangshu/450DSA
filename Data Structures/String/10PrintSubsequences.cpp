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

void bitmasking(string s){
	int n = s.length();
	for(int i=1;i<1<<n;i++){
		string op = "";
		for(int j=0;j<n;j++) if(i&(1<<j)) op += s[j];
		cout<<op<<endl;
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
		cout<<endl;
		bitmasking(s);
	}
}
