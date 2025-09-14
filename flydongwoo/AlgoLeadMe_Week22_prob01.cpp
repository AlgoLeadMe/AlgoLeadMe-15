#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> board;
int r_robot, c_robot, d_robot;

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

int cleaned_count = 0;

void solve() {
    while (true) {
        if (board[r_robot][c_robot] == 0) {
            board[r_robot][c_robot] = 2;
            cleaned_count++;
        }

        bool has_uncleaned_neighbor = false;
        for (int i = 0; i < 4; i++) {
            int next_d = (d_robot + 3 - i) % 4;
            int nr = r_robot + dr[next_d];
            int nc = c_robot + dc[next_d];

            if (nr >= 0 && nr < N && nc >= 0 && nc < M) {
                if (board[nr][nc] == 0) {
                    has_uncleaned_neighbor = true;
                    break;
                }
            }
        }

        if (has_uncleaned_neighbor) {
            d_robot = (d_robot + 3) % 4;

            int nr = r_robot + dr[d_robot];
            int nc = c_robot + dc[d_robot];

            if (nr >= 0 && nr < N && nc >= 0 && nc < M) {
                if (board[nr][nc] == 0) {
                    r_robot = nr;
                    c_robot = nc;
                }
            }
        }
        else {
            int back_d = (d_robot + 2) % 4;
            int nr = r_robot + dr[back_d];
            int nc = c_robot + dc[back_d];

            if (nr < 0 || nr >= N || nc < 0 || nc < M || board[nr][nc] == 1) {
                break;
            }
            else {
                r_robot = nr;
                c_robot = nc;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    cin >> r_robot >> c_robot >> d_robot;

    board.resize(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    solve();

    cout << cleaned_count << endl;

    return 0;
}