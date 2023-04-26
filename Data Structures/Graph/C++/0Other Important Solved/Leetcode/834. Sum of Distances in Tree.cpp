class Solution {
public:
    
    vector<unordered_set<int>> adj;
    vector<int> count, ans;
    
    // this helps us count the number of nodes in a subtree
    // including root of that subtree and also the sum of all
    // distances from root to all nodes of that subtree
    // this is done by bottom to up (post order)
    void postOrder(int root, int parent){
        for(auto e:adj[root]){
            if(e!=parent){
                postOrder(e,root);
                count[root] += count[e];
                ans[root] += count[e]+ans[e];
            }
        }
    }
    
    // this is done top to bottom(pre order), when we move our
    // root from parent to its child i, count[i] points get 1
    // closer to root, and the rest nodes (i.e. n - count[i])
    // nodes get 1 futhur to root.
    // Thus ans[i] = (ans[root] - count[i]) + (n-count[i])
    void preOrder(int root, int parent){
        for(auto e:adj[root]){
            if(e!=parent){
                ans[e] = ans[root]-count[e]+count.size()-count[e];
                preOrder(e,root);
            }
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        count.assign(n,1);
        ans.assign(n,0);
        for(auto e:edges){
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }
        postOrder(0,-1);
        preOrder(0,-1);
        return ans;
    }
};