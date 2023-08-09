from math import log2

def gospersHack(setBits: int) -> int:
    c = setBits & -setBits
    r = setBits + c
    setBits = (((r ^ setBits) >> 2) // c) | r
    return setBits

def checkCover(n, k, m, adjMat):
    setBits,limit = (1<<k)-1,(1<<n)

    while setBits<limit:
        visited,noOfEdgesCovered,nodeBit = [[False]*(n+1) for _ in range(n+1)],0,1
        while nodeBit<limit:
            if setBits&nodeBit:
                node = int(log2(nodeBit&~(nodeBit-1)))+1
                for i in range(1, n+1):
                    if adjMat[node][i] and not visited[node][i]:
                        visited[node][i] = visited[i][node] = True
                        noOfEdgesCovered += 1
            nodeBit <<= 1

        if noOfEdgesCovered==m: return True
        setBits = gospersHack(setBits)
        
    return False

def binarySearch(adjMat, n, m):
    lo,hi = 1,n
    while lo<hi:
        mid = (lo + hi) >> 1
        if checkCover(n, mid, m, adjMat): hi = mid
        else: lo = mid+1
    return lo

def vertexCover(n, edges):
    rows, cols = n+1, n+1
    adjMatrix = [[0]*cols for _ in range(rows)]

    for a,b in edges:
        adjMatrix[a][b] = 1
        adjMatrix[b][a] = 1

    return binarySearch(adjMatrix, n, len(edges)) 