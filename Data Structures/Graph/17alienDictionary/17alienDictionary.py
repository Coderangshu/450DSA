from collections import deque

class Solution:
    def findOrder(self,alien_dict, N, K):
        adj = [[] for i in range(K)]
        inDegree = [0 for i in range(K)]
        for i in range(N-1):
            w1,w2 = alien_dict[i],alien_dict[i+1]
            j = 0
            while(j<len(w1) and j<len(w2)):
                if w1[j]!=w2[j]:
                    w1i,w2i = ord(w1[j])-ord('a'),ord(w2[j])-ord('a')
                    adj[w1i].append(w2i)
                    inDegree[w2i] += 1
                    break
                j += 1
        q = deque(i for i in range(K) if inDegree[i]==0)
        ans = ""
        while q:
            node = q.popleft()
            ans += chr(node+ord('a'))
            for nxt in adj[node]:
                inDegree[nxt] -= 1
                if inDegree[nxt]==0: q.append(nxt)
        return ans