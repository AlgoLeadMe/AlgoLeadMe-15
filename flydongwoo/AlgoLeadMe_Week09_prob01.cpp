#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int N, M;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
vector<string> map;
vector<vector<int>> visited;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = 1;

    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
                continue;
            }
            if (map[nx][ny] == '0' || visited[nx][ny] != 0) {
                continue;
            }

            visited[nx][ny] = visited[curX][curY] + 1;
            q.push({ nx, ny });
        }
    }
}

int main() {
    cin >> N >> M;
    map.resize(N);
    visited.assign(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++) {
        cin >> map[i];
    }

    bfs(0, 0);

    cout << visited[N - 1][M - 1] << endl;
    return 0;
}