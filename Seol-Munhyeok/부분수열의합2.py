from bisect import bisect_left, bisect_right

# arr의 모든 조합에 대한 합계를 저장
def get_sub_sums(arr):
    result = []
    n = len(arr)
    def dfs(idx, total):
        if idx == n:
            result.append(total)
            return
        dfs(idx + 1, total)  # 현재 원소 선택 안 함
        dfs(idx + 1, total + arr[idx])  # 현재 원소 선택 함

    dfs(0, 0)
    return result

# 입력 처리
n, s = map(int, input().split())
arr = list(map(int, input().split()))

# 수열을 반으로 나눔
mid = n // 2
left = arr[:mid]
right = arr[mid:]

# 부분합 구하기
left_sums = get_sub_sums(left)
right_sums = get_sub_sums(right)

# 이분탐색을 위해 오른쪽 부분합 정렬
right_sums.sort()

# 정답 찾기
answer = 0
for x in left_sums:
    target = s - x
    l = bisect_left(right_sums, target)
    r = bisect_right(right_sums, target)
    answer += (r - l)

# 공집합 제외
if s == 0:
    answer -= 1

print(answer)