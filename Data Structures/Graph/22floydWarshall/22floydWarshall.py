def floydWarshall(adjMat: list[list[int]]) -> list[list[int]]:
    n = len(adjMat)
    for i in range(n):
        for j in range(n):
            if adjMat[i][j]==-1: adjMat[i][j] = float("inf")
    
    # i -> src, j -> dest, k -> intermediate
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if adjMat[i][k]!=float("inf") and adjMat[k][j]!=float("inf"):
                    adjMat[i][j] = min(adjMat[i][j],adjMat[i][k]+adjMat[k][j])
    return adjMat