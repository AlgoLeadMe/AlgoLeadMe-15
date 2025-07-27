def solution(n, s, a, b, fares):
    answer = 0
    INF = int(1e9)

    # 인접행렬 초기화
    graph = [[INF for _ in range(n+1)] for _ in range(n+1)]
    
    # 자기 자신으로 가는 경로의 가중치는 0
    for i in range(1, n+1):
        graph[i][i] = 0
    
    # 입력 처리
    for fare in fares:
        x, y, z = fare
        graph[x][y] = z
        graph[y][x] = z
    
    # 최단 경로 찾기
    for k in range(1, n+1):
        for i in range(1, n+1):
            for j in range(1, n+1):
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])
    
    # 합승하지 않았을 때의 비용 계산
    answer = graph[s][a] + graph[s][b]
    
    # 출발 지점을 제외한 나머지 지점을 경유했을 때의 비용을 비교한다.
    for i in range(1, n+1):
        if i == s:
            continue
        answer = min(answer, graph[s][i] + graph[i][a] + graph[i][b])
    
    return answer