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

def bfs(a, b):
    queue = deque()
    queue.append(a)
    level = 0
    while queue:
        size = len(queue)
        for _ in range(size):
            cur = queue.popleft()
            visited[cur] = True
            if cur == b:
                return level
            for neighbor in graph[cur]:
                if not visited[neighbor]:
                    queue.append(neighbor)
        level += 1
    
    return -1

print(bfs(a, b))