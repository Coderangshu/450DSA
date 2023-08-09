from functools import cmp_to_key

class findUnion:
    def __init__(self, numberOfNodes: int) -> None:
        self.parent = [i for i in range(numberOfNodes)]
        self.rank = [1 for i in range(numberOfNodes)]

    def find(self,n):
        if self.parent[n]==n: return n
        self.parent[n] = self.find(self.parent[n])
        return self.parent[n]

    # Return True if union is done else return False
    def union(self,a,b):
        pa,pb = self.find(a),self.find(b)
        if pa==pb: return False
        if self.rank[pa]>self.rank[pb]: self.parent[pb] = pa
        elif self.rank[pb]>self.rank[pa]: self.parent[pa] = pb
        else:
            self.parent[pb] = pa
            self.rank[pa] += 1
        return True
    
# Edge class for storing the Edges of thee graph
class Edge:
    def __init__(self, start, end, weight):
        self.start = start
        self.end = end
        self.weight = weight

def minimumSpanningTree(edges: list[Edge], V: int) -> int:
    # sort w.r.t. weight of edges in increasing order
    edges = sorted(edges,key=cmp_to_key(lambda a,b: a.weight-b.weight))
    ans = 0
    fu = findUnion(V)
    for edge in edges:
        if fu.union(edge.start,edge.end): ans += edge.weight
    return ans