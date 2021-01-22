// Time complexity = O(n)
// where n is length of resultant
// string.
#include <bits/stdc++.h>
using namespace std;

int main(){
	string a,b,c;
	cin>>a>>b>>c;
	int la = a.length();
	int lb = b.length();
	int lc = c.length();
	if(la+lb != lc) cout<<"No"<<endl;
	else{
		int i=0,j=0,k=0;
		while(k<lc){
			if(i<la and a[i]==c[k]) i++;
			else if(j<lb and b[j]==c[k])j++;
			else break;
			k++;
		}
		if(i<la or j<lb) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
}
