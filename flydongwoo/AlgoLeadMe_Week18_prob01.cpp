#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 100000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<bool> visited(MAX + 1, false);
    vector<int> dist(MAX + 1, -1);

    queue<int> q;
    q.push(N);
    visited[N] = true;
    dist[N] = 0;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (x == K) {
            cout << dist[x] << endl;
            return 0;
        }

        int moves[3] = { x - 1, x + 1, x * 2 };
        for (int nx : moves) {
            if (nx >= 0 && nx <= MAX && !visited[nx]) {
                visited[nx] = true;
                dist[nx] = dist[x] + 1;
                q.push(nx);
            }
        }
    }

    return 0;
}