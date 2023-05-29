from collections import deque
class Solution:
    def minStepToReachTarget(self, KnightPos, TargetPos, N) -> int:
        ans = 0
        dx = [ -2, -1,  1,  2, -2, -1, 1, 2 ]
        dy = [ -1, -2, -2, -1,  1,  2, 2, 1 ]
        q = deque()
        q.append(KnightPos)
        visited = set()
        visited.add(",".join(map(str,KnightPos)))
        while q:
            sz = len(q)
            while sz:
                sz -= 1
                cur = q.popleft()
                if cur==TargetPos: return ans
                for i in range(8):
                    nx,ny = cur[0]+dx[i], cur[1]+dy[i]
                    nstr = ",".join(map(str,[nx,ny]))
                    if nx>0 and nx<=N and ny>0 and ny<=N and nstr not in visited:
                        visited.add(nstr)
                        q.append([nx,ny])
            ans += 1
        return ans