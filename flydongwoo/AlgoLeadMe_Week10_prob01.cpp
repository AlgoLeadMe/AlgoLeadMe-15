#include <iostream>    
#include <vector>      
using namespace std;

const int MAX = 100 + 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int graph[MAX][MAX] = { 0 };

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
    }

    // 플로이드-워셜 알고리즘
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (graph[i][k] && graph[k][j])
                    graph[i][j] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                continue;
            }
            if (graph[i][j] == 0 && graph[j][i] == 0) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
