// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	
	// Using concept of graph, store {num,index} in vector and
	// sort it, this puts the pairs in there sorted position,
	// then using sorted position to its original position
	// (the index in the pair) as a directed edge
	// Notice(imagine) that the pairs will form loops from the sorted to
	// original position and back, each cycle will contain 2 or more
	// nodes in it, so the number of swaps required for each cycle
	// will be: (number of node in it - 1), the summation of all the
	// swaps will give the answer
	// Time: O(nlogn), Space: O(2n)
	
	
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector<pair<int,int>> a;
	    for(int i=0;i<nums.size();i++) a.push_back({nums[i],i});
	    sort(a.begin(),a.end());
	    vector<bool> visited(a.size(),false);
	    int ans = 0;
	    for(int i=0;i<a.size();i++){
	        // if node already visited or present in
	        // sorted index
	        if(visited[i] or a[i].second==i) continue;
	        int countNodes = 0;
	        int nodeInd = i;
	        // while loop not returns back to starting
	        // node continue the loop
	        while(!visited[nodeInd]){
	            visited[nodeInd] = true;
	            countNodes++;
	            // going to the next node in loop
	            nodeInd = a[nodeInd].second;
	        }
	        if(countNodes>0) ans += countNodes-1;
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
