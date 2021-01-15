class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for(int e:prices){
            if(e<minPrice) minPrice = e;
            else{
                if(e-minPrice>maxProfit) maxProfit = e-minPrice;
            }
        }
        return maxProfit;
    }
};
