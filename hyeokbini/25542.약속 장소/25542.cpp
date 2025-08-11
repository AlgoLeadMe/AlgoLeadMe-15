#include <bits/stdc++.h>
using namespace std;

bool isValid(string s, vector<string> arr)
{
    for (auto t : arr)
    {
        int diff = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != t[i])
            {
                diff++;
            }
        }
        if (diff > 1)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("test.txt", "rt", stdin);
    int n, m;
    cin >> n >> m;
    vector<string> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < m; ++i)
    {
        for (char c = 'A'; c <= 'Z'; c++)
        {
            string tmp = arr[0];
            tmp[i] = c;
            if (isValid(tmp, arr))
            {
                cout << tmp;
                return 0;
            }
        }
    }

    cout << "CALL FRIEND";
    return 0;
}
