#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n, m, x, y, k;
    cin >> n >> m >> x >> y >> k;
    int top = 0, bottom = 0, east = 0, west = 0, south = 0, north = 0;
    vector<vector<int>> arr(n, vector<int>(m,0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < k; i++)
    {
        int command;
        cin >> command;
        if (command == 1)
        {
            if (y + 1 >= m)
            {
                continue;
            }
            y++;
            int tmp = east;
            east = top;
            top = west;
            west = bottom;
            bottom = tmp;
        }
        else if (command == 2)
        {
            if (y - 1 < 0)
            {
                continue;
            }
            y--;
            int tmp = east;
            east = bottom;
            bottom = west;
            west = top;
            top = tmp;
        }
        else if (command == 3)
        {
            if (x - 1 < 0)
            {
                continue;
            }
            x--;
            int tmp = south;
            south = bottom;
            bottom = north;
            north = top;
            top = tmp;
        }
        else
        {
            if (x + 1 >= n)
            {
                continue;
            }
            x++;
            int tmp = south;
            south = top;
            top = north;
            north = bottom;
            bottom = tmp;
        }
        if (arr[x][y] == 0)
        {
            arr[x][y] = bottom;
        }
        else
        {
            bottom = arr[x][y];
            arr[x][y] = 0;
        }
        cout << top << "\n";
    }
    return 0;
}