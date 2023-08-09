class Solution:
    
    #Function to find number of strongly connected components in the graph.
    def kosaraju(self, V, adj):
        def dfs(node: int, adj: list[list[int]], isRev: bool):
            vis[node] = True
            for neighbour in adj[node]:
                if not vis[neighbour]:
                    dfs(neighbour,adj,isRev)
            if not isRev: stk.append(node)

        # populate stack using simple dfs
        stk, vis = [], [False for _ in range(V)]
        for node in range(V):
            if not vis[node]: dfs(node,adj,False)

        # create transpose adj to reverse all edges of graph
        adjT = [[] for _ in range(V)]
        for node,neighbours in enumerate(adj):
            for neighbour in neighbours:
                adjT[neighbour].append(node)
                
        # DFS through transpose graph and count SCCs
        vis = [False for _ in range(V)]
        ans = 0
        while len(stk)>0:
            node = stk.pop()
            # not visited means start of new SCC
            if not vis[node]:
                ans += 1
                dfs(node,adjT,True)
        return ans