class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for(auto e:prices){
            if(e<minPrice) minPrice = e;
            else maxProfit = max(maxProfit,e-minPrice);
        }
        return maxProfit;
    }
};