from typing import List
class Solution:
    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        adj = [[] for i in range(n)]
        for edge in connections:
            u,v = edge
            adj[u].append(v)
            adj[v].append(u)
        # tIn stores the timestamp when first that node is visited
        # tLow stores the lowest timestamp of it or any of its neighbours
        # except its parent while DFSing 
        visited,tIn,tLow = [False for _ in range(n)],[0 for _ in range(n)],[float("inf") for _ in range(n)]
        ans = []
        # simple DFS through the nodes
        def tarjan(timer: int, node: int, parent: int):
            visited[node] = True
            tIn[node] = tLow[node] = timer
            for neighbour in adj[node]:
                if neighbour!=parent:
                    if not visited[neighbour]:
                        tarjan(timer+1,neighbour,node)
                    tLow[node] = min(tLow[node],tLow[neighbour])
                    # if the neighbour's tLow is more than node's tIn
                    # implies there is no other way of visiting the neighbour
                    # other than going through node thus this is a bridge
                    if tLow[neighbour]>tIn[node]:
                        ans.append([node,neighbour])
            return
        tarjan(0,0,-1)
        return ans