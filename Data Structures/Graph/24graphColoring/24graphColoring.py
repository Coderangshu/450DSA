def graphColoring(adj: list[list[int]], colors: int):
    v = len(adj)
    colorPath = []
    unavailableColors = [set() for i in range(v)]
    def recursion(node):
        if node==v: return True
        for color in range(colors):
            if color not in unavailableColors[node]:
                for neighbours in adj[node]: unavailableColors[neighbours].add(color)
                colorPath.append(color)
                if recursion(node+1): return True
                for neighbours in adj[node]: unavailableColors[neighbours].remove(color)
                colorPath.pop()
        return False
    print(recursion(0))
    print(colorPath)

adj = [[1],[0]]
adj1 = [[1,3],[0,2],[1,3],[0,2]]
adj2 = [[1,2],[0,2],[0,1]]
graphColoring(adj2,4)