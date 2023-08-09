def printEulerPath(n: int, edgeList: list[list[int]]) -> list:
    adj = [[] for _ in range(n)]
    degree = [0]*n
    for u,v in edgeList:
        adj[u].append(v)
        adj[v].append(u)
        degree[u] += 1
        degree[v] += 1

    # get start and end nodes for euler path (nodes with odd degree)
    # no odd degree node implies there might be an euler circuit
    oddDeg = [i for i,d in enumerate(degree) if d%2!=0]
    odl = len(oddDeg)
    if odl!=0 and odl!=2: return [-1]
    # if no odd degree nodes, there exists euler circuit
    # and any node can be start and end node (we take 0)
    start = 0
    if odl==2: start = oddDeg[0]

    pth,usedEdges = [],set()
    def dfs(node: int,parent: int) -> bool:
        pth.append(node)
        usedEdges.add((parent,node))
        usedEdges.add((node,parent))
        if len(pth)-1==len(edgeList): return True
        for nxt in adj[node]:
            if nxt!=parent and not (node,nxt) in usedEdges:
                if dfs(nxt,node): return True
        pth.pop()
        usedEdges.remove((parent,node))
        usedEdges.remove((node,parent))
        return False

    if dfs(start,-1): return pth
    else: return [-1]
