class Solution:    
    # generates all bit sets of size n with r bits set
    # ex: allPossibleStates(3,4) -> [0111, 1011, 1101, 1110] -> [7, 11, 13, 14]
    def allPossibleStates(self, r: int, n: int) -> list[int]:
        bitSet = []
        def recursion(binaryNumber: int,beginningSetBitPosition: int,noOfBitsToSet: int):
            if beginningSetBitPosition>n: return
            if noOfBitsToSet==0: bitSet.append(binaryNumber)
            else:
                for i in range(beginningSetBitPosition,n):
                    # flip ith bit
                    binaryNumber ^= (1<<i)
                    recursion(binaryNumber,i+1,noOfBitsToSet-1)
                    # flip ith bit
                    binaryNumber ^= (1<<i)
            return
        recursion(0,0,r)
        return bitSet

    # populate the memo table with the min distances upto ith node with state s in memo[i][s]
    def solve(self, adjMat: list[list[int]],memo: list[list[int]],src: int,n: int):
        # we begin from 3 visited node state as
        # for all ith node to src we have the minimum cost
        # we need to visit all nodes thus upto n+1
        for visNodeCount in range(3,n+1):
            for state in self.allPossibleStates(visNodeCount,n):
                # if src is set in current state then proceed
                if state&(1<<src)!=0:
                    # try all nodes from current state as next node
                    for next in range(n):
                        # if next is not src and next is present 
                        # in current state then proceed
                        if next!=src and state&(1<<next)!=0:
                            # remove next from current state and store in
                            # state without next
                            stateWONext = state^(1<<next)
                            minDist = float("inf")
                            # get minDist while standing at node e
                            # with the current state without next,
                            # and cost from node e to next and get min
                            # of their sum this will be the next node from e
                            for e in range(n):
                                if e!=src and e!=next and stateWONext&(1<<e)!=0:
                                    minDist = min(minDist,memo[e][stateWONext]+adjMat[e][next])
                            # store in memo for standing on node next with state as state the minDist
                            memo[next][state] = minDist

    def findMinCost(self, adjMat: list[list[int]],memo: list[list[int]],src: int,n: int) -> int:
        allNodeVisitedState = (1<<n)-1
        minTourCost = float("inf")
        for node in range(n):
            if node!=src:
                # getting cost of visiting all nodes and currently 
                # standing at node plus current node to source cost
                # and updating to get the minimum round cost
                minTourCost = min(memo[node][allNodeVisitedState]+adjMat[node][src],minTourCost)
        return minTourCost

    def findOptimalTour(self, adjMat: list[list[int]],memo: list[list[int]],src: int,n: int) -> list[int]:
        lastNode = src
        lastState = (1<<n)-1
        tour = [0]*(n+1)

        for i in range(n-1,0,-1):
            minCost, index = float("inf"), -1
            for j in range(n):
                if j!=src and lastState&(1<<j)!=0:
                    # get cost with current state and standing at j
                    # plus cost from j to lastNode visited
                    cost = memo[j][lastState]+adjMat[j][lastNode]
                    if cost<minCost:
                        minCost = cost
                        index = j
            tour[i] = index
            lastState ^= (1<<index)
            lastNode = index
        tour[0] = tour[n] = src
        return tour

    def tsp(self, adjMat: list[list[int]], src: int) -> int:
        n = len(adjMat)
        memo = [[float("inf")]*(1<<n) for i in range(n)]
        for i in range(n):
            if i!=src:
                # standing at node i with src and i already
                # visited in path, the optimal value is cost
                # from src to i
                memo[i][1<<src|1<<i] = adjMat[src][i]
        self.solve(adjMat,memo,src,n)
        minCost = self.findMinCost(adjMat,memo,src,n)
        tour = self.findOptimalTour(adjMat,memo,src,n)
        return (minCost,tour)
    

obj = Solution()
adjMat = [[0, 10, 15, 20],
          [10, 0, 25, 25],
          [15, 25, 0, 30],
          [20, 25, 30, 0]]
minCost,tour = obj.tsp(adjMat,0)
print("Minimum cost is: ",minCost,"\nThe smallest cost tour is : ",tour)