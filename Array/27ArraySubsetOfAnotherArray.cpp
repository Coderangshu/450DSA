#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    unordered_set<int> s;
	    int n,m;
	    cin>>n>>m;
	    for(int i=0;i<n;i++){
	        int e;
	        cin>>e;
	        s.insert(e);
	    }
	    int flag=1;
	    for(int i=0;i<m;i++){
	        int e;
	        cin>>e;
	        if(s.find(e)==s.end()){
	            flag = 0;
	            break;
	        }
	    }
	    if(flag==0)cout<<"No"<<endl;
	    else cout<<"Yes"<<endl;
	}
	return 0;
}
