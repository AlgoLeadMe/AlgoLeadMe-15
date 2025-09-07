#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int R, C, T;
vector<vector<int>> room;
int purifier_top_r = -1;
int purifier_bottom_r = -1;

int dr[] = { 0, 1, 0, -1 };
int dc[] = { 1, 0, -1, 0 };

void spread_dust() {
    vector<vector<int>> diffused_dust(R, vector<int>(C, 0));

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (room[r][c] > 0) {
                int spread_amount = room[r][c] / 5;
                int spread_count = 0;

                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if (nr >= 0 && nr < R && nc >= 0 && nc < C && room[nr][nc] != -1) {
                        diffused_dust[nr][nc] += spread_amount;
                        spread_count++;
                    }
                }
                room[r][c] -= spread_amount * spread_count;
            }
        }
    }

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            room[r][c] += diffused_dust[r][c];
        }
    }
}

void circulate_air() {
    for (int r = purifier_top_r - 1; r > 0; r--) {
        room[r][0] = room[r - 1][0];
    }
    for (int c = 0; c < C - 1; c++) {
        room[0][c] = room[0][c + 1];
    }
    for (int r = 0; r < purifier_top_r; r++) {
        room[r][C - 1] = room[r + 1][C - 1];
    }
    for (int c = C - 1; c > 1; c--) {
        room[purifier_top_r][c] = room[purifier_top_r][c - 1];
    }
    room[purifier_top_r][1] = 0;

    for (int r = purifier_bottom_r + 1; r < R - 1; r++) {
        room[r][0] = room[r + 1][0];
    }
    for (int c = 0; c < C - 1; c++) {
        room[R - 1][c] = room[R - 1][c + 1];
    }
    for (int r = R - 1; r > purifier_bottom_r; r--) {
        room[r][C - 1] = room[r - 1][C - 1];
    }
    for (int c = C - 1; c > 1; c--) {
        room[purifier_bottom_r][c] = room[purifier_bottom_r][c - 1];
    }
    room[purifier_bottom_r][1] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C >> T;
    room.resize(R, vector<int>(C));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> room[i][j];
            if (room[i][j] == -1) {
                if (purifier_top_r == -1) {
                    purifier_top_r = i;
                    purifier_bottom_r = i + 1;
                }
            }
        }
    }

    while (T--) {
        spread_dust();
        circulate_air();
    }

    int total_dust = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (room[i][j] > 0) {
                total_dust += room[i][j];
            }
        }
    }

    cout << total_dust << endl;

    return 0;
}