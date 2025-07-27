#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
int ans = 0;
int s;

void func(int curval, int curidx)
{
    for(int i = curidx; i < arr.size(); i++)
    {
        if(curval + arr[i] == s)
        {
            ans++;
        }
        func(curval + arr[i], i + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("test.txt", "rt", stdin);
    int n;
    cin >> n >> s;
    arr.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    func(0,0);
    cout << ans;
    return 0;
}
