#include<bits/stdc++.h>
using namespace std;
int main(){
	//code
	int t;
	cin>>t;
	while(t--){
	    stack<int> s;
	    string str;
	    cin>>str;
	    int minReversal = 0;
	    for(int i=0;i<str.length();i++){
	        if(str[i]=='}'){
	            if(!s.empty()) s.pop();
	            else {
	                minReversal++;
	                s.push(str[i]);
	            }
	        }
	        else s.push(str[i]);
	    }
	    if(!s.empty()){
	        if(s.size()%2==0) cout<<minReversal+(s.size()/2)<<endl;
	        else cout<<-1<<endl;
	    }
	    else cout<<minReversal<<endl;
	}
	return 0;
}
