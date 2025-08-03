#include <iostream>
#include <vector>
using namespace std;

int main() {
    int C, R, K;
    cin >> C >> R >> K;

    // 좌석 수보다 큰 경우는 예외 처리를 해주어야 함!
    if (K > R * C) {
        cout << 0 << endl;
        return 0;
    }

    // 방향 벡터: 아래 → 오른쪽 → 위 → 왼쪽 (반시계 방향)
    int dx[4] = { 0, 1, 0, -1 }; 
    int dy[4] = { 1, 0, -1, 0 }; 

    vector<vector<int>> theater(R, vector<int>(C, 0));

    int x = 0, y = 0, dir = 0;  
    for (int i = 1; i <= K; i++) {
        theater[y][x] = i;

        if (i == K) {
            cout << x + 1 << " " << y + 1 << endl;
            break;
        }

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= C || ny < 0 || ny >= R || theater[ny][nx] != 0) {
            dir = (dir + 1) % 4;
            nx = x + dx[dir];
            ny = y + dy[dir];
        }

        x = nx;
        y = ny;
    }

    return 0;
}