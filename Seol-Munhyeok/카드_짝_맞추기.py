from collections import deque
from collections import defaultdict
from itertools import permutations

bfs_cache = dict()
# 어떤 좌표 (y, x)에서, 목표 좌표 (ey, ex)까지 최소 키 입력 횟수 구하기
def bfs(sy, sx, ey, ex, board):
    key = (sy, sx, ey, ex, tuple(tuple(row) for row in board))
    if key in bfs_cache:
        return bfs_cache[key]
    
    # 출발지와 도착지 위치가 같으면 이동 횟수는 0
    if (sy, sx) == (ey, ex):
        return 0
    
    dy, dx = [-1, 0, 1, 0], [0, 1, 0, -1]
    visited = [[False for _ in range(4)] for _ in range(4)]
    queue = deque()
    queue.append((sy, sx, 0))
    visited[sy][sx] = True

    while queue:
        y, x, dist = queue.popleft()
        # 도착 지점 도달
        if (y, x) == (ey, ex):
            bfs_cache[key] = dist
            return dist

        for d in range(4):
            # 한 칸 이동
            ny, nx = y + dy[d], x + dx[d]
            if 0 <= ny < 4 and 0 <= nx < 4 and not visited[ny][nx]:
                visited[ny][nx] = True
                queue.append((ny, nx, dist + 1))
            # Ctrl 이동
            cy, cx = y, x
            while True:
                ny, nx = cy + dy[d], cx + dx[d]
                if not (0 <= ny < 4 and 0 <= nx < 4):
                    break
                cy, cx = ny, nx
                if board[cy][cx] != 0:
                    break
            if not visited[cy][cx]:
                visited[cy][cx] = True
                queue.append((cy, cx, dist + 1))
                
                
# 두 좌표에 있는 같은 카드 2장을 제거하고 새로운 보드 상태 반환하기
def remove_cards(board, pos1, pos2):
    new_board = [row[:] for row in board]
    y1, x1 = pos1
    y2, x2 = pos2
    new_board[y1][x1] = 0
    new_board[y2][x2] = 0
    return new_board


# 현재 보드에 존재하는 숫자별 카드 위치를 모두 수집해서 딕셔너리로 반환
def get_coords(board):
    coords = defaultdict(list)
    for i in range(4):
        for j in range(4):
            num = board[i][j]
            if num != 0:
                coords[num].append((i, j))
    return coords
 
    
# 카드 짝 제거 순서를 모든 순열로 시도하며 최솟값 탐색
def dfs(board, r, c, remaining_cards, memo):
    if not remaining_cards:
        return 0
    
    key = (r, c, tuple(tuple(row) for row in board), tuple(remaining_cards))
    if key in memo:
        return memo[key]
    
    min_move = int(1e9)
    coords = get_coords(board)
    
    for i, num in enumerate(remaining_cards):
        pos1, pos2 = coords[num]
        
        # 순서 1: pos1 → pos2
        move1 = bfs(r, c, pos1[0], pos1[1], board)
        move2 = bfs(pos1[0], pos1[1], pos2[0], pos2[1], board)
        total1 = move1 + move2 + 2  # Enter 2번 포함
        new_board1 = remove_cards(board, pos1, pos2)
        next_cards = remaining_cards[:i] + remaining_cards[i+1:]
        min_move = min(min_move, total1 + dfs(new_board1, pos2[0], pos2[1], next_cards, memo))
        
        # 순서 2: pos2 → pos1
        move1 = bfs(r, c, pos2[0], pos2[1], board)
        move2 = bfs(pos2[0], pos2[1], pos1[0], pos1[1], board)
        total2 = move1 + move2 + 2  # Enter 2번 포함
        new_board2 = remove_cards(board, pos2, pos1)
        next_cards = remaining_cards[:i] + remaining_cards[i+1:]
        min_move = min(min_move, total2 + dfs(new_board2, pos1[0], pos1[1], next_cards, memo))
        
    memo[key] = min_move
    return min_move
        
    
def solution(board, r, c):
    coords = get_coords(board)
    card_types = list(coords.keys())
    min_total = int(1e9)

    for order in permutations(card_types):
        memo = dict()
        min_total = min(min_total, dfs(board, r, c, list(order), memo))

    return min_total
