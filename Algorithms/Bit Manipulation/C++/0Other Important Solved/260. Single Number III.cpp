class Solution {
	public:
	vector<int> singleNumber(vector<int>& nums) {
        	long long int xorres = accumulate(nums.begin(),nums.end(),0,bit_xor<int>());
	        xorres &= ~(xorres-1);
		vector<int> ans(2,0);
		for(auto e:nums){
			if((e&xorres)==0) ans[0] ^= e;
			else ans[1] ^= e;
		}
		return ans;
	}
};
