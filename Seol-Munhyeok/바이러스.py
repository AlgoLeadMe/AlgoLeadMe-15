from collections import defaultdict
a = int(input())
b = int(input())
graph = defaultdict(list)
visited = [False] * (a+1)

# 인접 리스트 생성
for _ in range(b):
    x, y = map(int, input().split())
    graph[x].append(y)
    graph[y].append(x)

# DFS 수행
answer = 0
def dfs(node):
    global answer
    visited[node] = True

    for _next in graph[node]:
        if not visited[_next]:
            answer += 1
            dfs(_next)

# DFS 함수 호출 횟수가 구하는 값임
dfs(1)
print(answer)