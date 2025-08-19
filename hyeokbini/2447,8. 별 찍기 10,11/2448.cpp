#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<char>> arr;

void drawdot(int x, int y)
{
    // 인자로 받은 x,y 값은 삼각형 위쪽 꼭짓점
    arr[x][y] = '*';
    arr[x + 1][y - 1] = '*';
    arr[x + 1][y + 1] = '*';
    arr[x + 2][y - 2] = '*';
    arr[x + 2][y - 1] = '*';
    arr[x + 2][y] = '*';
    arr[x + 2][y + 1] = '*';
    arr[x + 2][y + 2] = '*';
    return;
}

void func(int curheight, int curx, int cury)
{
    // 사각형 높이가 3이 된다면 기저조건
    if (curheight == 3)
    {
        drawdot(curx, cury);
        return;
    }
    int newheight = curheight / 2;
    func(newheight, curx, cury); // 삼각형 위쪽 중앙
    func(newheight, curx + newheight, cury + newheight); // 삼각형 오른쪽 아래
    func(newheight, curx + newheight, cury - newheight); // 삼각형 왼쪽 아래
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    cin >> n;
    arr.resize(n, vector<char>(2 * n - 1, ' '));
    func(n, 0, n - 1); // 인자는 현재 전체 사각형 높이, 삼각형의 맨 위 꼭짓점 위치
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n * 2 - 1; j++)
        {
            cout << arr[i][j];
        }
        cout << "\n";
    }
    return 0;
}
