#include<bits/stdc++.h>
using namespace std;

void prntSs(string op, int initial, int length, string s){
	if(initial==length) cout<<op<<endl;
	else{
		prntSs(op,initial+1,length,s);
		op += s[initial];
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
