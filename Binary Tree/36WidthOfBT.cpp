/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int mn = q.front().second;
            int sz = q.size();
            int first = 0, last = 0;
            for(int i=0;i<sz;i++){
                auto [node,id] = q.front();
                // to prevent overflow of int when long way down the tree
                id -= mn;
                q.pop();
                if(i==0) first = id;
                else if(i==sz-1) last = id;
                if(node->left) q.push({node->left,2*id+1});
                if(node->right) q.push({node->right,2*id+2});
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
};