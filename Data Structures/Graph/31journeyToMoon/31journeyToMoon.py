from collections import defaultdict

def journeyToMoon(n, astronaut):
    parent,rank = [i for i in range(n)], [1 for _ in range(n)]
    def find(i):
        if(parent[i]==i): 
            return i
        else:
            parent[i] = find(parent[i])
            return parent[i]
    def union(a,b):
        pa,pb = find(a),find(b)
        if pa!=pb:
            if rank[pa]>rank[pb]:
                parent[pb] = pa
            elif rank[pb]>rank[pa]:
                parent[pa] = pb
            else:
                parent[pb] = pa
                rank[pa] += 1
    # each pair joins both nodes to same component
    for [a,b] in astronaut:
        union(a,b)
    for i in range(n):
        find(i)
    # taking all possible choices as ans
    ans = n*(n-1)/2
    d = defaultdict(int)
    for i in parent: d[i] += 1
    # for each component the number of nodes present
    # in it cannot form pair with other node of the same component
    # thus removes these possible pairs from the answer
    for k in d:
        ans -= d[k]*(d[k]-1)/2
    return int(ans)