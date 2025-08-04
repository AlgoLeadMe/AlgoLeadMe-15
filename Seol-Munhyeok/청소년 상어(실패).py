import sys, copy
sys.setrecursionlimit(100000)

# ↑, ↖, ←, ↙, ↓, ↘, →, ↗ (0~7)
dy = [-1, -1, 0, 1, 1, 1, 0, -1]
dx = [0, -1, -1, -1, 0, 1, 1, 1]

fish_index = [(-1, -1)] * 17  # 1~16번 물고기의 좌표
died = [False] * 17
visited = [[False]*4 for _ in range(4)]
max_total = 0

# 이거까지 현재 2시간 30분 사용

# 입력 처리
temp = [list(map(int, input().split())) for _ in range(4)]
fish = [[0]*4 for _ in range(4)]
dir = [[0]*4 for _ in range(4)]

# 물고기와 방향을 각각 배열에 저장
for i in range(4):
    for j in range(4):
        fish_num = temp[i][j*2]
        fish_dir = temp[i][j*2+1] - 1  # 방향은 0-index
        fish[i][j] = fish_num
        dir[i][j] = fish_dir
        fish_index[fish_num] = (i, j)

def in_range(y, x):
    return 0 <= y < 4 and 0 <= x < 4
    

def dfs(fish, dir, fish_index, died, y, x, total):
    global max_total
    print("------")
    for i in range(4):
        for j in range(4):
            print(fish[i][j], end=' ')
        print()
    print("------")
    for i in range(4):
        for j in range(4):
            print(dir[i][j], end=' ')
        print()

    #print(y, x, total, max_total)
    eaten = fish[y][x]
    shark_dir = dir[y][x]
    total += eaten
    max_total = max(max_total, total)
    died[eaten] = True

    fish[y][x] = -1  # 상어 위치
    dir[y][x] = -1
    
    # 물고기 이동
    for num in range(1, 17):
        if died[num]:
            continue

        y, x = fish_index[num]
        cur_dir = dir[y][x]
        for i in range(8):
            nd = (cur_dir + i) % 8
            ny, nx = y + dy[nd], x + dx[nd]
            if not in_range(ny, nx):
                continue
            if fish[ny][nx] == -1:  # 상어가 있는 곳
                continue
            
            # 물고기 위치 바꾸기
            target_num = fish[ny][nx]
            fish[y][x], fish[ny][nx] = fish[ny][nx], fish[y][x]
            dir[y][x], dir[ny][nx] = dir[ny][nx], nd
            fish_index[num] = (ny, nx)
            if target_num != 0:
                fish_index[target_num] = (y, x)

    print("---move fish---")
    for i in range(4):
        for j in range(4):
            print(fish[i][j], end=' ')
        print()
    print("---move fish---")
    for i in range(4):
        for j in range(4):
            print(dir[i][j], end=' ')
        print()

    # 상어 이동 dfs 수행
    moved = False
    for dist in range(1, 4):
        ny, nx = y + dy[shark_dir] * dist, x + dx[shark_dir] * dist
        if not in_range(ny, nx):
            break
        if fish[ny][nx] == 0:
            continue  # 빈 칸은 건너뜀

        fish[y][x] = 0  # 상어가 있었던 위치는 빈칸으로

        # 복사본을 인자로 넘김
        dfs(copy.deepcopy(fish), copy.deepcopy(dir), fish_index[:], died[:], ny, nx, total)
        moved = True
    
    if not moved:
        max_total = max(max_total, total)
        print("final", y, x, total, max_total)
        return
  
# main
dfs(fish, dir, fish_index, died, 0, 0, 0)
print(max_total)
