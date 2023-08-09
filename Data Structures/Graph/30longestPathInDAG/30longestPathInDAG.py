from typing import List

# Similar to find shortest path in DAG just reverse weights
# 2 step process:
# 1. find topological sort
# 2. relax each edge
class Solution:
    def shortestPath(self, n : int, src : int, edges : List[List[int]]) -> List[int]:
        adj = [[] for _ in range(n)]
        for edge in edges: adj[edge[0]].append((edge[1],-edge[2]))
        
        # toposort using stack and dfs
        stk, vis = [],[False for _ in range(n)]
        def dfs(node):
            vis[node] = True
            for next,_ in adj[node]:
                if not vis[next]: dfs(next)
            stk.append(node)
        for i in range(n):
            if not vis[i]: dfs(i)

        # relax each edge
        ans = [10**9 for _ in range(n)]
        ans[src] = 0
        while stk:
            node = stk.pop()
            for nxt,wt in adj[node]:
                if ans[node]!=10**9 and ans[node]+wt<ans[nxt]:
                    ans[nxt] = ans[node]+wt
        for i,e in enumerate(ans):
            if e==10**9: ans[i] = -1
            else: ans[i] *= -1
        return ans