from collections import deque

class Solution:
    def isBipartite(self, graph: list[list[int]]) -> bool:
        n = len(graph)
        color = [-1 for _ in range(n)]
        def bfs(node: int) -> bool:
            q = deque()
            q.append(node)
            color[node] = 0
            while q:
                node = q.popleft()
                nextCol = color[node]^1
                for neighbour in graph[node]:
                    if color[neighbour]==-1:
                        color[neighbour] = nextCol
                        q.append(neighbour)
                    else:
                        if color[neighbour]==color[node]: return False
            return True

        for node in range(n):
            if color[node]==-1:
                if not bfs(node): return False
        return True