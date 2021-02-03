#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int count = 0, op = 0;
		for(int i=1;i<s.length();i++){
			if(s[i]==s[0]) count++;
			else count--;
			if(count==0) op++;
		}
		cout<<op<<endl;
	}
}
