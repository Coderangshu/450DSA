class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int,int> um;
        long ans = 0;
        for(auto &e:arr) um[e]++;
        for(auto &[f,fcnt]:um){
            for(auto &[s,scnt]:um){
                int t = target-f-s;
                if(!um.count(t)) continue;
                // Using combination formulas
                // no need to check if frequencies are >= 3 for below
                // as if <3 than one of them would become 0 thus whole product 0
                // similar for next condition
                if(f==s and s==t) ans += (long)fcnt*(fcnt-1)*(fcnt-2)/6;
                else if(f==s and s!=t) ans += (long)fcnt*(fcnt-1)/2*um[t];
                // taking f<s and s<t instead of f!=s and s!=t as for different
                // f,s,t only consider one combination not all, != would consider
                // all those combinations but < would consider only 1 particular
                // combination of these 3 numbers
                // ex - target = 6 nos = {1,2,3}
                // possible combinations - {1,2,3} {2,1,3} {3,2,1} ..... so on
                else if(f<s and s<t) ans += (long)fcnt*scnt*um[t];
            }
        }
        return ans%(int)(1e9+7);
    }
};