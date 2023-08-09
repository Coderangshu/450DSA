# Algorithm : check if x is in y's subtree or vice versa
# according to given direction

def populateInOutTime(parent,node,adj,timer,inTime,outTime):
    inTime[node] = timer
    timer += 1
    for nxt in adj[node]:
        if nxt!=parent:
            timer = populateInOutTime(node,nxt,adj,timer+1,inTime,outTime)
    timer += 1
    outTime[node] = timer
    return timer

def isInSubTree(x,y,inTime,outTime):
    return inTime[x]<inTime[y] and outTime[y]<outTime[x]

n = int(input())
adj = [[] for _ in range(n+1)]
for _ in range(n-1):
    edge = list(map(int,input().split(" ")))
    adj[edge[0]].append(edge[1])
    adj[edge[1]].append(edge[0])
inTime,outTime,timer = [0]*(n+1),[0]*(n+1),0
populateInOutTime(0,1,adj,timer,inTime,outTime)
queries = int(input())
for query in range(queries):
    direction,x,y = list(map(int,input().split(" ")))
    # going up
    if direction==0:
        # y should be in subtree of x
        if isInSubTree(x,y,inTime,outTime):
            print("YES")
        else: print("NO")
    else:
        # x should be in subtree of y
        if isInSubTree(y,x,inTime,outTime):
            print("YES")
        else: print("NO")

