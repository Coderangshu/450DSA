#include <bits/stdc++.h>
using namespace std;
// Go through below approach first


// Let's say nums looks like this: [12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
// Because it's not fully sorted, we can't do normal binary search. But here comes the trick:

//     If target is let's say 14, then we adjust nums to this, where "inf" means infinity:
//     [12, 13, 14, 15, 16, 17, 18, 19, inf, inf, inf, inf, inf, inf, inf, inf, inf, inf, inf, inf]

//     If target is let's say 7, then we adjust nums to this:
//     [-inf, -inf, -inf, -inf, -inf, -inf, -inf, -inf, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]

// And then we can simply do ordinary binary search.

// Algorithm:
// we compare w.r.t nums[0], if both target and mid are on the same side then
// continue normal binary search as the mid is on the correct side.
// else if the target and the mid are not on the same side this means the
// mid is on the wrong side searching for the target, remove that side by
// either putting +INF or -INF on that side and continue binary search.
// To decide the +INF or -INF compare target to nums[0]
// if target is > than nums[0] then target is on this side thus mid's side
// all are assigned +INF, else assign -INF.

// Time complexity: O(log(n))
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l<=r){
            int mid = (l+r)>>1;
            int comparator = ((target<nums[0])==(nums[mid]<nums[0]))?nums[mid]:
                                                (target<nums[0])?INT_MIN:INT_MAX;
            if(target<comparator) r = mid-1;
            else if(target>comparator) l = mid+1;
            else return mid;
        }
        return -1;
    }
};


// Another approach easier than above also works
// when non-distinct values present in array
// lines I - V are required only for repeating element finding array
// gives the first occurence if found else in case of distinct array
// just return mid when nums[mid]==target
class Solution1 {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, ans = -1;
        while(l<=r){
            int mid = (l+r)>>1;
            // if found finding for the first index containing 
            if(nums[mid]==target){
                ans = mid;                                      // ------ (I)
                r = mid-1;                                      // ------ (II)
            }
            if(nums[l]==nums[mid] and nums[r]==nums[mid]){      // ------ (III)
                // if nums[l]==nums[mid] => l is first 
                // occurence of target thus return
                if(nums[l]==target) return l;                   // ------ (IV)
                l++, r--;                                       // ------ (V)
            }
            // if left side of mid is sorted
            else if(nums[l]<=nums[mid]){
                // if target is between l and mid
                if(nums[l]<=target and target<nums[mid]) r = mid-1;
                else l = mid+1;
            }
            // if right side of mid is sorted
            else{
                // if target is between r and mid
                if(nums[mid]<target and target<=nums[r]) l = mid+1;
                else r = mid-1;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> v = {4,5,6,7,0,1,2}, v1 = {2,5,6,0,0,1,2}, v2 = {0,0,0,0,0,0,0,0,0};
    int t = 0;
    Solution1 obj;
    cout<<obj.search(v,t)<<endl;
    cout<<obj.search(v1,t)<<endl;
    cout<<obj.search(v2,t)<<endl;
    return 0;
}