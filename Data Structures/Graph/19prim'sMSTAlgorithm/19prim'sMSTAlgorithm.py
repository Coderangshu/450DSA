from queue import PriorityQueue

# Edge class for storing the Edges of thee graph
class Edge:
    
    def __init__(self, start, end, weight) :

        self.start = start
        self.end = end
        self.weigth = weight


def minimumSpanningTree(edges, V, E):
    adj = [[] for i in range(V)]
    for edge in edges:
        adj[edge.start].append((edge.end,edge.weigth))
        adj[edge.end].append((edge.start,edge.weigth))
    # PriorityQueue takes minHeap by default
    minHeap = PriorityQueue()
    minHeap.put([0,0,-1])
    vis,ans = [0]*V,0
    while minHeap.qsize()>0:
        cur = minHeap.get()
        weight,end,start = cur[0],cur[1],cur[2]
        if vis[end]: continue
        vis[end] = 1
        ans += weight
        for nxt in adj[end]:
            minHeap.put([nxt[1],nxt[0],end])
    return ans