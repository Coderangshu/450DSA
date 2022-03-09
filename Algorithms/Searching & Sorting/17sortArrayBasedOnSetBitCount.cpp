#include<bits/stdc++.h>
using namespace std;

int countSetBits(int e){
	int count = 0;
	while(e){
		// turning off the last set bit
		// in each iteration
		e = e&(e-1);
		count++;
	}
	return count;
}

void sortBySetBitCount(vector<int> &a){
	// assuming integer is made of 32 bits
	// we know that sum of set count bits for
	// each integer will be 0-31
	// thus setting up a vector of vector to
	// store each number of each set bit count
	// in there respective vectors in the same
	// order (so as to get the stable sort in
	// result)
	vector<vector<int>> SBC(32);
	for(int i=0;i<a.size();i++){
		int sbc = countSetBits(a[i]);
		SBC[sbc].push_back(a[i]);
	}

	// arranging the numbers in descending order
	// of set bits
	int j = 0;
	for(int i=31;i>=0;i--)
		for(auto e:SBC[i]) a[j++] = e;

}

int main(){
	vector<int> a = {5,2,3,9,4,6,7,15,32}; 
	sortBySetBitCount(a);

	for(auto e:a) cout<<e<<" ";
	cout<<endl;

	return 0;
}
