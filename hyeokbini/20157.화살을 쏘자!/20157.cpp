#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    unordered_map<double, int> gradient1; // 1사분면으로 쏘기
    unordered_map<double, int> gradient2; // 2사분면으로 쏘기
    unordered_map<double, int> gradient3; // 3사분면으로 쏘기
    unordered_map<double, int> gradient4; // 4사분면으로 쏘기
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        double x, y;
        cin >> x >> y;
        double grad = y / x;
        if (x >= 0 && y > 0) // 1사분면
        {
            if (gradient1.find(grad) == gradient1.end())
            {
                gradient1.insert({grad,1});
            }
            else
            {
                gradient1[grad]++;
            }
            ans = max(ans,gradient1[grad]);
        }
        else if (x > 0 && y <= 0) // 2
        {
            if (gradient2.find(grad) == gradient2.end())
            {
                gradient2.insert({grad,1});
            }
            else
            {
                gradient2[grad]++;
            }
            ans = max(ans,gradient2[grad]);
        }
        else if (x <= 0 && y < 0) // 3
        {
            if (gradient3.find(grad) == gradient3.end())
            {
                gradient3.insert({grad,1});
            }
            else
            {
                gradient3[grad]++;
            }
            ans = max(ans,gradient3[grad]);
        }
        else // 4
        {
            if (gradient4.find(grad) == gradient4.end())
            {
                gradient4.insert({grad,1});
            }
            else
            {
                gradient4[grad]++;
            }
            ans = max(ans,gradient4[grad]);
        }
    }
    cout << ans;
    return 0;
}
