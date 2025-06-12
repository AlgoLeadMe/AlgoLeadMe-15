#include <bits/stdc++.h>
using namespace std;

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    long long cross = (long long)(b.first - a.first) * (c.second - a.second) -
                      (long long)(b.second - a.second) * (c.first - a.first);
    if (cross > 0)
        return 1;
    else if (cross < 0)
        return -1;
    else
        return 0;
}


void sortPointsByAngle(vector<pair<int, int>> &pts)
{
    double cx = 0, cy = 0;
    for (auto &p : pts)
    {
        cx += p.first;
        cy += p.second;
    }
    cx /= 4.0;
    cy /= 4.0;

    sort(pts.begin(), pts.end(), [&](pair<int, int> &a, pair<int, int> &b)
         {
        double angleA = atan2(a.second - cy, a.first - cx);
        double angleB = atan2(b.second - cy, b.first - cx);
        return angleA < angleB; });
}

bool isConvexQuad(vector<pair<int, int>> &pts)
{
    int n = 4;
    int sign = 0;
    for (int i = 0; i < n; i++)
    {
        int c = ccw(pts[i], pts[(i + 1) % n], pts[(i + 2) % n]);
        if (c == 0)
            return false; // 일직선이면 안됨
        if (sign == 0)
            sign = c;
        else if (sign != c)
            return false; // 부호 다르면 볼록 아님
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int N;
    cin >> N;
    vector<pair<int, int>> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i].first >> arr[i].second;

    int ans = 0;
    for (int i = 0; i < N - 3; i++)
    {
        for (int j = i + 1; j < N - 2; j++)
        {
            for (int k = j + 1; k < N - 1; k++)
            {
                for (int l = k + 1; l < N; l++)
                {
                    vector<pair<int, int>> quad = {arr[i], arr[j], arr[k], arr[l]};
                    sortPointsByAngle(quad);
                    if (isConvexQuad(quad))
                        ans++;
                }
            }
        }
    }

    cout << ans;
    return 0;
}
