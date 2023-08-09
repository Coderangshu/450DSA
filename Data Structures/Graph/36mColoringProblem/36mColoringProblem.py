def graphColoring(adjMat: list[list[int]], k: int, V: int) -> bool:
    colors = [-1]*V
    
    def isSafe(node: int, color: int) -> bool:
        for nxt,boolean in enumerate(adjMat[node]):
            if boolean and colors[nxt]==color: return False
        return True
    
    def mColorer(node: int) -> bool:
        if node==V: return True
        for i in range(k):
            if isSafe(node,i):
                colors[node] = i
                if mColorer(node+1): return True
                colors[node] = -1
        return False
    
    return mColorer(0)