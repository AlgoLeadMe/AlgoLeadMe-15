#include <bits/stdc++.h>
using namespace std;

int d[1004];
int n;

int main(){
    cin>>n;
    d[1] = 1;
    d[2] = 3;
    for(int i=3;i<=n;i++){
        d[i] = d[i-2] * 2 + d[i-1];
    }
    for(int i=3;i<=n;i++){
        cout<<d[i]<<" ";
    }
} 