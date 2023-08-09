''' Time Complexity: O(N!)
    Space Complexity: O(N^2)
    N = number of cities
'''
# Function to check whether graph is connected
def isGraphConnected(adj) -> bool:
    def dfs(node):
        visited.add(node)
        for nxt,wt in adj[node]:
            if nxt not in visited:
                dfs(nxt)
    visited = set()
    dfs(0)
    return len(visited)==len(adj)


# Function to check if euler circuit is present in graph
def eulerCircuitExists(adj) -> bool:
    for neigbourList in adj:
        if len(neigbourList)%2==1: return False
    return True


# Function to calculate shortest distance
# using Floyd Warshall Algprithm
def shortestDistance(n, roads):
    dist = [[float("inf")]*n for _ in range(n)]
    for u,v,wt in roads:
        dist[u-1][v-1] = dist[v-1][u-1] = wt
    for k in range(n):
        for i in range(n):
            for j in range(n):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
    return dist


# minimum extra time to travel all oddDegNodes
def findMinTime(oddDegNodes, dist):
    if len(oddDegNodes)==2: return dist[oddDegNodes[0]][oddDegNodes[1]]
    minTravelTime = float("inf")
    city1 = oddDegNodes.pop()
    
    for city2 in oddDegNodes:
        currentTravelTime = dist[city1][city2]
        currentTravelTime += findMinTime([node for node in oddDegNodes if node!=city2], dist)
        minTravelTime = min(minTravelTime, currentTravelTime)
    
    return minTravelTime


def minTravelTime(n, roads):
    adj = [[] for _ in range(n)]
    for u,v,wt in roads:
        adj[u-1].append((v-1,wt))
        adj[v-1].append((u-1,wt))

    if not isGraphConnected(adj): return -1

    # if euler circuit is present return total time
    totTime = sum([i for _,_,i in roads])
    if eulerCircuitExists(adj): return totTime

    # Generating shortest distance between all pairs
    dist = shortestDistance(n, roads)

    # Finding all nodes having odd degree
    oddDegNodes = []
    for i,nList in enumerate(adj):
        if len(nList)%2: oddDegNodes.append(i)

    # getting lowest possible extra time needed for
    # joining odd degree nodes to make them even
    minExtraTime = findMinTime(oddDegNodes, dist)

    return totTime + minExtraTime