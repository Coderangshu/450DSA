from queue import PriorityQueue
import sys

class Solution:
    def dijkstra(self, V, adj, S):
        minHeap,ans = PriorityQueue(),[sys.maxsize for i in range(V)]
        minHeap.put((0,S))
        ans[S] = 0
        while minHeap.qsize()>0:
            (val,node) = minHeap.get()
            val *= -1
            for nxt in adj[node]:
                [nnode,nval] = nxt
                if nval+val<ans[nnode]:
                    ans[nnode] = nval+val
                    minHeap.put((ans[nnode]*-1,nnode))
        return ans