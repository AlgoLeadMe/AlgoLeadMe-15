#include <bits/stdc++.h>

using namespace std;

int ans = 0;

void func(vector<vector<int>> arr, vector<bool> used, int depth, int curval)
{
    if(depth == arr[0].size())
    {
        ans = max(curval,ans);
        return;
    }
    for(int i = 0; i < arr.size(); i++)
    {
        if(used[i])
        {
            continue;
        }
        curval += arr[i][depth];
        used[i] = true;
        func(arr,used,depth + 1, curval);
        curval -= arr[i][depth];
        used[i] = false;
    }
}

int solution(vector<vector<int>> ability) {
    vector<bool> used(ability.size(),false);
    func(ability,used, 0,0);
    return ans;
}