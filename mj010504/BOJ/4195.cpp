#include <bits/stdc++.h>
using namespace std;

vector<int> parent, networkSize;

int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

int unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) {
        parent[y] = x;
        networkSize[x] += networkSize[y];
    }

    return networkSize[x];
}

int main() {

    freopen("input.txt", "rt", stdin);  
    int t; cin >> t;

    while(t--) {
        int f; cin >> f;
        vector<pair<string, string>> pv;
        set<string> s;

        for(int i = 0; i < f; i++) {
            string a, b; cin >> a >> b;
            pv.push_back({a ,b});
            s.insert(a);
            s.insert(b);
        }

        unordered_map<string, int> m;
        int idx = 0;
        for(auto str : s) {
            m[str] = idx;
            idx++;
        }
        
        parent.clear();
        parent.resize(s.size());

        networkSize.clear();
        networkSize.resize(s.size(), 1);

        for(int i = 0; i < s.size(); i++) parent[i] = i;

        for(auto p : pv) {
            int a = m[p.first];
            int b = m[p.second];

           int res = unite(a, b);
           

            cout << res << '\n';
        }
    }


    return 0;
}
