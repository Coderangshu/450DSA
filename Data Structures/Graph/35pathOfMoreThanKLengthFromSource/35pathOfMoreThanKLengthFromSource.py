def getPath(adj: list[list[list[int]]], src: int, k: int):
    path, vis = [], set()
    def dfs(node: int, k: int):
        if k<=0: return True
        if node in vis: return False
        vis.add(node)
        for nxt,wt in adj[node]:
            path.append(nxt)
            if dfs(nxt,k-wt): return True
            path.pop()
        vis.remove(node)
        return False
    if dfs(src,k):
        print(path)
    else: print("No path exist")

adj = [[[1,4],[7,8]],
       [[0,4],[2,8],[7,11]],
       [[1,8],[5,4],[3,7],[8,2]],
       [[2,7],[4,9],[5,14]],
       [[3,9],[5,10]],
       [[2,4],[3,14],[4,10],[6,2]],
       [[5,2],[7,1],[8,6]],
       [[0,8],[1,11],[6,1],[8,7]],
       [[2,2],[6,6],[7,7]]
       ]
getPath(adj,0,58)