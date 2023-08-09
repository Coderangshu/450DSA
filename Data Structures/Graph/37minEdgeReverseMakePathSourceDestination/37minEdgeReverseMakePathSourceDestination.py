from heapq import heappop,heappush

# creat weighted adj list with weights 0 for original edges
# and 1 for reverse edges that we add for every original edge present
def reverseEdges(n: int, start: int, end: int, edgeList: list[list[int]]) -> int:
   adj = [[] for _ in range(n)]
   for a,b in edgeList:
      adj[a].append((b,0))
      adj[b].append((a,1))

   def dijkstra(S):
        minHeap,ans = [],[float("inf") for i in range(n)]
        heappush(minHeap,(0,S))
        ans[S] = 0
        while len(minHeap)>0:
            (val,node) = heappop(minHeap)
            if node==end: return val
            for nxt in adj[node]:
                [nnode,nval] = nxt
                if nval+val<ans[nnode]:
                    ans[nnode] = nval+val
                    heappush(minHeap,(ans[nnode],nnode))

   return dijkstra(start)
      