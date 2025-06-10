#include <bits/stdc++.h>

using namespace std;


int main() {
   // freopen("input.txt", "rt", stdin);  
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s,t; cin >> s >> t;

    int res = 0;
    queue<string> q;
    q.push(t);

    while(!q.empty()) {
        auto str = q.front();
        q.pop();

        if(str == s) {
            res = 1;
            break;
        }

        if(str.size() <= s.size()) continue;
        
        string temp;
        if(str[str.size() - 1] == 'A') {
            temp = str.substr(0, str.size() - 1);
        }

        if(str[str.size() - 1] == 'B') {
            temp = str.substr(0, str.size() - 1);
            reverse(temp.begin(), temp.end());
        }

        q.push(temp);
      
    }

    cout << res;


    return 0;
}

