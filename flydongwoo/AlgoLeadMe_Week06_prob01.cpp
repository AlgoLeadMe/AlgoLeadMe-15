#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

const int MAX = 1001;
bool visited[MAX]; 
vector<pair<int, int>> graph[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // 간선 정보 입력
    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        graph[u].emplace_back(cost, v);
        graph[v].emplace_back(cost, u);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, 1); 
    int total_cost = 0;

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();

        if (visited[u]) {
            continue;
        }

        visited[u] = true;
        total_cost += cost;

        for (auto [next_cost, v] : graph[u]) {
            if (!visited[v]) {
                pq.emplace(next_cost, v);
            }
        }
    }

    cout << total_cost << '\n';
    return 0;
}