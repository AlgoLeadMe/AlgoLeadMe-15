#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
int ans = 0;
int s;

void func(int curval, int curidx)
{
    if(curidx == arr.size())
    {
        if(curval == s)
        {
            ans++;
        }
        return;
    }
    func(curval,curidx + 1);
    func(curval + arr[curidx],curidx + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n >> s;
    arr.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    func(0,0);
    if(s == 0)
    {
        ans--; // 구하는 수가 0일 때는 아무것도 선택하지 않는 경우의 수(공집합)가 포함되므로 ans--
    }
    cout << ans;
    return 0;
}
