#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    vector<int> arr(n);
    int maxval = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        maxval = max(arr[i],maxval);
    }
    int lowidx,highidx;
    for(int i = n - 1; i >= 0; i--)
    {
        if(arr[i] == maxval)
        {
            highidx = i;
            break;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == maxval)
        {
            lowidx = i;
            break;
        }
    }
    if(highidx + lowidx == n - 1) // 제일 큰 힘을 가진 사람이 중심으로부터 양쪽에 떨어진 거리가 같음
    {
        cout << "X";
    }
    else // 아니라면
    {
        int left = lowidx; // 맨 왼쪽에서부터 최댓값 인덱스까지의 거리
        int right = n - highidx - 1; // 맨 오른쪽에서부터 최댓값 인덱스까지의 거리
        if(left > right) // 최댓값 인덱스가 멀리 떨어져 있다는 건 그만큼 승리하는 확률이 낮다는 뜻
        {
            cout << "B";
        }
        else
        {
            cout << "R";
        }
    }
    return 0;
}
