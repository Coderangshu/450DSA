//questionn : https://leetcode.com/problems/minimize-deviation-in-array/description/

#include <bits/stdc++.h>
using namespace std;

// increase all odds to even and add all nos to max heap
// keep track of min while doing so
// pop each from heap and check if (top-min) is minimum
// update min with top/2 and push top/2 to max heap
// continue until top is odd
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int mn = INT_MAX;
        priority_queue<int> pq;
        for(auto &e:nums){
            if(e%2!=0) e *= 2;
            mn = min(mn,e);
            pq.push(e);
        }
        int ans = INT_MAX;
        while(pq.top()%2==0){
            int top = pq.top();
            pq.pop();
            ans = min(ans,top-mn);
            top /= 2;
            mn = min(mn,top);
            pq.push(top);
        }
        ans = min(ans,pq.top()-mn);
        return ans;
    }
};

// similar method using make_heap algorithm on array/vector
// instead of STL maxHeapw
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int mn = INT_MAX, ans = INT_MAX;
        for(auto &e:nums) {
            if(e%2!=0) e *= 2;
            mn = min(mn,e);
        }
        make_heap(nums.begin(),nums.end());
        while(nums[0]%2==0) {
            ans = min(ans,nums[0]-mn);
            mn = min(mn,nums[0]/2);
            pop_heap(nums.begin(),nums.end());
            nums.back() /= 2;
            push_heap(nums.begin(),nums.end());
        }
        ans = min(ans,nums[0]-mn);
        return ans;
    }
};