#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<char>> arr;

void func(int curlength, int curxstart, int curystart)
{
    // 기저 조건(curlength가 1)
    if (curlength == 1)
    {
        // 현재 칸을 별로 색칠
        arr[curxstart][curystart] = '*';
        return;
    }

    // 현재 길이를 3등분해서 기준으로 삼을 값
    int newlength = curlength / 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // 중간 부분은 별을 찍지 않음
            if (i == 1 && j == 1)
            {
                continue;
            }
            func(newlength, curxstart + newlength * i, curystart + newlength * j);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    cin >> n;
    arr.resize(n, vector<char>(n,' '));
    func(n, 0, 0); // 인자는 현재 사각형 길이, 좌상단 시작점 좌표
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << arr[i][j];
        }
        cout << "\n";
    }
    return 0;
}
