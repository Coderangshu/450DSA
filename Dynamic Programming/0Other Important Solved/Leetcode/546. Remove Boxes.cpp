class Solution {
public:
    
    int memo[101][101][101];
    
    // leftSame stores # of same colored as the start indexed box
    int removeBoxesUtil(vector<int> &boxes, int start, int end, int leftSame){
        int ls = leftSame;
        
        // base condition
        if(start>end) return memo[start][end][ls] = 0;
        
        if(memo[start][end][ls]!=-1) return memo[start][end][ls];
        
        // taking into account all same colors from starting
        int i = start;
        for(;i+1<=end and boxes[i]==boxes[i+1];i++,leftSame++);
        // including the last same colored box
        i++,leftSame++;
        
        // 2 options of removing same colored:
        // (1) above continuous same color streak,
        // (2) above and the later occuring of same color streak
        
        // option 1
        // converging same colored and finding and adding max points
        // for the rest array, as there's no same colored left side
        // of i to end array thus leftSame is 0 from i to end
        int ans = (leftSame*leftSame)+removeBoxesUtil(boxes,i,end,0);
        
        // option 2
        // finding the next same color from i+1(as i is different color) to end
        // when found calculate max points from i to k-1 and from k to end, add
        // this search is continued till the last of array tried for all same
        // colored box found and the max is stored in ans
        for(int k=i+1;k<=end;k++){
            if(boxes[i-1]==boxes[k]) 
                ans = max(ans,removeBoxesUtil(boxes,i,k-1,0)+removeBoxesUtil(boxes,k,end,leftSame));
        }
        return memo[start][end][ls] = ans;
    }
    
    int removeBoxes(vector<int>& boxes) {
        memset(memo,-1,sizeof(memo));
        return removeBoxesUtil(boxes,0,boxes.size()-1,0);
    }
};
