dp = [[0 for _ in range(1001)] for _ in range(1001)]

# 테이블 초기화
for i in range(1, 1001):
    dp[1][i] = 1

dp[2][1] = 1
for i in range(2, 1001):
    dp[2][i] = 2

dp[3][1], dp[3][2] = 1, 3
for i in range(3, 1001):
    dp[3][i] = 4

# 점화식
for i in range(4, 1001):
    for j in range(2, 1001):
        dp[i][j] = (dp[i-1][j-1] + dp[i-2][j-1] + dp[i-3][j-1]) % 1_000_000_009

# 출력
t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    print(dp[n][m])