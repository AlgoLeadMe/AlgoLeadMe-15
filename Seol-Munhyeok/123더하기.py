dp = [0] * 20
dp[1], dp[2], dp[3] = 1, 2, 4
for i in range(4, 20):
    dp[i] = dp[i-3] + dp[i-2] + dp[i-1]
t = int(input())
for _ in range(t):
    n = int(input())
    print(dp[n])