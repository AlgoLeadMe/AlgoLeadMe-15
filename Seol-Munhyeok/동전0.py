n, k = map(int, input().split())
coins = [int(input()) for _ in range(n)]
answer = 0

# 가장 큰 가치의 동전부터 탐색
for i in range(n-1, -1, -1):
    if k == 0:
        break
    coin = coins[i]
    answer += k // coin
    k %= coin

print(answer)
