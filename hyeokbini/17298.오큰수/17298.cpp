#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    stack<int> S;
    // 배열 반복문을 돌면서
    // 1. S가 비어있다면 현재 인덱스 push
    // 2. S가 비어있지 않다면 S.top()의 인덱스 배열값과 현재 인덱스 배열값 비교
    // 2.1.1 arr[S.top()] < arr[i]인 동안 ans[S.top] = arr[i], S.pop()
    // 2.1.2 위 과정이 모두 끝났다면, 현재 인덱스 S.push()
    // 2.2 arr[S.top()] >= arr[i] 라면 현재 인덱스 S.push()
    // 3. 배열의 끝까지 왔다면 !S.empty() 동안 S.pop()하면서 -1로 채우기
    for (int i = 0; i < n; i++)
    {
        if (S.empty())
        {
            S.push(i);
        }
        else
        {
            if (arr[S.top()] < arr[i])
            {
                while(!S.empty() && arr[S.top()] < arr[i])
                {
                    ans[S.top()] = arr[i];
                    S.pop();
                }
                S.push(i);
            }
            else
            {
                S.push(i);
            }
        }
    }
    while (!S.empty())
    {
        ans[S.top()] = -1;
        S.pop();
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
