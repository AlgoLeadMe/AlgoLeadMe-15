#include <bits/stdc++.h>
using namespace std;

int mem[104];
int c[104];

vector<vector<int>> d;

int main(){
    int n,m;
    cin>>n>>m;
    d.resize(n+1, vector<int>(m, 101));
    for(int i=0;i<n;i++){
        cin>>mem[i];
    }
    for(int i=0;i<n;i++){
        cin>>c[i];
    }

    for(int i=0;i<n;i++){
        for(int j=1;j<=m;j++){
            if(i-1>=0){
                if(j-mem[i]<=0) d[i][j] = min(c[i],d[i-1][j]);
                else d[i][j] = min(d[i-1][j],d[i-1][j-mem[i]]);
                cout<<i<<" "<<j<<"\n";
            }
            else{
                if(j-mem[i]<=0) d[i][j] = c[i];
                else continue;
                cout<<i<<" "<<j<<"\n";
            }
        }
    }

    cout<<d[n-1][m];
}