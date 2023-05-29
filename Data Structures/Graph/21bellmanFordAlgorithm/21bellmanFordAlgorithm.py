class Solution:
    def isNegativeWeightCycle(self, n, edges):
        if n==0 or len(edges)==0: return 0
        distance = [float("inf")]*n
        distance[edges[0][0]] = 0
        
        def oneTraversal():
            for edge in edges:
                [start,end,weight] = edge
                distance[end] = min(distance[end],distance[start]+weight)
        
        for i in range(n-1): oneTraversal()
        nextDistance = [i for i in distance]
        oneTraversal()
        return 0 if distance==nextDistance else 1