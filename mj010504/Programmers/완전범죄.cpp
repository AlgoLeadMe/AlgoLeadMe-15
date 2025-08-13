#include<bits/stdc++.h>

using namespace std;


int res = INT_MAX;
int aa, bb;

set<tuple<int, int, int>> check;

void steal(vector<vector<int>> v, int a, int b, int i) {
    if(a >= res) return;

    if (check.count(make_tuple(a, b, i))) return;
    check.insert(make_tuple(a, b, i));

    if(i == v.size()) {
        res = min(res, a);
        return;
    }

    if(a + v[i][0] < aa) {
         steal(v, a + v[i][0], b, i + 1);
    }   

    if(b + v[i][1] < bb) {
        steal(v, a, b + v[i][1], i + 1);
    } 
}

int solution(vector<vector<int>> v, int n, int m) {
     aa = n; bb = m;
    steal(v, 0, 0, 0);

    if(res == INT_MAX) res = -1;

    return res;
}
