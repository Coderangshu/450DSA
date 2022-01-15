#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int count0 = 0, count1 = 0, op = 0;
		for(int i=0;i<s.length();i++){
			if(s[i]=='0') count0++;
			else count1++;
			if(count0==count1) op++;
		}
		cout<<op<<endl;
	}
}
