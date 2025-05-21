#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
   // freopen("input.txt", "rt", stdin);  
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--) {
        int m, n, k; cin >> m >> n >> k;

        int res = 0;
        vector<vector<int>> v(n, vector<int> (m, 0));

        for(int i = 0; i < k; i++) {
            int x, y; cin >> y >> x;
            v[x][y] = 1;
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(v[i][j] == 1) {
                    res++;
                    v[i][j] = 0;
                    queue<pair<int, int>> q;
                    q.push({i,j});
                    while(!q.empty()) {
                        auto tp = q.front();
                        q.pop();

                        for(int d = 0; d < 4; d++) {
                            int xx = tp.first + dx[d];
                            int yy = tp.second + dy[d];

                            if(xx >= 0 && xx < n && yy >=0 && yy < m && v[xx][yy] == 1) {
                                v[xx][yy] = 0;
                                q.push({xx, yy});
                            }
                        }
                    }

                }
            }
        }

        cout << res << '\n';

    }

    return 0;
}

