from collections import deque

class Solution:
    def snakesAndLadders(self, board: list[list[int]]) -> int:
        # convert 2D to 1D
        oneD,n = [],len(board)
        # always starting from bottom left to right and going up
        # thus check required in case of odd/even rows in board
        for i in range(len(board)-1,-1,-1):
            if n%2==0:
                if i%2==0:
                    for j in range(n-1,-1,-1): oneD.append(board[i][j])
                else:
                    for j in range(len(board[0])): oneD.append(board[i][j])
            else:
                if i%2!=0:
                    for j in range(n-1,-1,-1): oneD.append(board[i][j])
                else:
                    for j in range(len(board[0])): oneD.append(board[i][j])
        q = deque()
        q.append(0)
        visited = set([0])
        steps = 0
        while q:
            sz = len(q)
            for _ in range(sz):
                node = q.popleft()
                if node==n**2-1: return steps
                for i in range(1,7):
                    if node+i<n**2:
                        nextNode = node+i if oneD[node+i]==-1 else oneD[node+i]-1
                        if nextNode not in visited:
                            visited.add(nextNode)
                            q.append(nextNode)
            steps += 1
        return -1