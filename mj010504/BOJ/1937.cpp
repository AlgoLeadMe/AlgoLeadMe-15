#include <bits/stdc++.h>

using namespace std;

struct p {
    int x, y, value, cnt;
};

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int res = 0;
int n;
vector<vector<int>> v(500, vector<int> (500));
vector<vector<int>> cv(500, vector<int> (500, -1)); // 시작점일 때 가능한 최대 방문 수

int movePanda(int x, int y, int value) {
    bool canMove = false;
      for(int d = 0; d < 4; d++) {
            int xx = x + dx[d];
            int yy = y + dy[d];

            if(xx >= 0 && xx < n && yy >=0 && yy < n && v[xx][yy] > value) {
                canMove = true;
                if(cv[xx][yy] == -1) {
                    cv[x][y] = max(cv[x][y], 1 + movePanda(xx, yy, v[xx][yy], cv));
                }
                else {
                    cv[x][y] = max(cv[x][y], 1 + cv[xx][yy]);
                }
            }
      }

      if(!canMove) {
        cv[x][y] = 1;
        return 1;
      }
      else return cv[x][y];

 }
    


int main() {
  // freopen("input.txt", "rt", stdin);  
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cin >> v[i][j];
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(cv[i][j] == -1) movePanda(i, j, v[i][j], cv);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            res = max(res, cv[i][j]);
        }
    }


    cout << res;

    return 0;
}

