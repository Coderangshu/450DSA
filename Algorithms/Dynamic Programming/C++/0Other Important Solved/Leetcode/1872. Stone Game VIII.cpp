class Solution {
private:
    // finding the max diff at each step
    int recursion(vector<int>& stones, vector<int> &memo, int n, int i){
        if(i==n-1) return stones[i];
        if(memo[i]!=INT_MIN) return memo[i];
        // have 2 options:
        // (1) take upto this index in this pass's score and send sum of this
        //     element and also the next indices for the opponent score to be
        //     calculated and substracted from the current score to get the diff
        // (2) try taking the next stones into this pass's score
        // atlast take the max diff of both the circumstances

        // An arbitary example to elaborate the above 2 cases
        // [-1,2,-3,4,-5] --- prefix sum ---> [-1,1,-2,2,-3]
        // follow the prefix sum array values below
        // starting from 1st index
        // 1 - (recursion from -2 to end) => at the -2 position it includes 2 values added
        // 1 (from the previous stones sum i.e. (-1+2)) and -3 resulting in -2, thus fulfilling
        // the condition of atleast 2 elements for the participant
        // thus goes on....
        // for the second case its easy to visualize, we keep including each of the stones upto the end
        // and see if any of these choices gives more diff
        int takeUptoHere = stones[i] - recursion(stones,memo,n,i+1);
        int takeNextsToo = recursion(stones,memo,n,i+1);
        return memo[i] = max(takeUptoHere,takeNextsToo);
    }
public:
    int stoneGameVIII(vector<int>& stones) {
        // converting the stones to prefix sum vector, as after taking upto ith index
        // we replace all those stones with the sum upto that index, thus the prefix sum
        // property is maintained at all times.
        partial_sum(stones.begin(),stones.end(),stones.begin());
        int n = stones.size();
        vector<int> memo(n+1,INT_MIN);
        // notice index starts from 1 as atleast 2 (>1 stones are to be picked)
        // stone is to be taken by each participant, recursion makes sure of that
        // 1 element is picked up, thus to make sure the first is picked up thus starting
        // from 1
        return recursion(stones,memo,n,1);
    }
};
