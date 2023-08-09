# There are 3 possible states from current state:
# (I)    Fill either of the jug completely
# (II)   Empty either of the jugs
# (III)  Fill either of them using the other until the other is completely
#        empty or until the one being filled is full

from collections import deque


def ninjaAndVessels(m, n, w):
    # Write your code here.
    q, ans, vis = deque(), 0, set()
    q.append((0,0))
    vis.add((0,0))
    while q:
        sz = len(q)
        for i in range(sz):
            a,b = q.popleft()
            # if any of the 2 buckets have w return steps
            if a==w or b==w: return ans

            actions = []
            # empty either one
            actions.append((0,b))
            actions.append((a,0))

            # fill either one
            actions.append((m,b))
            actions.append((a,n))

            # fill one from other
            toFilla = min(m-a,b)
            actions.append((a+toFilla,b-toFilla))
            toFillb = min(n-b,a)
            actions.append((a-toFillb,b+toFillb))
            
            for action in actions:
                if not action in vis:
                    vis.add(action)
                    q.append(action)
        ans += 1
    return -1