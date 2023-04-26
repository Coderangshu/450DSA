// question : https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/
// This question is an application of maximum sum subarray with value no larger than k
// Similarly can be done for the smallest sum subarray with value no lesser than k

class Solution {
private:
    // THE FUNCTION OF INTEREST
    // function to find maximum sum subarray with value no larger than k

    // There are 3 ways of finding the max sum subarray according to the
    // requirement :
    // (1) Kadane's Algorithm : Using DP when array contains -ve and +ve (TC:O(n))
    // (2) Sliding Window : When array contains only +ve or -ve (TC:O(n))
    // (3) Binary Search in set : When there's an upperbound to the max sum possible
    
    // both (1) and (2) can be used interchangeably given they satisfy there specific
    // conditions, (3) is the one we discuss here

    // METHOD : maintain a cumulative sum (CS) from the beginning
    // for every index we get the CS then for that CS, binary search (upper bound)
    // the previous CSs found to get the smallest possible value greater than
    // ((CS - k) - 1) (see below equation to get justification) and -1 is done
    // to check that we dont's miss the (CS-k) value if found as the property of
    // upperbound is to find the greater than the given number, if custom binary
    // search function is written than no need to -1

    // CS - previous CS found by search = k => previous CS found by search = CS - k

    // hence smaller the binary search outcome closer to k
    // and larger the outcome smaller is the value and further away from k
    // if exactly (CS-k) is found implies we the subarray sum that will give k
    // thus we end our process and return the answer

    int getMaxSumUpperBounded(int* arr, int n, int k){

	  // a self sorting data structure to maintain
    	  // an ordered cumulative sums of at all indices
    	  // upto the current index
        set<int> st;
    	  // inserting 0 to not keep the set empty in the beginning
    	  // so as to also check the first element if it satifies the
    	  // conditions and could be a viable answer and not miss it
        st.insert(0);

        int ans = INT_MIN, curSum = 0;
        for(int i=0;i<n;i++){
            curSum += arr[i];
            auto it = st.upper_bound(curSum-k-1);
            if(it!=st.end()) ans = max(ans,curSum-*it);
            if(ans==k) return k;
            st.insert(curSum);
        }
        return ans;
    }

public:
    // this is a simple old school technique applied to find something in
    // 2d matrix, similar to the max sum rectangle in 2d matrix found under
    // the dp section

    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size(), ans = INT_MIN, arr[100];
        for(int top=0;top<n;top++){
            memset(arr,0,sizeof(arr));
            for(int bottom=top;bottom<n;bottom++){
                for(int i=0;i<m;i++) arr[i] += matrix[bottom][i];
                ans = max(ans,getMaxSumUpperBounded(arr,m,k));
                if(ans==k) return ans;
            }
        }
        return ans;
    }
};