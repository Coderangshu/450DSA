// question : https://leetcode.com/problems/sliding-window-median/

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        multiset<int> window(nums.begin(),nums.begin()+k);
        auto mid = next(window.begin(),k/2);

        // pushing the first window's median
        ans.push_back((double(*mid)+*prev(mid,1-k%2))/2);
        for(int i=k;i<nums.size();i++){
            window.insert(nums[i]);

            // if the inserted value is less than mid then mid shifted to the left
            // as after the removal of the next element if that element is larger than
            // the median then this current mid will be the new median
            if(nums[i]<*mid) mid--;

            // if the element to be removed is smaller or equal to the median then
            // the median will be shifted to the right
            if(nums[i-k]<=*mid) mid++;

            // removing the element from the window which is out of the window
            window.erase(window.lower_bound(nums[i-k]));

            // pushing the current window's median
            ans.push_back((double(*mid)+*prev(mid,1-k%2))/2);
        }
        return ans;
    }
};