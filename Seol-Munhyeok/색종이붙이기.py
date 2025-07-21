paper = [list(map(int, input().split())) for _ in range(10)]  # 입력 받기
count = [0 for _ in range(6)]  # count[i] = k는 크기가 i인 색종이가 k개 사용됨을 의미
INF = int(1e9)
N = 10
answer = INF

# (y, x)에 size 크기의 색종이를 붙일 수 있는 지 판단하는 함수
def check(y, x, size):
    # 색종이가 종이를 벗어나는 경우
    if y + size > N or x + size > N:
        return False
    # 0이 적힌 칸에는 색종이가 있는 경우
    for i in range(y, y + size):
        for j in range(x, x + size):
            if paper[i][j] == 0:
                return False
    return True


# (y, x)에 size 크기의 정사각형을 value로 채움
# value = 1 → 색종이 떼기, value = 0 → 색종이 붙이기
def draw(y, x, size, value):
    for i in range(y, y + size):
        for j in range(x, x + size):
            paper[i][j] = value


def dfs(y, x, cnt):
    global answer
    # 사용한 색종이 수가 answer보다 더 크면 return
    if cnt >= answer:
        return
    # x좌표 탐색이 끝나면 왼쪽 하단으로 한 칸 이동
    if x == N:
        dfs(y + 1, 0, cnt)
        return
    # 모든 좌표의 탐색이 끝난 경우
    if y == N:
        answer = min(answer, cnt)  # 최솟값을 갱신
        return
    # 색종이를 붙일 수 없는 경우
    if paper[y][x] == 0:
        dfs(y, x + 1, cnt)
        return
    
    # 큰 색종이부터 붙이기 시작
    for size in range(5, 0, -1):
        # 해당 size의 색종이를 다 사용하면 중단
        if count[size] == 5:
            continue
        # 해당 좌표에 색종이를 붙일 수 있으면
        if check(y, x, size):
            count[size] += 1
            draw(y, x, size, 0)  # 그 좌표에 색종이를 붙이고
            dfs(y, x + size, cnt + 1)  # 그 다음 좌표를 체크
            draw(y, x, size, 1)  # 탐색을 마치면 다시 색종이 떼기
            count[size] -= 1

dfs(0, 0, 0)
print(-1 if answer == INF else answer)