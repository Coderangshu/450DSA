class Solution {
	public:
	int singleNumber(vector<int>& nums) {
		int ans = 0;
	        for(int i=0;i<32;i++){
			int bitSum = 0;
		        for(auto e:nums) bitSum += ((e>>i)&1);
		        if(bitSum%3!=0) ans |= (1<<i);
		}
		return ans;
	}
};
