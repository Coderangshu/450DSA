class Solution {
private:
    // recursive method (without nota)
    int recursion(vector<int>& prices, int i, int j){
        if(i==0) return (j==0)?0:INT_MIN;
        if(j==0) return max(recursion(prices,i-1,0),recursion(prices,i-1,1)+prices[i-1]);
        return max(recursion(prices,i-1,1),recursion(prices,i-1,0)-prices[i-1]);
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // # of transactions allowed
        int nota = 1;
        
        // dp[ith_day][k_transaction_left][#ofStockInHand(0 or 1)]
        // dp stores the max profit after the actions done on 
        // the ith day for the given parameters
        int dp[n+1][nota+1][2];
        
        // Impossible Condition(IC):
        // A transaction consists of buy & sell, hence sell cannot happen before buying
        for(int i=0;i<n+1;i++){
            for(int j=0;j<nota+1;j++){
                for(int k=0;k<2;k++){
                    // Base Cases:
                    
                    // (1) For 0th day:
                    // have 0 share in hand => 0 profit (no shares available to buy)
                    // have 1 share in hand => INT_MIN (bacause IC)
                    if(i==0) dp[i][j][k] = (k==0)?0:INT_MIN;
                    
                    // (2) When 0 transactions are available:
                    // have 0 share in hand => 0 profit (can't buy new)
                    // have 1 share in hand => INT_MIN (bacause IC)
                    else if(j==0) dp[i][j][k] = (k==0)?0:INT_MIN;
                    
                    else{
                        // for 0 stocks to be in hand after ith day, 
                        // action performed on (i-1)th day:
                        // Rest->no buying/selling when theres 0 share in hand
                        // Sell->sell when theres 1 share in hand
                        if(k==0) dp[i][j][k] = max(dp[i-1][j][k],dp[i-1][j][1]+prices[i-1]);
                        
                        // for 1 stock to be in hand after ith day, 
                        // action performed on (i-1)th day:
                        // Rest->no buying/selling when theres 1 share in hand
                        // Buy->buy when theres 0 shares in hand
                        else dp[i][j][k] = max(dp[i-1][j][k],dp[i-1][j-1][0]-prices[i-1]);
                    }
                }
            }
        }
        return dp[n][nota][0];
    }
};