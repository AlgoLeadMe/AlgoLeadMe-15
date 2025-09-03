#include <bits/stdc++.h>
using namespace std;

int row, col;
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
vector<int> v;
vector<vector<bool>> visited;

void func(vector<vector<int>>& land, int x, int y)
{
    queue<pair<int, int>> Q;
    
    Q.push({x, y});
    visited[x][y] = true;
    
    int cnt = 0;
    int ymin = y, ymax = y;

    while(!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        cnt++;

        // YMIN, YMAX 계산
        if(cur.second < ymin) ymin = cur.second;
        if(cur.second > ymax) ymax = cur.second;

        for(int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || ny < 0 || nx >= col || ny >= row) continue;
            if(land[nx][ny] == 0 || visited[nx][ny]) continue;

            visited[nx][ny] = true;
            Q.push({nx, ny});
        }
    }

    // YMIN과 YMAX 내에서 크기 누적
    for(int i = ymin; i <= ymax; i++)
    {
        v[i] += cnt;
    }
}

int solution(vector<vector<int>> land) {
    int ans = 0;
    row = land[0].size();
    col = land.size();
    visited.resize(col,vector<bool>(row,false));
    v.resize(row,false);

    for(int i = 0; i < col; i++)
    {
        for(int j = 0; j < row; j++)
        {
            if(land[i][j] == 1 && visited[i][j] == false)
            {
                func(land, i, j);
            }
        }
    }

    // 최대값 계산
    for(int i = 0; i < row; i++)
    {
        ans = max(v[i], ans);
    }

    return ans;
}
