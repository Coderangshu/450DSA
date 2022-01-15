#include<bits/stdc++.h>
using namespace std;

// not for all negative intergers in nums
int method1(vector<int> &nums){
    int maxNow = 0, maxSoFar = INT_MIN;
    for(auto e:nums){
        maxNow += e;
        if(maxNow<0) maxNow = 0;
        maxSoFar = max(maxSoFar,maxNow);
    }
    return maxSoFar;
}

// functions also when all are -ve
int method2(vector<int> &nums){
    int maxNow = 0, maxSoFar = INT_MIN;
    for(auto e:nums){
        maxNow = max(maxNow+e,e);
        maxSoFar = max(maxSoFar,maxNow);
    }
    return maxSoFar;
}

int main(){
    vector<int> nums = {-2,-3,-4,-1,-2,-1,-5,-3};
    cout<<method2(nums)<<endl;
    return 0;
}