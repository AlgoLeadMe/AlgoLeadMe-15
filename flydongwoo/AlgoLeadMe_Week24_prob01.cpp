#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <tuple>

using namespace std;

int N, M;
vector<string> board;
bool visited[1001][1001][2];

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int bfs() {
    queue<tuple<int, int, int, bool>> q;

    q.push({ 0, 0, 1, false });
    visited[0][0][0] = true;

    while (!q.empty()) {
        auto [r, c, dist, broken] = q.front();
        q.pop();

        if (r == N - 1 && c == M - 1) {
            return dist;
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < N && nc >= 0 && nc < M) {
                if (board[nr][nc] == '0' && !visited[nr][nc][broken]) {
                    visited[nr][nc][broken] = true;
                    q.push({ nr, nc, dist + 1, broken });
                }
                else if (board[nr][nc] == '1' && !broken) {
                    visited[nr][nc][1] = true;
                    q.push({ nr, nc, dist + 1, true });
                }
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    board.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    cout << bfs() << endl;

    return 0;
}