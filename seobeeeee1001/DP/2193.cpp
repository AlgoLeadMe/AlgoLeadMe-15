#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll d[100][2];

int main(){
    int n;
    cin>>n;
    d[1][0] = 0; // 맨 뒷자리 0
    d[1][1] = 1LL; // 맨 뒷자리 1
    for(int i=2;i<=n;i++){
        d[i][0] = d[i-1][0] + d[i-1][1]; // 맨 뒷자리 0은 두 가지 케이스 개수를 합친 것
        d[i][1] = d[i-1][0]; // 맨 뒷자리 1은 맨 뒷자리 0인 케이스의 개수만
    }
    ll res = d[n][0] + d[n][1];
    cout<<res;
}