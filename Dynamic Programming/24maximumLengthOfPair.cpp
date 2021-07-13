#include<bits/stdc++.h>
using namespace std;

// Using Longest Increasing Subsequence concept

int maxChainLength(vector<pair<int,int>> arr){
	int n = arr.size();
	vector<int> len(n,1);
	for(int i=1;i<n;i++)
		for(int j=0;j<i;j++)
			if(arr[j].second<arr[i].first and len[i]<len[j]+1)
				len[i] = len[j]+1;
	return *max_element(len.begin(),len.end());
}

int main(){
	vector<pair<int,int>> arr = {{5, 24},{15, 25},{27, 40},{50, 60}};
    // sorting to get the first of each pair in order
    sort(arr.begin(),arr.end());
    
	cout<<"Length of maximum size chain is "<<maxChainLength(arr);
    return 0;
}
