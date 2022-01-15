// O(n) is Time complexity
// O(1) is space complexity


#include <bits/stdc++.h>
using namespace std;

void prntVec(vector<int> V){
	for(auto e:V) {cout<<e<<" ";}
	cout<<endl;
}

void rotate(vector<int> &v, int i, int j){
	int temp = v[j];
	for(int k=j;k>i;k--) v[k] = v[k-1];
	v[i] = temp;
}

int getNextInd(vector<int> &v, int ind, bool sign){
	int ans = ind;
	while((v[ans]>=0)!=sign) ans++;
	return (ans>=v.size())?-1:ans;
}

void rearrange(vector<int> &v){
	int n = v.size();
	if(n<=2) return;
	
	// true when +ve in even else false
	bool evenSign;
	if(v[0]>=0) evenSign = true;
	else evenSign = false;

	int i = 0;
	while(i<n){
		if(i%2==0 and (v[i]>=0)!=evenSign){
			int j = getNextInd(v,i+1,evenSign);
			if(j==-1) break;
			rotate(v,i,j);
		}
		else if(i%2!=0 and (v[i]>=0)==evenSign){
			int j = getNextInd(v,i+1,!evenSign);
			if(j==-1) break;
			rotate(v,i,j);
		}
		i++;
	}
}

int main(){
	vector<int> V1 = {2,-3,7,8,4,-1,-3,-8,12,-12,6,-19,-65,-78,65,78,45,-32,4,-1};
	vector<int> V = { -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 };
	rearrange(V1);
	rearrange(V);
	prntVec(V1);
	prntVec(V);
}
