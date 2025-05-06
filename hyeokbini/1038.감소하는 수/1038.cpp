#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    if (n <= 10)
    {
        cout << n;
    }
    else
    {
        int count = 10;
        int val = 10;
        // 1. 가장 낮은 자릿수부터 올릴 수 있는 수가 있는지 검사
        // 1.1 있으면 올리고, count++
        // 1.2 없으면
        // 1.2.1 맨 앞자리수가 9인지 검사하고, 맞다면 자릿수 +1, count++
        // 1.2.2 맨 앞자리수가 9가 아니라면 맨 앞자리수 +1, count++
        string tmp = to_string(val);
        bool flag;
        while (1)
        {
            if(tmp == "9876543210")
            {
                cout << -1;
                return 0;
            }
            flag = false;
            for (int i = tmp.length() - 1; i > 0; i--)
            {
                if (tmp[i] - '0' + 1 < tmp[i - 1] - '0')
                {
                    tmp[i] = (tmp[i] - '0' + 1) + '0';
                    string head = tmp.substr(0,i + 1);
                    for(int j = tmp.length() - (i + 2); j >= 0; j--)
                    {
                        head += j + '0';
                    }
                    tmp = head;
                    count++;
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                if (count == n)
                {
                    cout << tmp;
                    return 0;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                if (tmp[0] - '0' == 9)
                {
                    int tmplen = tmp.length();
                    tmp = "";
                    for (int i = tmplen; i >= 0; i--)
                    {
                        tmp += i + '0';
                    }
                }
                else
                {
                    char firsttmpval = (tmp[0] - '0' + 1) + '0';
                    int tmplen = tmp.length();
                    tmp = "";
                    tmp += firsttmpval;
                    for(int i = tmplen - 2; i >= 0; i--)
                    {
                        tmp += i + '0';
                    }
                }
                count++;
                if (count == n)
                {
                    cout << tmp;
                    return 0;
                }
            }
        }
    }
    return 0;
}
