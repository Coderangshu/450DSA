class Solution:
    def isNegativeWeightCycle(self, n: int, edges: list[list[int]]) -> bool:
        if n==0 or len(edges)==0: return False
        distance = [float("inf")]*n
        distance[edges[0][0]] = 0
        
        def oneTraversal():
            for edge in edges:
                [start,end,weight] = edge
                distance[end] = min(distance[end],distance[start]+weight)
        
        for i in range(n-1): oneTraversal()
        nextDistance = [i for i in distance]
        oneTraversal()
        return False if distance==nextDistance else True