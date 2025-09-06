from collections import defaultdict, deque
import sys

input = sys.stdin.readline
N, M = map(int, input().split())
graph = defaultdict(list)
for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

visited = [False] * (N+1)
queue = deque()
queue.append(1)
visited[1] = True
answer = 1

while queue:
    size = len(queue)
    answer *= (size + 1)
    for _ in range(size):
        cur = queue.popleft()
        for neighbor in graph[cur]:
            if not visited[neighbor]:
                queue.append(neighbor)
                visited[neighbor] = True

print((answer - 1) % 1_000_000_007)