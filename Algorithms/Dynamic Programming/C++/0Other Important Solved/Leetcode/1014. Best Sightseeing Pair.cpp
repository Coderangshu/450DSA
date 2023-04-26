// similar to best time to buy stock I,
// keeping track of max val for index i
// and for each step forward in search of j
// decrement imax to keep in consideration the
// distance between i and j.
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int imax =  values[0], ans = 0;
        for(int j=1;j<values.size();j++){
            imax--;
            ans = max(ans,imax+values[j]);
            imax = max(imax,values[j]);
        }
        return ans;
    }
};