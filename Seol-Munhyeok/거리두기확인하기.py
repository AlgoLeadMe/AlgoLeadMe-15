def solution(places):
    answer = []
    
    dy, dx = [-1, 0, 1, 0], [0, 1, 0, -1]
    
    def in_range(y, x):
        return 0 <= y < 5 and 0 <= x < 5
    
    def check(place, y, x):
            visited[y][x] = True 
            for i in range(4):
                ny, nx = y + dy[i], x + dx[i]
                if in_range(ny, nx) and place[ny][nx] != 'X' and not visited[ny][nx]:
                    if place[ny][nx] == 'P':
                        return False
                    visited[ny][nx] = True
                    for j in range(4):
                        nny, nnx = ny + dy[j], nx + dx[j]
                        if in_range(nny, nnx) and place[nny][nnx] != 'X' and not visited[nny][nnx]:
                            if place[nny][nnx] == 'P':
                                return False
            return True
    
    
    for place in places:
        visited = [[False for _ in range(5)] for _ in range(5)]
        ok = True
        for i in range(5):
            for j in range(5):
                if place[i][j] == 'P':
                    if not check(place, i, j):
                        ok = False
                        break
            if not ok:
                break
        if ok:
            answer.append(1)
        else:
            answer.append(0)
                    
    return answer