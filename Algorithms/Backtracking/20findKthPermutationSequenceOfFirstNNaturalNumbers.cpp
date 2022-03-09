#include<bits/stdc++.h>
using namespace std;

// Brute force would be to generate all the permutations using recursion
// sort them and return the k-1 th permutation
// TC : O(n!*n*n!logn!)

// Better approach
// To understand the algorithm, watch https://youtu.be/wT7gcXLYoao
// TC : O(n)
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        int fact = 1;
        for(int i=1;i<n;i++){
            fact *= i;
            nums.push_back(i);
        }
        nums.push_back(n);
        string ans = "";
        k--;
        while(true){
            ans += to_string(nums[k/fact]);
            nums.erase(nums.begin()+k/fact);
            k %= fact;
            int n = nums.size();
            if(n==0) break;
            fact /= n;
        }
        return ans;
    }
};

int main(){
	int n = 3, k = 4;
	Solution obj;
	cout<<obj.getPermutation(n,k)<<endl;
	return 0;
}
