# Question : https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes

class Solution:
    def subtreeWithAllDeepest(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def dfs(root: TreeNode):
            if not root: return (root,0)
            ln, ld = dfs(root.left)
            rn, rd = dfs(root.right)
            if ld>rd: return (ln,ld+1)
            elif ld<rd: return (rn,rd+1)
            return (root,ld+1)
        return dfs(root)[0]