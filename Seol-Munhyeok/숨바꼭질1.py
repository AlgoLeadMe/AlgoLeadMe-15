from collections import deque
import sys
n, k = map(int, input().split())
visited = [False] * 100004
queue = deque()

queue.append(n)
visited[n] = True
depth = 0
while queue:
    size = len(queue)
    for _ in range(size):
        cur = queue.popleft()
        if cur == k:
            print(depth)
            sys.exit()
        for _next in [cur-1, cur+1, cur*2]:
            if 0 <= _next < 100002 and not visited[_next]: 
                queue.append(_next)
                visited[_next] = True
    depth += 1