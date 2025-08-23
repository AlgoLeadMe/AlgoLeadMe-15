def solution(alp, cop, problems):
    INF = int(1e9)
    maxA = max(p[0] for p in problems)
    maxC = max(p[1] for p in problems)
    
    # 초기의 알고력(코딩력) 자체가 alp_max(cop_max)보다 높은 경우에 대한 예외처리
    alp, cop = min(alp, maxA), min(cop, maxC)
    
    # dp[a][c] : 알고력 a, 코딩력 c를 얻는데 걸린 시간
    dp = [[INF for _ in range(maxC + 1)] for _ in range(maxA + 1)]
    dp[alp][cop] = 0  # 초기값 설정
    
    # DP
    for a in range(alp, maxA + 1):
        for c in range(cop, maxC + 1): 
            # 공부하는 경우
            ta, tc = min(maxA, a+1), min(maxC, c+1)
            dp[ta][c] = min(dp[ta][c], dp[a][c] + 1)
            dp[a][tc] = min(dp[a][tc], dp[a][c] + 1)
            
            # 문제 풀이하는 경우
            for alp_req, cop_req, alp_rwd, cop_rwd, cost in problems:
                if a >= alp_req and c >= cop_req:
                    na, nc = min(maxA, a + alp_rwd), min(maxC, c + cop_rwd)
                    dp[na][nc] = min(dp[na][nc], dp[a][c] + cost)
    
    return dp[maxA][maxC]