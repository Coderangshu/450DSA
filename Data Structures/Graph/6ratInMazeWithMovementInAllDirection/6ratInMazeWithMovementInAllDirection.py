class Solution:
    def findPath(self, m, n):
        # lexicographically D L R U
        ans,dir,dl = [],[[1,0],[0,-1],[0,1],[-1,0]],['D','L','R','U']
        def dfs(node,path):
            i,j = node
            if m[i][j]!=1: return
            if i==n-1 and j==n-1:
                ans.append(path)
                return
            m[i][j] = 2
            for d in range(4):
                ni,nj = i+dir[d][0],j+dir[d][1]
                if ni>=0 and ni<n and nj>=0 and nj<n and m[ni][nj]!=2:
                    path += dl[d]
                    dfs((ni,nj),path)
                    path = path[:len(path)-1]
            m[i][j] = 1
            return
        dfs((0,0),"")
        return ans