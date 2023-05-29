class Solution {
private:
    void dfs(unordered_map<int, queue<int>> &adj, vector<vector<int>> &ans, int parent){
        while(!adj[parent].empty()){
            auto next = adj[parent].front();
            adj[parent].pop();
            dfs(adj,ans,next);
            ans.push_back({parent,next});
        }
    }
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, queue<int>> adj;
        unordered_map<int, int> in, out;
        for(auto &p:pairs){
            out[p[0]]++;
            in[p[1]]++;
            adj[p[0]].push(p[1]);
        }
        int start = -1;
        for(auto &[src,_]:adj) if(out[src]-in[src]==1){
            start = src;
            break;
        }
        start = (start==-1)?adj.begin()->first:start;
        vector<vector<int>> ans;
        dfs(adj,ans,start);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};