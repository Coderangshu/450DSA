// question : https://leetcode.com/problems/132-pattern/

// Brute force solution
// Time complexity: O(n^3)
// Space complexity: O(1)

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] < nums[j] && nums[j] > nums[k]) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};



// Better solution
// Time complexity: O(n^2)
// Space complexity: O(1)

class Solution1 {
public:
    bool find132pattern(vector<int>& nums) {
        // keeping track of the min value from the left,
        // the first value more small more better because
        // we need to keep the search space for the kth element
        // as large as possible at every iteration wherein the
        // search space would be from min value to nums[j]
        int mn = nums[0], n = nums.size();
        for(int j=1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(mn<nums[k] and nums[k]<nums[j]) return true;
            }
            // update the min value if smaller element found
            mn = min(mn,nums[i]);
        }
        return false;
    }
};



// Optimal solution
// Time complexity: O(n)
// Space complexity: O(n)

class Solution2{
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size(), mn = INT_MAX;
        // this is somewhat similar to the previous solution
        // crate min array to store the min value from left to right
        vector<int> minArray(n);
        for(int i=0;i<n;i++){
            mn = min(mn,nums[i]);
            minArray[i] = mn;
        }

        // need to search the jth and the kth element now
        // storing elements in the stack so as to reverse the order
        // and if observed carefully the stack stores the values in
        // increasing order top to bottom (as for each index's min, it
        // will either increase or remain same right to left), iterating
        // from right to left, and considering each element as the jth 
        // element and removing all stack.top() which are <= the min
        // element upto this jth element, this is done because we need kth 
        // element as greater then ith and less than jth, the removing part
        // fulfils kth > ith after removal we check if jth > stack.top()
        // return true else push this element to the stack as this might be
        //  a viable future kth element

        // NOTE: Above is the detailed story, for solving just keep in mind
        // remove all elements from the stack which are <= min and check the
        // top with current jth element, checking the top as this will be the
        // smallest element greater than min at this index (values in stack are
        // in increasing order)
        stack<int> stk;
        for(int j=n-1;j>=0;j--){
            // 1. "ith element"                   = minArray[j]
            // 2. "jth element"                   = current element
            // 3. "kth element"(viable candidate) = stk stores these in increasing order

            // removing all elements from the stack which are less than the min
            // i.e. remove all possible kth elements that are <= ith element
            while(!stk.empty() and stk.top()<=minArray[j]) stk.pop();

            // check if current jth element is greater than
            // the smallest viable kth element candidate
            if(!stk.empty()) if(stk.top()<nums[j]) return true;
            stk.push(nums[i]);
        }
        return false;
    }      
};