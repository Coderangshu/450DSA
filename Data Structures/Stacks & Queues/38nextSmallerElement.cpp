#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmaller(vector<int> arr){
	// this stack maintains a decreasing order
	// from top to bottom
	stack<int> stk;
	vector<int> ans(arr.size());
	for(int i=arr.size()-1;i>=0;i--){
		// popping all tops until the top
		// is smaller than the current
		while(!stk.empty() and arr[stk.top()]>=arr[i]) stk.pop();
		ans[i] = (stk.empty())?-1:arr[stk.top()];

		// pushing current element
		stk.push(i);
	}
	return ans;
}

int main()
{
    vector<int> arr = {11,13,10,9,10,21,7,3};
	for(auto e:arr) cout<<e<<" ";
	cout<<endl;
    vector<int> ans = nextSmaller(arr);
	for(auto e:ans) cout<<e<<" ";
	cout<<endl;
    return 0;
}
