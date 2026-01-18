#include<bits/stdc++.h>
using namespace std;

int method1(vector<int> &nums){
    int maxNow = 0, maxSoFar = INT_MIN;
    for(auto e:nums){
        maxNow += e;
        maxSoFar = max(maxSoFar,maxNow);
        if(maxNow<0) maxNow = 0;
    }
    return maxSoFar;
}

int method2(vector<int> &nums){
    int maxNow = nums[0], maxSoFar = nums[0];
    for(int i=1;i<nums.size();i++){
        maxNow = max(maxNow+nums[i],nums[i]);
        maxSoFar = max(maxSoFar,maxNow);
    }
    return maxSoFar;
}

int main(){
    vector<int> nums = {-2,-3,-4,-1,-2,-1,-5,-3};
    cout<<method2(nums)<<endl;
    return 0;
}