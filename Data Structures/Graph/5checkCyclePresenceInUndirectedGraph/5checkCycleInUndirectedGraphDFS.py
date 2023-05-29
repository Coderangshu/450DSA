class Solution:
	def isCycle(self, V: int, adj: list[list[int]]) -> bool:
		visited = set()
		def dfs(u,parent) -> bool:
			visited.add(u)
			for v in adj[u]:
				if not v in visited:
					if dfs(v,u): return True
					elif v!=parent: return True
			return False
		for i in range(V):
			if not i in visited:
				if dfs(i,-1): return True
		return False