#include<bits/stdc++.h>
using namespace std;

int findSum(vector<int> arr, int k){
	// using concept of sliding widow
	// once for max and once for min
	// in max dequeue maintain decreasing
	// order of the index in arr inside
	// queue from front to back
	// and in min queue the opposite
	
	deque<int> maxWin, minWin;
	int n = arr.size();
	
	int ans = 0;

	for(int i=0;i<n;i++){
		// if either or both queues are empty, at first
		// both queues are empty
		if(maxWin.empty() or minWin.empty()){
			if(maxWin.empty()) maxWin.push_back(i);
			if(minWin.empty()) minWin.push_back(i);
		}else{
			// maxWin maintains decreasing order thus remove from back all the
			// no's index smaller than current no., thus front always has the
			// largest no's index
			while(!maxWin.empty() and arr[maxWin.back()]<arr[i]) maxWin.pop_back();
			// push the current no's index
			maxWin.push_back(i);
			// minWin maintains increasing order, thus front always has the smallest
			// no's index
			while(!minWin.empty() and arr[minWin.back()]>arr[i]) minWin.pop_back();
			minWin.push_back(i);
		}
		// when i comes to end of the first window and then all the
		// indices make up the window of k length
		if(i+1>=k){
			// remove all the out of window indices
			while(maxWin.front()<=i-k) maxWin.pop_front();
			while(minWin.front()<=i-k) minWin.pop_front();
			// add the min and max of the current window
			// to the answer
			ans += arr[maxWin.front()]+arr[minWin.front()];
		}
	}
	return ans;
}

int main(){
    vector<int> arr = {2, 5, -1, 7, -3, -1, -2} ;
    int k = 3;
    cout << findSum(arr,k);
    return 0;
}
