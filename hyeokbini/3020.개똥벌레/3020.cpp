#include <bits/stdc++.h>

using namespace std;

// 종유석
vector<int> top;
// 석순
vector<int> bottom;
int n, h;
int best = INT_MAX;
int way = 0;

// 인자로 주는 curheight는 0 based로
void func(int curheight)
{
    int val = 0;
    int needbottom = curheight + 1;
    int needtop = h - curheight;

    // 석순 계산
    int start = 0;
    int end = (n / 2) - 1;
    int stand = n / 2; // 기본값
    while(start <= end)
    {
        int mid = (start + end) / 2;
        if(bottom[mid] >= needbottom)
        {
            stand = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    val += (n / 2) - stand;
    // 종유석 계산
    start = 0;
    end = (n / 2) - 1;
    stand = n / 2;
    while(start <= end)
    {
        int mid = (start + end) / 2;
        if(top[mid] >= needtop)
        {
            stand = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    val += (n/2) - stand;

    // 갱신
    if(best > val)
    {
        best = val;
        way = 1;
    }
    else if(best == val)
    {
        way++;
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    cin >> n >> h;
    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        if(i % 2 == 0)
        {
            bottom.push_back(val);
        }
        else
        {
            top.push_back(val);
        }
    }
    sort(bottom.begin(),bottom.end());
    sort(top.begin(),top.end());
    for(int i = 0; i < h; i++)
    {
        func(i);
    }
    cout << best << " " << way;
    return 0;
}
