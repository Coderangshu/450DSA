from collections import deque

# Using Kahn's Topological sorting algorithm

class Solution:
    def isCyclic(self, V, adj):
        indegree = [0]*V
        for neighbours in adj:
            for n in neighbours:
                indegree[n] += 1
        q = deque()
        for i,v in enumerate(indegree):
            if v==0: q.append(i)
        count = 0
        while q:
            node = q.popleft()
            count += 1
            for i in adj[node]:
                indegree[i] -= 1
                if indegree[i]==0: q.append(i)
        # if count returned from toposort != # of nodes their is cycle
        return True if count!=V else False