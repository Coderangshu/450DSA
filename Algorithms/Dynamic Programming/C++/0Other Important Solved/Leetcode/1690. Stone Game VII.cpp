class Solution {
public:
    
    vector<int> preSum;
    int memo[1001][1001];
    
    int getPreSum(int left, int right){
        return preSum[right+1]-preSum[left];
    }
    

    // minimax approach
    int recursion(vector<int> &v, int start, int end, int isAlice){
        if(end==start) return 0;
        // alice tries to increase the difference thus max of addition, this implies that
        // the max is added to the result so far
        if(isAlice==1) return max(getPreSum(start+1,end)+recursion(v,start+1,end,1-isAlice),
                               getPreSum(start,end-1)+recursion(v,start,end-1,1-isAlice));
        // bob tries to decrease the difference thus min of substraction, this implies that
        // the max is substracted from the result far
        else return min(recursion(v,start+1,end,1-isAlice)-getPreSum(start+1,end),
                        recursion(v,start,end-1,1-isAlice)-getPreSum(start,end-1));
    }
    
    int recursion(vector<int> &v, int start, int end){
        if(end==start) return 0;
        if(memo[start][end]!=-1) return memo[start][end];
        // irrespective of player both plays optimally, our target is to maximize the
        // difference on the result that will be obtained from now to end and the current result
        return memo[start][end] = max(getPreSum(start+1,end)-recursion(v,start+1,end),
                   getPreSum(start,end-1)-recursion(v,start,end-1));
    }
    
    int stoneGameVII(vector<int>& stones) {
        memset(memo,-1,sizeof(memo));
        int n = stones.size();
        preSum.assign(n+1,0);
        int sum = 0, i = 0;
        for(auto e:stones){
            sum += e;
            preSum[++i] = sum;
        }
        return recursion(stones,0,n-1);
    }
};