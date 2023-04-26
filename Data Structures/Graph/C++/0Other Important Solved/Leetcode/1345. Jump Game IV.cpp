// Question : https://leetcode.com/problems/jump-game-iv/

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,vector<int>> um;
        vector<int> visited(n,false);
        for(int i=0;i<n;i++) um[arr[i]].push_back(i);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                int node = q.front();
                q.pop();
                if(node==n-1) return ans;
                if(node-1>=0 and !visited[node-1]) q.push(node-1), visited[node-1] = true;
                if(node+1<n and !visited[node+1]) q.push(node+1), visited[node+1] = true;
                for(auto &e:um[arr[node]]) if(e!=node and !visited[e]) q.push(e), visited[e] = true;
                // clearing the um[arr[node]] as not required further, although it won't be
                // visited again but still the above for loop would run and check all these
                // indices, thus reducing from O(n^2) to O(n)
                um[arr[node]].clear();
            }
            ans++;
        }
        return -1;
    }
};
