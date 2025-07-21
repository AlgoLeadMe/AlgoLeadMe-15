#include <iostream>
#include <vector>
using namespace std;

const int dx[4] = { -1, 1, 0, 0 }; 
const int dy[4] = { 0, 0, -1, 1 }; 

int T, M, N, K;
vector<vector<int>> field;
vector<vector<bool>> visited;

void dfs(int x, int y) {
    visited[y][x] = true;

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
            if (field[ny][nx] == 1 && !visited[ny][nx]) {
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    while (T--) {
        cin >> M >> N >> K;

        field = vector<vector<int>>(N, vector<int>(M, 0));
        visited = vector<vector<bool>>(N, vector<bool>(M, false));

        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            field[y][x] = 1;
        }

        int count = 0;

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (field[y][x] == 1 && !visited[y][x]) {
                    dfs(x, y);
                    count++;
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}
