from heapq import heappop,heappush

class Solution:
    def dijkstra(self, V, adj, S):
        minHeap,ans = [],[float("inf") for i in range(V)]
        heappush(minHeap,(0,S))
        ans[S] = 0
        while len(minHeap)>0:
            (val,node) = heappop(minHeap)
            val *= -1
            for nxt in adj[node]:
                [nnode,nval] = nxt
                if nval+val<ans[nnode]:
                    ans[nnode] = nval+val
                    heappush(minHeap,(-ans[nnode],nnode))
        return ans