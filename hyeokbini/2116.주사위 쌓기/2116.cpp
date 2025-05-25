#include <bits/stdc++.h>

using namespace std;
int n, ans;
unordered_map<int,int> key;
vector<vector<int>> dice;

int func(int startidx)
{
    int val = 0;
    int choosedidx = startidx;
    int backidx = key[choosedidx];
    int choosedidxval = dice[0][choosedidx];
    int backidxval = dice[0][backidx];
    for(int i = 0; i < n; i++)
    {   
        if(i > 0)
        {
            for(int j = 0; j < 6; j++)
            {
                if(dice[i][j] == backidxval)
                {
                    choosedidx = j;
                    backidx = key[j];
                    choosedidxval = dice[i][choosedidx];
                    backidxval = dice[i][backidx];
                    break;
                }
            }
        }
        int curdicemaxval = 0;
        for(int j = 0; j < 6; j++)
        {
            if(j == choosedidx || j == backidx)
            {
                continue;
            }
            curdicemaxval = max(curdicemaxval,dice[i][j]);
        }
        val += curdicemaxval;
    }
    return val;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    key.insert({0,5});
    key.insert({1,3});
    key.insert({2,4});
    key.insert({3,1});
    key.insert({4,2});
    key.insert({5,0});
    cin >> n;
    dice.resize(n,vector<int>(6));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            cin >> dice[i][j];
        }
    }
    for(int i = 0; i < 6; i++)
    {
        ans = max(func(i),ans);
    }
    cout << ans;
    return 0;
}
