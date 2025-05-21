#include <bits/stdc++.h>
using namespace std;

int n,m;

int d[1000005][2];
int a[1000005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    d[1][0] = 0;
    d[1][1] = 0;
    d[2][0] = 1;
    d[2][1] = 1;
    d[3][0] = 1;
    d[3][1] = 1;
    for(int i=4;i<=n;i++){
        d[i][0] = d[i-1][0] + 1;
        d[i][1] = i-1;
        if(i%2==0 && d[i][0] > d[i/2][0] + 1) {
            d[i][0] = d[i/2][0] +1;
            d[i][1] = i/2;
        }
        if(i%3==0 && d[i][0] > d[i/3][0] + 1){
            d[i][0] = d[i/3][0] +1;
            d[i][1] = i/3;
        }
    }
    int cnt = d[n][0];
    cout<<cnt<<"\n";
    cout<<n<<" ";
    int idx = n;
    for(int i=0;i<cnt;i++){
        cout<<d[idx][1]<<" ";
        idx = d[idx][1];
    }
    
    
}