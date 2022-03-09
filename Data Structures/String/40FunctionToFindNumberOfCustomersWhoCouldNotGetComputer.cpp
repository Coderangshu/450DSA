#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,count=0;
		string s;
		cin>>n>>s;
		stack<char> stk;
		char seen[26] = {0};
		int ans = 0, occupied = 0;
		for(int i=0;i<s.length();i++){
			int index = s[i]-'A';
			if(seen[index]==0){
				seen[index] = 1;
				if(occupied<n){
					occupied++;
					seen[index] = 2;
				}
				else ans++;
			}
			else{
				if(seen[index] ==2) occupied--;
				seen[index] = 0;
			}
		}
		cout<<ans<<endl;
	}
}
