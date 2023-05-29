from collections import deque

class Solution:
	def isCycle(self, V: int, adj: list[list[int]]) -> bool:
		visited = set()
		def bfs(node) -> bool:
			q, parent = deque(),[-1]*0
			q.append(node)
			visited.add(node)
			while q:
				u = q.popleft()
				for v in adj[u]:
					if not v in visited:
						visited.add(v)
						parent[v] = u
						q.append(v)
					elif parent[u]!=v:
						return True
			return False
		for node in range(V):
			if not node in visited:
				if bfs(node): return True
		return False
