n = int(input())
m = int(input())
lst = list(map(int, input().split())) if m > 0 else []
cand = [i for i in range(10) if i not in lst]  # 사용 가능한 숫자 버튼
length = len(str(n))

answer = int(1e9)

def brute(arr, r, depth, value):
    global n, answer
    if depth == r:
        answer = min(answer, r + abs(n - value))
        return
    for num in arr:
        brute(arr, r, depth + 1, value * 10 + num)

def solve(num):
    global answer
    # 기본값: 숫자 버튼 안 쓰고 +/-
    answer = abs(num - 100)

    # [1] 채널이 100인 경우
    if num == 100:
        return 0

    # [2] 100 근처 채널 예외 처리
    if num == 101 or num == 99:
        return 1
    if num == 102 or num == 98:
        return 2
    if num == 103:
        return 3
    
    # [3] 모두 고장
    if m == 10:
        return answer
    
    # [4] 아무것도 안 고장
    if m == 0:
        return len(str(num))
    
    # [5] 모든 자릿수마다 경우의 수 체크
    for r in range(1, length + 2):
        brute(cand, r, 0, 0)

    return answer

print(solve(n))