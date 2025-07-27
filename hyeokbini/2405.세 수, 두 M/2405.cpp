#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    int ans = 0;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    for(int i = 1; i < n - 1; i++)
    {
        int firval = abs(arr[i] * 2 - (arr[i - 1] + arr[n - 1]));
        int secval = abs(arr[i] * 2 - (arr[0] + arr[i + 1]));
        ans = max({ans,firval,secval});
    }
    cout << ans;
    return 0;
}
