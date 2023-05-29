class Solution:
    def isCyclic(self, V, adj) -> bool:
        visited,recSet = set(),set()
        def dfs(node) -> bool:
            visited.add(node)
            recSet.add(node)
            for neigh in adj[node]:
                if neigh in recSet: return True
                if not neigh in visited:
                    if dfs(neigh): return True
            recSet.remove(node)
            return False
        for node in range(V):
            if not node in visited:
                recSet.clear()
                if dfs(node): return True
        return False