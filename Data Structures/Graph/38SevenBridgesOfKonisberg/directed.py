def printEulerPath(n: int, edgeList: list[list[int]]) -> list:
    adj = [[] for _ in range(n)]
    inDegree,outDegree = [0]*n,[0]*n
    for u,v in edgeList:
        adj[u].append(v)
        inDegree[v] += 1
        outDegree[u] += 1

    # get start and end nodes for euler path
    # node with outDegree-inDegree==1 -> path start
    # node with inDegree-outDegree==1 -> path end
    # inDegree==outDegree node implies there might be an euler circuit
    start,end,allSameNoInOutDeg = -1,-1,True
    for e,(i,o) in enumerate(zip(inDegree,outDegree)):
        if o!=i: allSameNoInOutDeg = False
        if abs(o-i)>1 or abs(i-o)>1: return [-1]
        if o-i==1:
            if start==-1: start = e
            else: return [-1]
        elif i-o==1:
            if end==-1: end = e
            else: return [-1]
    if allSameNoInOutDeg and start==-1 and end==-1: start=end=0
    
    path,usedEdges = [],set()
    def dfs(u,v):
        path.append(v)
        usedEdges.add((u,v))
        if len(path)-1==len(edgeList): return True
        for nxt in adj[v]:
            if not (v,nxt) in usedEdges:
                if dfs(v,nxt): return True
        path.pop()
        usedEdges.remove((u,v))
        return False
    
    return path if dfs(-1,start) else [-1]



# try algoritm with examples
edgeList1 = [[0,1],
             [1,2],
             [2,0],
             [0,3],
             [3,1],
             [1,4],
             [4,3],
             [3,2],
             [2,4],
             [4,0]
             ]

edgeList2 = [[0,1],
             [1,2],
             [2,0],
             [0,3],
             [3,1],
             [1,4],
             [4,3],
             [3,2],
             [2,4]
             ]

edgeList3 = [[0,1],
             [1,2],
             [2,0],
             [3,4],
             [4,1],
             [0,3],
             [3,1],
             [1,4],
             [4,3],
             [3,2],
             [2,4]
             ]

print(printEulerPath(5,edgeList1))
print(printEulerPath(5,edgeList2))
print(printEulerPath(5,edgeList3))