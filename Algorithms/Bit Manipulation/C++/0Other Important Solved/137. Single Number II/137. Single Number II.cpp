#include<bits/stdc++.h>
using namespace std;

 Solution {
	public:
	int singleNumber(vector<int>& nums) {
		int ans = 0;
			// for each of 32  bits take each position
			// add all bits of that position
			// if sum of bits gives remainder when divided with 3
			// means this bit is part of the element appearing once
	        for(int i=0;i<32;i++){
			int bitSum = 0;
		        for(auto e:nums) bitSum += ((e>>i)&1);
		        if(bitSum%3!=0) ans |= (1<<i);
		}
		return ans;
	}
};

// NOTE : We do not need to convert -ve nums to 2s complement when using C++
// they are converted to 2s complement automatically
