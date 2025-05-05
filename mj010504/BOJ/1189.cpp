#include <bits/stdc++.h>

using namespace std;

int res = 0;
int r,c,k;

char v[5][5];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void dfs(int x, int y, int cnt) {
    if(cnt >= k) return;

    for(int d = 0; d < 4; d++) {
        int xx = x + dx[d];
        int yy = y + dy[d];

        if(xx >= 0 && xx < r && yy >= 0 && yy < c && v[xx][yy] == '.') {
            if(xx == 0 && yy == c - 1 && (cnt + 1) == k) res++;
            else {
                v[xx][yy] = 'T';
                dfs(xx, yy, cnt + 1);
                v[xx][yy] = '.';
            }
        }
    }
}

int main() {
   freopen("input.txt", "rt", stdin);  
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

   cin >> r >> c >> k;

   for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
        cin >> v[i][j];
    }
   }

   v[r-1][0] = 'T';

   dfs(r - 1,0,1);

   cout << res;

    return 0;
}

