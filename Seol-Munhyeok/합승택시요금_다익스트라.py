import heapq
from collections import defaultdict

INF = int(1e9)

def dijkstra(start, graph, n):
    dist = [INF for _ in range(n+1)]
    dist[start] = 0  # 시작 노드까지의 거리는 0

    # (현재까지의 거리, 현재 노드)를 저장하는 최소 힙 (우선순위 큐)
    hq = [(0, start)]

    while hq:
        # 현재까지의 거리(cost)가 가장 짧은 노드를 꺼냄
        cost, now = heapq.heappop(hq)

        # 이미 더 짧은 거리로 방문한 적이 있으면 건너뜀
        if cost > dist[now]:
            continue

        # 현재 노드와 연결된 이웃 노드들 확인
        for c, nxt in graph[now]:
            # 현재 노드를 거쳐서 nxt 노드로 가는 비용이 기존보다 더 짧으면 갱신
            if dist[nxt] > cost + c:
                dist[nxt] = cost + c  # 거리 테이블 갱신
                heapq.heappush(hq, (dist[nxt], nxt))  # 갱신된 노드를 큐에 추가
    
    return dist


def solution(n, s, a, b, fares):
    graph = defaultdict(list)
    for u, v, w in fares:
        graph[u].append((w, v))
        graph[v].append((w, u))
    
    dist_s = dijkstra(s, graph, n)
    dist_a = dijkstra(a, graph, n)
    dist_b = dijkstra(b, graph, n)

    answer = INF
    for x in range(1, n+1):
        answer = min(answer, dist_s[x] + dist_a[x] + dist_b[x])
    
    return answer