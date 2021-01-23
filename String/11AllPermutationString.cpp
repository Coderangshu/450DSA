#include<bits/stdc++.h>
using namespace std;

void permute(string s,int l, int r, vector<string> &v){
    if(l==r) v.push_back(s);
    else{
        for(int i=l;i<=r;i++){
            swap(s[l],s[i]);
            permute(s,l+1,r,v);
            swap(s[l],s[i]);
        }
    }
}

int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    vector<string> v;
	    int length = s.length();
	    permute(s,0,length-1,v);
	    sort(v.begin(),v.end());
	    for(auto e:v) cout<<e<<" ";
	    cout<<endl;
	}
	return 0;
}
