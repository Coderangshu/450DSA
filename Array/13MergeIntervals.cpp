#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> newv;
        vector<int> v=intervals[0];
        int i=0;
        for(auto V:intervals){
            if(V[0]<=v[1]){
                v[1] = max(v[1],V[1]);
            }else{
                newv.push_back(v);
                v = V;
            }
        }
        newv.push_back(v);
        return newv;
    }
};

// Problem in driver code yet Solution class works perfectly
int main(){
  int t,N;
  vector<vector<int>> V;
	cin>>t;
	while(t--){
		cin>>N;
		for(int i=0;i<N;i++){
      vector<int> v;
      for(int j=0;j<2;j++){
  			int e;
  			cin>>e;
  			v.push_back(e);
		  }
      V.push_back(v);
    }
		Solution obj;
    vector<vector<int>> V = obj.merge(V);
    for(int i=0;i<N;i++) for(int j=0;j<2;j++) cout<<V[i][0]<<" ";
	}
  cout<<endl;
}
