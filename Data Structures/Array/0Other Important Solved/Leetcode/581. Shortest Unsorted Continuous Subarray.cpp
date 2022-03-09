// Intuition:
// for an unsorted array there must be an element that is greater than an element to its right
// also there must be an element that is less than an element to its left
// using above 2 observations to obtain the start and end of the unsorted subarray
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // taking weird start and end values so as to maintain
        // the answer as 0 if the array is already sorted
        int end = -2, mx = nums[0], n = nums.size();
        // keep track of max from l -> r
        // if at any point the element is less than the max,
        // then we know that the subarray is unsorted ending at this
        // element, as the max element should come to this index
        for(int i=1;i<n;i++){
            mx = max(mx,nums[i]);
            if(nums[i]<mx) end = i;
        }
        // similarly keep track of min from r -> l
        // if at any point the element is greater than the min,
        // then we know that the subarray is unsorted starting at this
        // element, as the min element should come to this index
        int start = -1, mn = nums[n-1];
        for(int i=n-2;i>=0;i--){
            mn = min(mn,nums[i]);
            if(nums[i]>mn) start = i;
        }
        return end-start+1;
    }
};