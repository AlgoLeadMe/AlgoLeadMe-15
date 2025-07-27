#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    
    string ans;
    cin >> n;
    stack<tuple<string,string,int>> S;
    for(int i = 0; i < n; i++)
    {
        string tmp1,tmp2;
        int tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        S.push({tmp1,tmp2,tmp3});
    }
    while(!S.empty())
    {
        if(get<0>(S.top()) == "type")
        {
            ans += get<1>(S.top());
            S.pop();
        }
        else
        {
            int stand = get<2>(S.top()) - stoi(get<1>(S.top()));
            while(!S.empty() && get<2>(S.top()) >= stand)
            {
                S.pop();
            }
        }
    }
    reverse(ans.begin(),ans.end());
    cout << ans;
    return 0;
}
