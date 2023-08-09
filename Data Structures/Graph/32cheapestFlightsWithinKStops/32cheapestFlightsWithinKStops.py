from typing import List
from collections import defaultdict, heappush, heappop

class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        if src==dst: return 0
        adj = defaultdict(list)
        for fr, to, price in flights:
            adj[fr].append([to, price])
        q = []
        k += 1
        heappush(q,[0,src,k])
        vis = set()
        vis.add((src,k))
        while q:
            wt,node,k = heappop(q)
            if node==dst: return wt
            if (node,k) in vis or k<=0 or node not in adj: continue
            vis.add((node,k))
            for nb,prc in adj[node]:
                heappush(q,[wt+prc,nb,k-1])
        return -1