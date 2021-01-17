// O(n) is the time complexity
// O(1) is the space complexity

#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,max_profit=0;
		cin>>n;
		for(int i=0;i<n;i++){
			int e1,e2;
			if(i==0) cin>>e1;
			else{
				cin>>e2;
				if(e2-e1>0) max_profit += e2-e1;
				e1 = e2;
			}
		}
		cout<<max_profit<<endl;
	}
	return 0;
}
