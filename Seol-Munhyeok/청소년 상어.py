# 참고한 코드 : https://developer-ellen.tistory.com/68
import copy

board = [[-1 for _ in range(4)] for _ in range(4)]

# ↑, ↖, ←, ↙, ↓, ↘, →, ↗ (0~7)
dy = [-1, -1, 0, 1, 1, 1, 0, -1]
dx = [0, -1, -1, -1, 0, 1, 1, 1]

# 입력 처리
for i in range(4):
    data = list(map(int, input().split()))
    fish = []
    for j in range(4):
        # 물고기 번호, 방향(0-index)
        fish.append([data[2*j], data[2*j+1]-1])
    board[i] = fish

max_score = 0

def in_range(y, x):
    return 0 <= y < 4 and 0 <= x < 4

def dfs(sy, sx, score, board):
    # (sy, sx)가 상어의 위치
    global max_score
    score += board[sy][sx][0]
    max_score = max(max_score, score)
    board[sy][sx][0] = 0  # 빈칸은 0으로 표현

    # 물고기 움직임
    for f in range(1, 17):
        fy, fx = -1, -1
        for y in range(4):
            for x in range(4):
                if board[y][x][0] == f:
                    fy, fx = y, x   # 교환할 물고기의 좌표 저장
                    break
        # 물고기가 없음
        if fy == -1 and fx == -1:
            continue
        f_dir = board[fy][fx][1]

        for i in range(8):
            nd = (f_dir + i) % 8
            ny, nx = fy + dy[nd], fx + dx[nd]
            # 범위 밖이거나, 상어가 있는 위치인 경우
            if not in_range(ny, nx) or (ny == sy and nx == sx):
                continue
            board[fy][fx][1] = nd
            board[fy][fx], board[ny][nx] = board[ny][nx], board[fy][fx]
            break
    
    # 상어 먹음
    s_dir = board[sy][sx][1]
    for i in range(1, 5):
        ny, nx = sy + dy[s_dir] * i, sx + dx[s_dir] * i
        # 범위 안에 있고 물고기가 있는 위치일 때
        if in_range(ny, nx) and board[ny][nx][0] > 0:
            dfs(ny, nx, score, copy.deepcopy(board))  # board의 복사본을 넘겨야 함

dfs(0, 0, 0, board)
print(max_score)