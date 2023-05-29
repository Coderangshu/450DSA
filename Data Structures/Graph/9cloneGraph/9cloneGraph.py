# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        vis = {}
        def dfs(cur):
            if not cur: return None
            if cur in vis: return vis[cur]
            newNode = Node(cur.val)
            vis[cur] = newNode
            for neigh in cur.neighbors:
                newNode.neighbors.append(dfs(neigh))
            return newNode
        return dfs(node) 