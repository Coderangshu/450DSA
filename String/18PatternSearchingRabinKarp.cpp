#include <bits/stdc++.h>
using namespace std;
#define d 256

void search(string pat, string txt){
	int tl = txt.length(), pl = pat.length();
	int p=0,t=0, pn=5381,h=1;
	for (int i = 0; i<pl-1; i++) h = (h*d) % pn;
	for(int i=0;i<pl;i++){
		p = (d*p + pat[i])%pn;
		t = (d*t + txt[i])%pn;
	}
	for(int i=0;i<(tl-pl)+1;i++){
		if(p==t){
			int j;
			for(j=0;j<pl;j++) if(txt[i+j]!=pat[j]) break;
			if(j==pl){
				cout<<"Match found at "<<i+1<<endl;
				return;
			}
		}
		if(i<(tl-pl)){
			t = (d*(t-txt[i]*h)+txt[i+pl])%pn;
			if(t<0) t += pn;
		}
	}
	cout<<"No match found."<<endl;
}


int main(){
	int t;
	cin>>t;
	while(t--){
		string txt,pat;
		cin>>txt>>pat;
		search(pat, txt);
		return 0;
	}
}
