from functools import cmp_to_key

# Edge class for storing the Edges of thee graph
class Edge:
    def __init__(self, start, end, weight) :

        self.start = start
        self.end = end
        self.weigth = weight

def minimumSpanningTree(edges, V, E):
    parent,rank = [i for i in range(V)],[1 for i in range(V)]
    
    def find(n):
        if parent[n]==n: return n
        parent[n] = find(parent[n])
        return parent[n]

    # Return True if union is done else return False
    def union(a,b):
        pa,pb = find(a),find(b)
        if pa==pb: return False
        if rank[pa]>rank[pb]: parent[pb] = pa
        elif rank[pb]>rank[pa]: parent[pa] = pb
        else:
            parent[pb] = pa
            rank[pa] += 1
        return True

    # sort w.r.t. weigth of edges in increasing order
    edges = sorted(edges,key=cmp_to_key(lambda a,b: a.weigth-b.weigth))
    ans = 0
    for edge in edges:
        if union(edge.start,edge.end): ans += edge.weigth
    return ans