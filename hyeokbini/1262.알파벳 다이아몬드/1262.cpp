#include <bits/stdc++.h>

using namespace std;

int n;

char calculate(int i,int j)
{
    int localcenter = n - 1;
    int distance = abs(i - localcenter) + abs(j - localcenter);
    if(distance >= n)
    {
        return '.';
    }
    else
    {
        return 'a' + (distance % 26);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int r1,c1,r2,c2;
    cin >> n >> r1 >> c1 >> r2 >> c2;
    int stand = n * 2 - 1;
    for(int i = r1; i <= r2; i++)
    {
        for(int j = c1; j <= c2; j++)
        {
            int tempi = i % stand;
            int tempj = j % stand;

            cout << calculate(tempi,tempj);
        }
        cout << "\n";
    }

    return 0;
}