class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int cntNeg = 0, firstNeg = -1, winStart = -1, maxLen = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                cntNeg = 0;
                firstNeg = -1;
                winStart = i;
            }
            else{
                if(nums[i]<0) cntNeg++;
                // taking the index of first negative in current window
                if(cntNeg==1 and firstNeg==-1) firstNeg = i;
                // if there are even # of odd #s then consider
                // max length from the start of the current window
                if(cntNeg%2==0) maxLen = max(maxLen,i-winStart);
                // else consider the max length from next of the first
                // negative index to i
                else maxLen = max(maxLen,i-firstNeg);
            }
        }
        return maxLen;
    }
};