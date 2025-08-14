from collections import defaultdict, deque

n = int(input())
a, b = map(int, input().split())
m = int(input())
graph = defaultdict(list)
visited = [False] * (n+1)
for _ in range(m):
    x, y = map(int, input().split())
    graph[x].append(y)
    graph[y].append(x)

answer = -1
def dfs(cur, depth):
    global answer
    visited[cur] = True
    if cur == b:
        answer = depth
        return
    
    for neighbor in graph[cur]:
        if not visited[neighbor]:
            dfs(neighbor, depth + 1)
    return

dfs(a, 0)
print(answer)