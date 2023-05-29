# Using Union Find to find the extra edges
class DSU:
    parent, rank = [],[]
    def __init__(self,n):
        self.parent = [i for i in range(n)]
        self.rank = [1 for i in range(n)]

    def find(self,n):
        if self.parent[n]==n: return n
        self.parent[n] = self.find(self.parent[n])
        return self.parent[n]
    
    # Returns True if union is created else returned False
    def union(self,a,b) -> bool:
        pa,pb = self.find(a),self.find(b)
        if pa!=pb:
            if self.rank[pa]>self.rank[pb]: self.parent[pb] = pa
            elif self.rank[pb]<self.rank[pa]: self.parent[pa] = pb
            else:
                self.parent[pb] = pa
                self.rank[pa] += 1
            return True
        else: return False

class Solution:
    def makeConnected(self, n: int, connections: list[list[int]]) -> int:
        extraEdges = 0
        fu = DSU(n)
        for edge in connections:
            if not fu.union(edge[0],edge[1]): extraEdges += 1
        for i in range(n):
            fu.find(i)
        components = len(set(fu.parent))
        requiredEdges = components-1
        if extraEdges>=requiredEdges: return requiredEdges
        else: return -1