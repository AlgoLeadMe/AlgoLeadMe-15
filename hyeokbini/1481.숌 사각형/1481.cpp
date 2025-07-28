#include <bits/stdc++.h>
using namespace std;

int n,d;
vector<vector<int>> arr;

bool check(int x, int y, int val) // 수정 필요
{
    // 각 행 / 열에 사용된 숫자의 사용 여부(0 ~ d-1)
    vector<bool> rowinserted(d,false);
    vector<bool> colinserted(d,false);
    // 이미 사용된 숫자 체크
    for(int i = 0; i < n; i++)
    {
        if(arr[x][i] != -1)
        {
            rowinserted[arr[x][i]] = true;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(arr[i][y] != -1)
        {
            colinserted[arr[i][y]] = true;
        }
    }
    // 이번에 넣으려는 값도 미리 반영
    rowinserted[val] = true;
    colinserted[val] = true;
    // 아직 안 나온 숫자 개수 계산
    int missingrow = 0, missingcol = 0;
    for(int i = 0; i < d; i++)
    {
        if(!rowinserted[i])
        {
            ++missingrow;
        }
        if(!colinserted[i])
        {
            ++missingcol;
        }
    }
    // 남은 칸 개수 계산
    int rowremain = n - (y + 1);
    int colremain = n - (x + 1);

    // 아직 한번도 나오지 않은 숫자의 개수 >= 남은 빈칸 수라면 채울 수 있음, true를 리턴
    return (rowremain >= missingrow) && (colremain >= missingcol);
}

void func(int xidx, int yidx)
{
    if(xidx == n)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
    }
    if(yidx == n)
    {
        func(xidx + 1, 0);
        return;
    }
    for(int i = 0; i < d; i++)
    {
        if(check(xidx, yidx, i))
        {
            arr[xidx][yidx] = i;
            func(xidx, yidx + 1);
            arr[xidx][yidx] = -1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    cin >> n >> d;
    arr.resize(n,vector<int>(n,-1));
    func(0,0);
    return 0;
}
