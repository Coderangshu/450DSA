// O(n) is Time complexity
// O(1) is space complexity


#include <bits/stdc++.h>
using namespace std;

void prntVec(vector<int> V){
	for(auto e:V) {cout<<e<<" ";}
	cout<<endl;
}

vector<int> rearrange(vector<int> V){
	int i = 0, j = V.size()-1;
	// cout<<i<<" "<<j;
	while(i<=j){
		if(V[i]>0 && V[j]<0){
			i++;
			j--;
		}
		else if(V[i]<0 && V[j]>0){
			swap(V[i],V[j]);
                        i++;
                        j--;
                }
		else if(V[i]>0 && V[j]>0) {
			i++;
		}
		else if(V[i]<0 && V[j]<0){
			j--;
		}
	}
	// cout<<i<<" "<<j<<endl;
	if(i==0 || i==V.size()) return V;
	int k = 0;
	while(k<V.size() && i<V.size()){
		swap(V[k],V[i]);
		i++;
		k += 2;
	}
	return V;
}

int main(){
	vector<int> V = {-2,3,7,8,4,-1,-3,-8,12,-12,6,-19,-65,-78,65,78,45,-32,4,-1};
	V = rearrange(V);
	prntVec(V);
}
