#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
	cin>>t;
	while(t--){
	     int N;
	     cin>>N;
	     vector<int> V;
	     for(int i=0;i<N;i++){
	         int e;
	         cin>>e;
	         V.push_back(e);
	     }
	     for(int i=N-1;i<2*N-1;i++) cout<<V[i%N]<<" ";
	     cout<<endl;
	}
	return 0;
}
