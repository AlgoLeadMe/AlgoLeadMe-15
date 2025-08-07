#include <bits/stdc++.h>

using namespace std;

int main() {
 // freopen("input.txt", "rt", stdin);  
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    int a, b; cin >> a >> b;
    int m; cin >> m;

    a--; b--;

    vector<vector<bool>> v(n, vector<bool> (n, false));
    while(m--) {
      int x, y; cin >> x >> y;
      x--; y--;

      v[x][y] = true;
      v[y][x] = true;
    }

    int res = -1;

    vector<bool> visited(n, false);
    visited[a] = true;
    queue<pair<int, int>> q;
    q.push({a, 0});
    while(!q.empty()) {
      auto tp = q.front();
      q.pop();
    
      int temp = tp.first;
      for(int i = 0; i < n; i++) {
        if(v[temp][i] && !visited[i]) {
          if(i == b) {
            res = tp.second + 1;
            break;
          }
          else {
            visited[i] = true;
              q.push({i, tp.second + 1});
          }
        }
      }
    }

    cout << res;

    return 0;
}
