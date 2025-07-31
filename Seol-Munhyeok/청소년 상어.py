# ↑, ↖, ←, ↙, ↓, ↘, →, ↗ (0~7)
dy = [-1, -1, 0, 1, 1, 1, 0, -1]
dx = [0, -1, -1, -1, 0, 1, 1, 1]
fish_index = [0 for _ in range(17)]  # 물고기의 현재 좌표
died = [False for _ in range(17)]  # 물고기가 상어에게 먹혔는지 여부
temp = [list(map(int, input().split())) for _ in range(4)]
fish = [[0 for _ in range(4)] for _ in range(4)]
dir = [[0 for _ in range(4)] for _ in range(4)]
SHARK = -1

# 이거까지 현재 1시간 30분 사용

# 물고기와 방향을 각 배열에 저장
for i in range(4):
    for j in range(8):
        if j % 2 == 0:
            fish[i][j//2] = temp[i][j]
            fish_index[temp[i][j]] = (i, j//2)
        else:
            dir[i][j//2] = temp[i][j] - 1

# 상어가 (y, x)에서 dist 만큼 이동
def move_shark(y, x, dist):
    pass

def swap_fish(num1, num2, y, x, ny, nx):
    fish[y][x], fish[ny][nx] = fish[ny][nx], fish[y][x]
    dir[y][x], dir[ny][nx] = dir[ny][nx], dir[y][x]
    fish_index[num1], fish_index[num2] = fish_index[num2], fish_index[num1]

def is_valid(y, x):
    return 0 <= y < 4 and 0 <= x < 4 and fish[y][x] != SHARK

# 1번부터 차례대로 물고기 이동
def move_fish():
    for f in range(1, 17):
        if not died[f]:
            y, x = fish_index[f]
            cur_dir = dir[y][x]
            for i in range(8):
                final_dir = (cur_dir + i) % 8
                ny, nx = y + dy[final_dir], x + dx[final_dir]
                if is_valid(ny, nx):
                    dir[y][x] = final_dir  # 현재 물고기 방향 바꾸기
                    swap_fish(f, fish[ny][nx], y, x, ny, nx)
                    break

# main
died[fish[0][0]] = True
fish[0][0] = SHARK
move_fish()

for i in range(4):
    for j in range(4):
        print(fish[i][j], end=' ')
    print()
print()
for i in range(4):
    for j in range(4):
        print(dir[i][j]+1, end=' ')
    print()
print()
print(fish_index)


