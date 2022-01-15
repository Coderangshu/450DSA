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

static int mod = 1e9+7;
class Solution {
public:
    
    unordered_map<TreeNode*,long long int> um;
    
    // getting total sum and in the process storing the sum
    // for each of the subtrees in hashmap
    long long int getTotalSum(TreeNode* root){
        if(!root) return 0;
        
        um[root->left] = getTotalSum(root->left);
        um[root->right] = getTotalSum(root->right);
        long long int sum = um[root->left]+um[root->right]+root->val;
        
        return um[root] = sum;
    }
    
    // taking each of the subtree sum and getting the sum of rest
    // tree by subtracting and then ans is the max of the product
    // of these
    long long int maxProduct(TreeNode* root, long long int totSum){
        long long int ans = INT_MIN;
        for(auto e:um){
            if(e.first==root) continue;
            ans = max(ans,e.second*(totSum-e.second));
        }
        return ans;
    }
    
    int maxProduct(TreeNode* root) {
        long long int ts = getTotalSum(root);
        long long int ans = maxProduct(root,ts);
        return ans%mod;
    }
};
