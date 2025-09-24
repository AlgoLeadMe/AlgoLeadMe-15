def solution(r, c, d, grid):
    dirs = [(-1, 0), (0, 1), (1, 0), (0, -1)]

    y, x, cur_dir = r, c, d
    cleaned = 0

    while True:
        # 현재 칸 청소
        if grid[y][x] == 0:
            grid[y][x] = 2
            cleaned += 1
        
        moved = False

        # 왼쪽부터 4방향 검사
        for _ in range(4):
            left = (cur_dir + 3) % 4
            dy, dx = dirs[left]
            ny, nx = y + dy, x + dx

            if grid[ny][nx] == 0:
                # 왼쪽이 미청소면 회전 + 전진
                cur_dir = left
                y, x = ny, nx
                moved = True
                break
            else:
                # 왼쪽이 아니면
                cur_dir = left
        
        if moved:
            continue

        # 4 방향 모두 불가 -> 뒤로 한 칸 (방향은 유지)
        back = (cur_dir + 2) % 4
        dy, dx = dirs[back]
        ny, nx = y + dy, x + dx

        # 뒤가 벽이면 종료
        if grid[ny][nx] == 1:
            return cleaned
        
        # 뒤로 이동 (바라보는 방향 cur는 그대로 유지)
        y, x = ny, nx
        

# 입력 처리
n, m = map(int, input().split())
r, c, d = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]

print(solution(r, c, d, grid))
