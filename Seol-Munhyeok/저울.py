INF = int(1e9)
n = int(input())
m = int(input())

# 인접 행렬 초기화 (자기 자신은 가중치 0)
graph = [[INF for _ in range(n+1)]  for _ in range(n+1)]
for i in range(1, n+1):
    graph[i][i] = 0

# 입력 처리 (가중치 1)   
for _ in range(m):
    a, b = map(int, input().split())
    graph[a][b] = 1

# 최단거리 구하기
for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])

# 물건 i와 비교 결과를 알 수 없는 물건의 개수를 출력
for i in range(1, n+1):
    answer = 0
    for j in range(1, n+1):
        if graph[i][j] == INF and graph[j][i] == INF:
            answer += 1
    print(answer)
