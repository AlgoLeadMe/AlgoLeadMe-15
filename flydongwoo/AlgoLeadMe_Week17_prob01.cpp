#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[101];   
bool visited[101];        
int count_infected = 0;  

void dfs(int node) {
    visited[node] = true;
    for (int next : graph[node]) {
        if (!visited[next]) {
            count_infected++;
            dfs(next);
        }
    }
}

int main() {
    int n, m; 
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);

    cout << count_infected << endl;

    return 0;
}